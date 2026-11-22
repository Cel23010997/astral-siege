"""Build the original C++ game using Emscripten and the independent web adapter.
Usage: python web/build.py /path/to/emsdk/upstream/emscripten/em++.py
"""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
import subprocess,sys,hashlib
root=Path(__file__).resolve().parents[1]
compiler=Path(sys.argv[1]).resolve()
cache=root/'web/.build';cache.mkdir(exist_ok=True)
(root/'docs').mkdir(exist_ok=True)
sources=[p for p in (root/'Source').glob('*.cpp') if p.name.lower()!='main.cpp']+[root/'web/main.cpp',root/'web/compat/AEEngine.cpp']
flags=['-std=c++17','-O2','-I'+str(root/'web/compat'),'-I'+str(root/'Header'),'-include',str(root/'web/compat/AEEngine.h'),'-ffile-prefix-map='+str(root)+'=.', '-Wno-nonportable-include-path','-Wno-ignored-pragmas','-Wno-extra-tokens','-Wno-implicit-const-int-float-conversion']
header_bytes=b''.join(p.read_bytes() for folder in ['Header','web/compat'] for p in sorted((root/folder).glob('*.h*')))
def compile_one(source):
 obj=cache/(source.parent.name+'_'+source.stem+'.o'); stamp=obj.with_suffix('.sha')
 digest=hashlib.sha256(source.read_bytes()+header_bytes+repr(flags).encode()).hexdigest()
 if obj.exists() and stamp.exists() and stamp.read_text()==digest: return obj,True
 p=subprocess.run([sys.executable,str(compiler),*flags,'-c',str(source),'-o',str(obj)],cwd=root,capture_output=True,text=True)
 if p.returncode: print(p.stderr,flush=True);return obj,False
 stamp.write_text(digest);print('Compiled '+source.name,flush=True);return obj,True
with ThreadPoolExecutor(max_workers=3) as pool: results=list(pool.map(compile_one,sources))
if not all(ok for _,ok in results):raise SystemExit(1)
cmd=[sys.executable,str(compiler),*[str(obj) for obj,_ in results],'-O2','-sALLOW_MEMORY_GROWTH=1','-sASSERTIONS=1','-sNO_EXIT_RUNTIME=1','-sENVIRONMENT=web','--preload-file','Assets@/Assets','--pre-js','web/runtime.js','--shell-file','web/shell.html','-o','docs/index.html']
raise SystemExit(subprocess.call(cmd,cwd=root))

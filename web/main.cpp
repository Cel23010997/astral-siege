#include "compat/AEEngine.h"
#include "../Header/Game.hpp"
#include <emscripten.h>
extern "C" EMSCRIPTEN_KEEPALIVE int astral_state(){return current;}
static void tick(){
  if(next!=current){
    fpFree();
    if(next!=GS_RESTART)fpUnload();
    previous=current;
    if(next==GS_QUIT)next=GS_MAINMENU;
    if(next==GS_RESTART){next=current;}else{current=next;GSM_Update();fpLoad();}
    fpInitialize();
  }
  AESysFrameStart();fpUpdate();fpDraw();AESysFrameEnd();
}
int main(){AESysInit(nullptr,0,1600,900,1,60,true,nullptr);GSM_Initialize(GS_SPLASHSCREEN);GSM_Update();fpLoad();fpInitialize();emscripten_set_main_loop(tick,60,true);return 0;}

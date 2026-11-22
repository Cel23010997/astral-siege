# Astral Siege

**Defend Earth in a C++ space tower-defence game where planetary gravity bends a shot.** A five-person project by The Alpha Beasts, with a later browser port for this portfolio.

[Play in your browser](https://Cel23010997.github.io/astral-siege/) · [Case study](https://Cel23010997.github.io/projects/astral-siege.html) · [My contributions](CONTRIBUTIONS.md)

**My role — Celeste Tong:** application/game-state flow, game screens, shared menus, pause/options interactions, Earth-related work and reset/resource-lifetime fixes.

## Original project

The team built a Windows C++ game using Alpha Engine. The design combines defending Earth, aiming through gravitational fields, purchasing/placing turrets and moving through menus, gameplay and result screens. It originally required the Windows game build to play and the appropriate development environment to rebuild.

## What the browser edition does

This is a port of the original game code to WebAssembly, with an independently written WebGL, input, font and browser-audio compatibility layer. It is not a video or a replacement minigame. Visitors receive the game files through the live website and do not need to install an engine or clone this repository.

- Desktop mouse controls are recommended; use the in-game Controls screen.
- Click inside the game to enable audio, as required by browsers.
- The browser edition returns to the main menu when the original game requests Quit.
- Browser rendering/audio can differ from the original Windows runtime. This is a portfolio adaptation, not a claim that every full-campaign path has been exhaustively tested.

The proprietary Alpha Engine SDK is not redistributed. The original Windows solution is retained as project context but cannot build from this checkout without its original licensed SDK and configuration.

## Source map

- `Source/`, `Header/`, `Assets/`: reviewed original game source and assets, with small C++ portability adjustments.
- `web/compat/`: independent replacement interface and implementation for browser rendering, maths, input and audio; not the Alpha Engine SDK.
- `web/runtime.js`: WebGL and browser runtime support.
- `web/main.cpp`: browser-compatible frame loop.
- `docs/`: generated static browser build, served by GitHub Pages.
- `vendor/json.hpp`: third-party JSON header with its original notice.

## Rebuild the browser version

Install the free [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html), then run:

```text
python web/build.py /path/to/emsdk/upstream/emscripten/em++.py
python -m http.server 8000 --directory docs
```

Open `http://localhost:8000`. The published site serves the same generated files. The port was built with Emscripten 7.0.1. Build objects are cached under `web/.build/` and excluded from Git.

## Team and provenance

The Alpha Beasts: **Chloe Lau, Celeste Tong Jia Xuan, Javier Lee, Choi Meng Yew and Guok Yi Yong**. Individual file credits and the original DigiPen copyright notices are preserved. No open-source license to the complete team game or its assets is implied.

This public repository starts from a privacy-reviewed final-source snapshot. It does not recreate or backdate the original team's commit history. Personal email addresses and student identifiers have been removed from public comments. The browser adapter and publication work are later portfolio adaptations made with AI assistance, separate from the original team submission.

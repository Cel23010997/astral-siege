# Celeste's Astral Siege contributions

I worked on the application and game-state flow, game screens, shared menus, pause/options interactions and Earth-related work. The game itself was a five-person collaboration; these are selected examples of my work, not a claim to sole authorship.

## Changes supported by the original commits

| Original commit | Problem and change | Code-supported outcome |
| --- | --- | --- |
| `0d12adc` | Mesh cleanup freed slots without clearing stored pointers. I added a null check and cleared each freed slot. | Repeat cleanup skips already-cleared meshes. |
| `307d0b0` | Restart left HUD interaction state behind. I added `HUD::Reset()` and called it from game reset. | Counter, click and hover state are explicitly reset. |
| `2813865` | Escape requested application exit from menus. I changed eligible menu states to return to the previous state. | Menu navigation goes back instead of quitting. |
| `f578ad4` | Added and integrated pause/options controls. | Resume, volume, gravity-arrow visibility and restart are available through the game's surrounding interfaces. |

These references come from the original local team history, preserved separately. The outcomes describe inspected code, not a measured memory-leak reduction or a formal usability study. Audio-lifecycle cleanup underwent several revisions; a commit subject saying “fixed memory leak” is not treated as proof that all leaks were eliminated.

The browser port in this repository is a later portfolio adaptation. It is documented separately from the original contributions above.

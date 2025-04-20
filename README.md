# Idle Floating Desktop Buddy (Windows Only)

![Static Badge](https://img.shields.io/badge/C%20Programming%20Language-blue?style=for-the-badge&logo=C&logoColor=white&labelColor=%236195CB&color=%2300427E) ![Static Badge](https://img.shields.io/badge/Raylib%20library-blue?style=for-the-badge&logo=raylib&logoColor=black&labelColor=white&color=%23f5f5f5)


Want a little dektop pet in the corner of your screen?<br/>
This app lets you have your pet floating on a position of your liking.<br/>

<u>Compilation:</u> `gcc main.c windows.c -o desktopBuddy.exe -lraylib -lgdi32 -lwinmm -Wl,--subsystem,windows`.<br/>
Example image from <a href='https://commons.wikimedia.org/wiki/File:Bumblebee_white_eyes_clipart.svg'>wikimedia.org</a>.

### How to use:
- Run `idleFloatingDesktopBuddy.exe`.
- <u>To use your own image:</u>
  - Place the image in this folder, and rename it `image.png` (replacing the already provided one).
  - Then open `size.h` and set the dimensions of the image. Keep in mind that the window would be a square (where the length would be the size of the larger dimension of your image). 

### Hotkeys:
- `Esc`: close window.
- `b`: toggle window border.
- `f`: toggle float (the up and down movement).
- `t`: keep the window on top. You can click through the window when this is toggled on.

### Screenshots:

<div style="display:grid;grid-template-columns: 35% 35%;justify-content:space-evenly;width:100%;">
  <img src="screenshot.png" style="border:#EEE 1px solid;width:100%" alt=""/>
  <img src="screenshot2.png" style="border:#EEE 1px solid;width:100%" alt=""/>
</div>
# Desktop Buddy (Windows Only)

![Static Badge](https://img.shields.io/badge/C%20Programming%20Language-blue?style=for-the-badge&logo=C&logoColor=white&labelColor=%236195CB&color=%2300427E) ![Static Badge](https://img.shields.io/badge/Raylib%20library-blue?style=for-the-badge&logo=raylib&logoColor=black&labelColor=white&color=%23f5f5f5)


Want a little dektop pet in the corner of your screen?<br/>
This app lets you have your pet floating on a position of your liking.<br/>

<u>Compilation:</u> `gcc main.c windows.c -o desktopBuddy.exe -lraylib -lgdi32 -lwinmm -Wl,--subsystem,windows`.<br/>
Example image from <a href='https://commons.wikimedia.org/wiki/File:Bumblebee_white_eyes_clipart.svg'>wikimedia.org</a>.

### How to use:
- Download the zip from the releases.
- Extract the files and run `desktopBuddy.exe`.
- To use your own image, place it in the same as folder as `desktopBuddy.exe`, and name it `image.png` (replacing the example image).

### Hotkeys:
- `Esc`: close window.
- `b`: toggle window border.
- `f`: toggle float (the up and down movement).
- `t`: keep the window on top. You can click through the window when this is toggled on.
- `c`: Bring the window to the center of your main monitor.
- Arrow Keys: Move your buddy up, down, left or right.
- `W`/`A`/`S`/`D`: Change width and height.

### Screenshots:

<table><tbody><tr>
  <td><img src="screenshot.png" style="border:#EEE 1px solid;width:100%" alt=""/></td>
  <td><img src="screenshot2.png" style="border:#EEE 1px solid;width:100%" alt=""/></td>
</tr></tbody></table>

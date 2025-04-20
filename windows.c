#include <windows.h>
#include <stdbool.h>

void getCursorPos(PPOINT mousePos){
  GetCursorPos(mousePos);
}

bool mouseOnTop(HWND handle, POINT mousePos){
  static RECT rect = {0, 0, 0, 0};
  GetWindowRect(handle, &rect);
  if((rect.left < mousePos.x) && (mousePos.x < rect.right) && (rect.top < mousePos.y) && (mousePos.y < rect.bottom))
    return true;
  return false;
}

void toggleOnTop(HWND handle){
  static bool onTop = true;
  if (onTop) {
    SetWindowPos(handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
    SetWindowLongPtrA(handle, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);
  }
  else {
    SetWindowPos(handle, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
    LONG_PTR exStyle = GetWindowLongPtrA(handle, GWL_EXSTYLE);
    SetWindowLongPtrA(handle, GWL_EXSTYLE, exStyle & ~WS_EX_TRANSPARENT);
  }
  onTop = !onTop;
}

void setPriorityLow(){
  SetPriorityClass(GetCurrentProcess(), IDLE_PRIORITY_CLASS);
}
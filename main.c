#include "raylib.h"
#include <math.h>

const char* FILE_LOC = "./image.png";
const char* WINDOW_TITLE = "Desktop Buddy";
const float DOUBLE_PI = 2*PI; 
const float HALF_PI = PI/2; 
const float RAD_DEG_FACTOR = 180/PI;
const float MAX_OFFSET = 5;

typedef struct {
  long x;
  long y;
} MousePos;

void getCursorPos(MousePos*);
void toggleOnTop(void*);
void setPriorityLow();
bool mouseOnTop(void*, MousePos);

static inline int squarifyImageByAddingPadding(Image *image){
  if(image->width > image->height) {
    const int offY = (image->width - image->height)/2;
    ImageResizeCanvas(image, image->width, image->width, 0, offY, WHITE);
    return image->width;
  }
  else {
    const int offX = (image->height - image->width)/2;
    ImageResizeCanvas(image, image->height, image->height, offX, 0, WHITE);
    return image->height;
  } 
}

static float getTextureRotation(const Vector2 origin, MousePos mPos) {
  Vector2 winPos = GetWindowPosition();
  const int centerX = winPos.x + origin.x;
  const int centerY = winPos.y + origin.y;
  const int difY = centerY - mPos.y;
  const int difX = mPos.x - centerX;
  float rad;
  // quadrant 1 and 4
  if (difX >= 0) rad = -atan(((float) difY)/difX);
  // quadrant 2 and 3
  else rad = PI-atan(((float) difY)/difX);
  return RAD_DEG_FACTOR * rad;
}

static inline void keyRelatedStuff(float *angleForOffset, float *verOffset){
  static bool allowFloat = true;
  static bool borderless = false;
  if(allowFloat){
    *angleForOffset += 0.1;
    if (*angleForOffset >= DOUBLE_PI) *angleForOffset = 0;
    *verOffset = sin(*angleForOffset)*MAX_OFFSET;
  }
  else *verOffset = 0;

  if(borderless) {
    if (!IsWindowState(FLAG_WINDOW_UNDECORATED)) SetWindowState(FLAG_WINDOW_UNDECORATED);
  }
  else ClearWindowState(FLAG_WINDOW_UNDECORATED);
  
  if (IsKeyPressed(KEY_B)) borderless = !(borderless);
  if (IsKeyPressed(KEY_F)) allowFloat = !(allowFloat);
  if (IsKeyPressed(KEY_T)) toggleOnTop(GetWindowHandle());

}

static inline void setDestAndOrigin(Rectangle *dest, Vector2 *origin, float *verOffset){
  float windowWidth = (float) GetScreenWidth();
  float windowHeight = (float) GetScreenHeight();
  float halfwidth = windowWidth/2.0;
  float halfHeight = windowHeight/2.0;

  if(windowWidth < windowHeight){
    *dest = (Rectangle) {halfwidth, halfHeight+(*verOffset), windowWidth, windowWidth};
    *origin = (Vector2) {halfwidth, halfwidth};
  }
  else{
    *dest = (Rectangle) {halfwidth, halfHeight+(*verOffset), windowHeight, windowHeight};
    *origin = (Vector2) {halfHeight, halfHeight};
  }

}

int main(void) {
  SetConfigFlags(FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_RESIZABLE);
  //initialize window (width and height will be reset later)
  InitWindow(500, 500, WINDOW_TITLE);
  setPriorityLow();
  SetTargetFPS(30);
  Image image = LoadImage(FILE_LOC);
  SetWindowSize(image.width, image.height);
  int length = squarifyImageByAddingPadding(&image);
  SetWindowIcon(image);
  // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
  const Texture2D texture = LoadTextureFromImage(image);
  UnloadImage(image); //image no longer needed, we gonna be using texture
  MousePos mPos = {0.0, 0.0};
  const Rectangle src = {0.0, 0.0, (float) length, (float) length}; 
  float verOffset;
  float angleForOffset = 0.0f; 
  float opacity = 1.0f;
  Rectangle dest;
  Vector2 origin;
  while (!WindowShouldClose()) {
    //^ Detect window close button or ESC key
    keyRelatedStuff(&angleForOffset, &verOffset);

    getCursorPos(&mPos);
    
    if (mouseOnTop(GetWindowHandle(), mPos)) {
      if (opacity > 0.25) opacity -= 0.05;
    }
    else if (opacity < 1) opacity += 0.05;
    SetWindowOpacity(opacity);

		BeginDrawing();
		ClearBackground(BLANK);
    setDestAndOrigin(&dest, &origin, &verOffset);
    DrawTexturePro(texture, src, dest, origin, getTextureRotation(origin, mPos), WHITE);
		EndDrawing();
  }
  UnloadTexture(texture);
  CloseWindow(); // Close window and OpenGL context
  return 0;
}
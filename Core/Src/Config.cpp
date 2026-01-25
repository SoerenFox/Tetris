#include "Config.h"

#include "windows.h"

Config::Config() : windowWidth(1008), windowHeight(1008),
targetFPS([]{ 
  HDC h = GetDC(NULL); 
  int r = GetDeviceCaps(h, VREFRESH); 
  ReleaseDC(NULL, h);
  return r ? r : 60; 
}()) {}

int Config::getWindowHeight() const {
  return windowHeight;
}

int Config::getWindowWidth() const {
  return windowWidth;
}

int Config::getTargetFPS() const {
  return targetFPS;
}
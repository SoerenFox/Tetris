#pragma once

class Config
{
  int windowWidth, windowHeight;
  int targetFPS;

  public:
    Config();
    int getWindowWidth() const;
    int getWindowHeight() const;
    int getTargetFPS() const;
};
#pragma once

#include "Config.h"
#include "GameState.h"
#include "Shape.h"

class Game {
  Config cfg;
  GameState gameState;
  Shape shape;
  
  void gameLoop();

  public:
    Game();
    void run();
};
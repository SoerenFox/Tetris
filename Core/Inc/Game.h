#pragma once

#include "Config.h"
#include "GameState.h"

class Game {
  Config cfg;
  GameState gameState;
  
  void gameLoop();

  public:
    Game();
    void run();
};
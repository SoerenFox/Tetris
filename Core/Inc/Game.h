#pragma once

#include "Config.h"
#include "GameState.h"
#include "Shape.h"

#include <vector>
#include <memory>

class Game {
  Config cfg;
  GameState gameState;
  
  bool isMoving;
  std::vector<std::unique_ptr<Shape>> shapes;
  
  void gameLoop();

  public:
    Game();
    void run();
};
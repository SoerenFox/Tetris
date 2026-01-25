#include "Game.h"

#include <raylib.h>
#include <iostream>
#include <string>

Game::Game() : gameState(GameState::PLAYING) {}

void Game::gameLoop() {
  BeginDrawing();
  ClearBackground(BLACK);

  EndDrawing();
}

void Game::run(){
  InitWindow(cfg.getWindowWidth(), cfg.getWindowHeight(), "");
  SetTargetFPS(cfg.getTargetFPS());

  while (!WindowShouldClose()) {
    if(IsKeyPressed(KEY_F11)){
      ToggleBorderlessWindowed();
    }
    switch (gameState) {
      case GameState::PLAYING:
        gameLoop();
        break;
      case GameState::QUIT:
        CloseWindow();
    }
  }
}
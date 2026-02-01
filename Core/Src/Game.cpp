#include "Game.h"

#include <raylib.h>
#include <iostream>
#include <string>

Game::Game() : gameState(GameState::PLAYING), shape(cfg) {
    srand(static_cast<unsigned int>(time(nullptr))); // random seed
}

void Game::gameLoop() {
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
}

void Game::run(){
    InitWindow(cfg.getWindowWidth(), cfg.getWindowHeight(), "");
    SetTargetFPS(cfg.getTargetFPS());

    while (!WindowShouldClose()) {
        switch (gameState) {
        case GameState::PLAYING:
            gameLoop();
            break;
        case GameState::QUIT:
            CloseWindow();
        }
    }
}
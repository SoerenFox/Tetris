#include "Game.h"

#include <raylib.h>
#include <iostream>
#include <string>

Game::Game() : gameState(GameState::PLAYING), isMoving(false) {
    shapes.push_back(std::make_unique<Shape>(cfg));
    srand(static_cast<unsigned int>(time(nullptr))); // random seed
}

void Game::gameLoop() {
    // Shape* last = shapes.back().get();
    // if (last->getVelocity() <= 0) shapes.push_back(std::make_unique<Shape>(cfg));
    // for (auto& shape : shapes) shape->update();

    BeginDrawing();
    ClearBackground(BLACK);

    // for (auto& shape : shapes) shape->draw();
    shapes.back()->draw();

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
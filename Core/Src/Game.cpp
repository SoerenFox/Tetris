#include "Game.h"

#include <raylib.h>
#include <iostream>
#include <string>

Game::Game() : gameState(GameState::PLAYING), isMoving(false) {
    srand(static_cast<unsigned int>(time(nullptr))); // random seed
}

void Game::gameLoop() {
    if (isMoving) {
        Shape* last = shapes.back().get();
        last->update();
        isMoving = (last->getVelocity() > 0);
    } else {
        shapes.push_back(std::make_unique<Shape>(cfg));
        isMoving = true;
    }
    BeginDrawing();
    ClearBackground(BLACK);

    shapes.back().get()->draw();

    EndDrawing();
    static int i = 0;
    std::cout << i++ << "\t" << shapes.size() << std::endl;
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
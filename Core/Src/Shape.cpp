#include "Shape.h"

#include "Colors.h"

#include <cstdlib>
#include <iostream>

Shape::Shape(const Config& cfg) : size(40), velocity(size) {
  pos = {(float)cfg.getWindowHeight() / 2, (float)cfg.getWindowHeight() / 2};
  shape = (ShapeType)(std::rand() % 7);
}

Shape::~Shape() {}

void Shape::update() {
    handleInput();
    if (pos.y >= GetScreenHeight() - size) velocity = 0;
    pos.y += velocity;
}

void Shape::handleInput() {
    if (IsKeyPressed(KEY_RIGHT)) std::cout << "move right" << std::endl;
    if (IsKeyPressed(KEY_LEFT)) std::cout << "move left" << std::endl;
    if (IsKeyPressed(KEY_DOWN)) std::cout << "move down" << std::endl;
    if (IsKeyPressed(KEY_SPACE)) std::cout << "turn clockwise" << std::endl;   
}

void Shape::draw() {
    switch (shape) {
        case (ShapeType::I): drawI(); break;
        case (ShapeType::J): drawJ(); break;
        case (ShapeType::L): drawL(); break;
        case (ShapeType::O): drawO(); break;
        case (ShapeType::S): drawS(); break;
        case (ShapeType::T): drawT(); break;
        case (ShapeType::Z): drawZ(); break;
    }
}

int Shape::getVelocity() {
    return velocity;
}

void Shape::drawI() {
    for (int i = 0; i < 4; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_I);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_I);
    }
}

void Shape::drawO() {
    for (int i = 0; i < 2; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_O);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_O);
    }
    for (int i = 0; i < 2; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y - size, size, size, RIM_O);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_O);
    }
}

void Shape::drawT() {
    for (int i = 0; i < 3; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_T);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_T);
    }
    DrawRectangle((int)pos.x + size, (int)pos.y - size, size, size, RIM_T);
    DrawRectangle((int)pos.x + (int)(size / 20) + size, (int)pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_T);
}

void Shape::drawZ() {
    for (int i = 0; i < 2; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_Z);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_Z);
    }
    for (int i = 0; i < 2; i++) {
        DrawRectangle((int)pos.x + size * i - size, (int)pos.y - size, size, size, RIM_Z);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i - size, (int)pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_Z);
    }
}

void Shape::drawS() {
    for (int i = 0; i < 2; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_S);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_S);
    }
    for (int i = 0; i < 2; i++) {
        DrawRectangle((int)pos.x + size * i + size, (int)pos.y - size, size, size, RIM_S);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i + size, (int)pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_S);
    }
}

void Shape::drawJ() {
    for (int i = 0; i < 4; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_J);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_J);
    }
    DrawRectangle((int)pos.x + size * 3, (int)pos.y - size, size, size, RIM_J);
    DrawRectangle((int)pos.x + (int)(size / 20) + size * 3, (int)pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_J);
}

void Shape::drawL() {
    for (int i = 0; i < 4; i++) {
        DrawRectangle((int)pos.x + size * i, (int)pos.y, size, size, RIM_L);
        DrawRectangle((int)pos.x + (int)(size / 20) + size * i, (int)pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_L);
    }
    DrawRectangle((int)pos.x, (int)pos.y - size, size, size, RIM_L);
    DrawRectangle((int)pos.x + (int)(size / 20), (int)pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_L);
}

#include "Shape.h"

#include "Colors.h"

#include <cstdlib>

Shape::Shape(const Config& cfg) : size(40), velocity(size) {
  pos = {(float)cfg.getWindowHeight() / 2, (float)cfg.getWindowHeight() / 2};
  shape = (ShapeType)(std::rand() % 7);
}

Shape::~Shape() {}

void Shape::update() {
    if (pos.y >= GetScreenHeight() - size) velocity = 0;
    pos.y += velocity;
}

void Shape::draw() {
    switch (shape) {
        case (ShapeType::I): drawI();
        case (ShapeType::J): drawJ();
        case (ShapeType::L): drawL();
        case (ShapeType::O): drawO();
        case (ShapeType::S): drawS();
        case (ShapeType::T): drawT();
        case (ShapeType::Z): drawZ();
    }
}

int Shape::getVelocity() {
    return velocity;
}

void Shape::drawI() {
    for (int i = 0; i < 4; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_I);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_I);
    }
}

void Shape::drawO() {
    for (int i = 0; i < 2; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_O);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_O);
    }
    for (int i = 0; i < 2; i++) {
        DrawRectangle(pos.x + size * i, pos.y - size, size, size, RIM_O);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_O);
    }
}

void Shape::drawT() {
    for (int i = 0; i < 3; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_T);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_T);
    }
    DrawRectangle(pos.x + size, pos.y - size, size, size, RIM_T);
    DrawRectangle(pos.x + (int)(size / 20) + size, pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_T);
}

void Shape::drawZ() {
    for (int i = 0; i < 2; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_Z);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_Z);
    }
    for (int i = 0; i < 2; i++) {
        DrawRectangle(pos.x + size * i - size, pos.y - size, size, size, RIM_Z);
        DrawRectangle(pos.x + (int)(size / 20) + size * i - size, pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_Z);
    }
}

void Shape::drawS() {
    for (int i = 0; i < 2; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_S);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_S);
    }
    for (int i = 0; i < 2; i++) {
        DrawRectangle(pos.x + size * i + size, pos.y - size, size, size, RIM_S);
        DrawRectangle(pos.x + (int)(size / 20) + size * i + size, pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_S);
    }
}

void Shape::drawJ() {
    for (int i = 0; i < 4; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_J);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_J);
    }
    DrawRectangle(pos.x + size * 3, pos.y - size, size, size, RIM_J);
    DrawRectangle(pos.x + (int)(size / 20) + size * 3, pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_J);
}

void Shape::drawL() {
    for (int i = 0; i < 4; i++) {
        DrawRectangle(pos.x + size * i, pos.y, size, size, RIM_L);
        DrawRectangle(pos.x + (int)(size / 20) + size * i, pos.y + (int)(size / 20), size - (int)(size / 10), size - (int)(size / 10), BODY_L);
    }
    DrawRectangle(pos.x, pos.y - size, size, size, RIM_L);
    DrawRectangle(pos.x + (int)(size / 20), pos.y + (int)(size / 20) - size, size - (int)(size / 10), size - (int)(size / 10), BODY_L);
}

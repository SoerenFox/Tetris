#pragma once

#include <raylib.h>

#include "Config.h"

enum class ShapeType { I, J, L, O, S, T, Z };

class Shape {
    ShapeType shape;
    Vector2 pos;
    int size;
    int velocity;
    
    void drawI();
    void drawJ();
    void drawL();
    void drawO();
    void drawS();
    void drawT();
    void drawZ();
    void handleInput();

    public:
        Shape(const Config& cfg);
        ~Shape();
        void update();
        void draw();
        int getVelocity();
};
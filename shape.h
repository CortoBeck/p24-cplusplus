#pragma once

#include <iostream>
#include <vector>

class shape {
public:
    shape() : x(0), y(0) {}
    shape(float x, float y) : x(x), y(y) {}

    virtual void move(float dx, float dy) {
        x += dx;
        y += dy;
    }

    virtual float area() const = 0;
    virtual bool is_at_position(float px, float py) const = 0;

protected:
    float x;
    float y;
};

class square : public shape {
public:
    square(float x, float y, float length) : shape(x, y), length(length) {}

    float area() const override {
        return length * length;
    }

    bool is_at_position(float px, float py) const override {
        return px >= x && px <= x + length && py >= y && py <= y + length;
    }

private:
    float length;
};

class rectangle : public shape {
public:
    rectangle(float x, float y, float width, float height) 
        : shape(x, y), width(width), height(height) {}

    float area() const override {
        return width * height;
    }

    bool is_at_position(float px, float py) const override {
        return px >= x && px <= x + width && py >= y && py <= y + height;
    }

private:
    float width;
    float height;
};

class circle : public shape {
public:
    circle(float x, float y, float radius) : shape(x, y), radius(radius) {}

    float area() const override {
        return 3.14f * radius * radius;
    }

    bool is_at_position(float px, float py) const override {
        float dx = px - x;
        float dy = py - y;
        return (dx * dx + dy * dy) <= radius * radius;
    }

private:
    float radius;
};

shape* find_at_position(float px, float py, const std::vector<shape*>& shapes) {
    for (shape* s : shapes) {
        if (s->is_at_position(px, py)) {
            return s;
        }
    }
    return nullptr;
}
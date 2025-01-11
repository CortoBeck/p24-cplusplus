// inclusion des bibliothèques standard ici
#include <iostream>
#include <vector>

// définition de vos classes ici
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

// optionnel:
// faire une fonction prend en argument x, y et un vecteur de formes et retourne la forme au point (x, y)
shape* find_at_position(float px, float py, const std::vector<shape*>& shapes) {
    // dans cette fonction vous avez besoin de tester si une forme est au point (x, y)
    // pour faire cela sans mettre cette fonction friend, ajouter en plus de move et area
    // une méthode bool is_at_position(int x, int y)
    for (shape* s : shapes) {
        if (s->is_at_position(px, py)) {
            return s;
        }
    }
    return nullptr;
}

int main() {
    circle c(10, 20, 4.5f);       // x, y, radius
    rectangle r(20, 30, 30, 60); // x, y, width, height
    std::vector<shape*> shapes;
    shapes.push_back(&c);
    shapes.push_back(&r);

    // première version (sans find_at_position et is_at_position)
    shapes[0]->move(4, 6);
    shapes[1]->move(2, 8);
    std::cout << shapes[0]->area() << std::endl; // affiche dans les 63.585
    std::cout << shapes[1]->area() << std::endl; // 1800

    // deuxième version (avec find_at_position et is_at_position)
    shape* shape1 = find_at_position(14, 26, shapes);
    if (shape1) {
        std::cout << "Found shape at (14, 26): area = " << shape1->area() << std::endl;
        shape1->move(1, 1); // Exemple d'appel à move
    }

    shape* shape2 = find_at_position(100, 200, shapes);
    if (shape2) {
        std::cout << "Found shape at (100, 200): area = " << shape2->area() << std::endl;
    } else {
        std::cout << "No shape found at (100, 200)." << std::endl;
    }

    return 0;
}
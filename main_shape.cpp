#include <iostream>
#include "shape.h"

int main() {
    try {
        circle c(10, 20, 4.5f);
        rectangle r(20, 30, 30, 60);
        std::vector<shape*> shapes;
        shapes.push_back(&c);
        shapes.push_back(&r);

        shapes[0]->move(4, 6);
        shapes[1]->move(2, 8);
        std::cout << shapes[0]->area() << std::endl;
        std::cout << shapes[1]->area() << std::endl;

        shape* shape1 = find_at_position(14, 26, shapes);
        if (shape1) {
            std::cout << "Found shape at (14, 26): area = " << shape1->area() << std::endl;
            shape1->move(1, 1); 
        }

        shape* shape2 = find_at_position(100, 200, shapes);
        if (shape2) {
            std::cout << "Found shape at (100, 200): area = " << shape2->area() << std::endl;
        } else {
            std::cout << "No shape found at (100, 200)." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
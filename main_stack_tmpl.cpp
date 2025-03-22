#include <iostream>
#include "stack_tmpl.h"

int main() {
    Stack<int, 5> s;

    try {
        s.push(1);
        s.push(2);
        s.push(3);

        std::cout << "Contenu de la pile : " << s << std::endl;

        std::cout << "Sommet : " << s.get_top() << std::endl;

        s.pop();
        std::cout << "pile après dépilage : " << s << std::endl;

        std::cout << "Test d'affichage d'une pile vide" << std::endl;
        Stack<int, 3> empty_stack;
        std::cout << empty_stack << std::endl;

    } catch (const std::exception& e) {
        std::cerr <<  e.what() << std::endl;
    }

    return 0;
}

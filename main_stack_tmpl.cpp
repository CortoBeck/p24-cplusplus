#include <iostream>
#include "stack_tmpl.h"

int main() {
    Stack<int, 5> s;

    try {
        std::cout << "Empilage de 1, 2, 3" << std::endl;
        s.push(1);
        s.push(2);
        s.push(3);

        std::cout << "Contenu de la pile : " << s << std::endl;

        std::cout << "Sommet de la pile : " << s.get_top() << std::endl;

        std::cout << "Dépilage : " << s.pop() << std::endl;
        std::cout << "Contenu de la pile après dépilage : " << s << std::endl;

        std::cout << "Test d'affichage d'une pile vide..." << std::endl;
        Stack<int, 3> empty_stack;
        std::cout << empty_stack << std::endl;  // Devrait lever une exception

    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}
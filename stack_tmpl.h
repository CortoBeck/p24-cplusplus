#pragma once

#include <iostream>
#include <stdexcept>

template <typename T, int SIZE> // Template sur le type et la taille
class Stack {
private:
    T pile[SIZE]; // Tableau pour stocker les éléments
    int length{}; // Nombre d'éléments dans la pile, initialement vide

public:
    void push(T e);
    T get_top() const;
    T pop();
    bool is_empty() const;
    bool is_full() const;
    void print() const;

    // Surcharge de l'opérateur <<
    template <typename U, int N>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U, N>& pile);
};

// Implémentation des méthodes

template <typename T, int SIZE>
inline void Stack<T, SIZE>::push(T e) {
    if (is_full()) {
        throw std::overflow_error("Erreur : on essaye d'empiler sur une pile pleine.");
    }
    pile[length] = e;
    length += 1;
}

template <typename T, int SIZE>
inline T Stack<T, SIZE>::get_top() const {
    if (is_empty()) {
        throw std::underflow_error("Erreur : on essaye de lire une pile vide.");
    }
    return pile[length - 1];
}

template <typename T, int SIZE>
inline T Stack<T, SIZE>::pop() {
    if (is_empty()) {
        throw std::underflow_error("Erreur : on essaye de dépiler une pile vide.");
    }
    T top = pile[length - 1];
    length -= 1;
    return top;
}

template <typename T, int SIZE>
inline bool Stack<T, SIZE>::is_empty() const {
    return length == 0;
}

template <typename T, int SIZE>
inline bool Stack<T, SIZE>::is_full() const {
    return length == SIZE;
}

template <typename T, int SIZE>
inline void Stack<T, SIZE>::print() const {
    if (is_empty()) {
        throw std::runtime_error("Erreur : affichage impossible d'une pile vide.");
    }

    std::cout << "[ ";
    for (int k = 0; k < length; k++) {
        std::cout << pile[k] << " ";
    }
    std::cout << "[\n";
}

template <typename T, int SIZE>
inline std::ostream& operator<<(std::ostream& os, const Stack<T, SIZE>& pile) {
    pile.print();
    return os;
}
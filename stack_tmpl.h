#pragma once

#include <iostream>
#include <stdexcept>

template <typename T, int SIZE>
class Stack {
private:
    T pile[SIZE];
    int length{};

public:
    void push(T e);
    T get_top() const;
    T pop();
    bool is_empty() const;
    bool is_full() const;
    void print() const;

    template <typename U, int N>
    friend std::ostream& operator<<(std::ostream& os, const Stack<U, N>& pile);
};


template <typename T, int SIZE>
inline void Stack<T, SIZE>::push(T e) {
    if (is_full()) {
        throw std::overflow_error("Erreur :pile pleine.");
    }
    pile[length] = e;
    length += 1;
}

template <typename T, int SIZE>
inline T Stack<T, SIZE>::get_top() const {
    if (is_empty()) {
        throw std::underflow_error("Erreur : pile vide.");
    }
    return pile[length - 1];
}

template <typename T, int SIZE>
inline T Stack<T, SIZE>::pop() {
    if (is_empty()) {
        throw std::underflow_error("Erreur : pile vide.");
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
        throw std::runtime_error("Erreur : pile vide.");
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

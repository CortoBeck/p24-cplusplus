#pragma once
#include <iostream>

// Swap avec des pointeurs
inline void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Swap avec des références
inline void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}
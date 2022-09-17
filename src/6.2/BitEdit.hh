#ifndef BITEDIT_HH
#define BITEDIT_HH
#include <iostream>
#include <istream>
#include <ostream>

    void bitOut(std::ostream output, int latter);
    void bitIn(std::istream input, int latter);
    bool get(int val, unsigned int offset);
    bool set(int val, unsigned int off)
#endif
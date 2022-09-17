/**
 * @file BitEditor.hh
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BITEDITOR_HH
#define BITEDITOR_HH

#include <iostream>

using bits_t = char;

// can bit_t bit be a reference? does it change?

bool get(bits_t const& bits, unsigned int const& offset);

bits_t set(bits_t const& bits, unsigned int const& offset, bool const& value);

bits_t insL(bits_t const& bits, unsigned int const& offset, bool const& value);
bits_t insR(bits_t const& bits, unsigned int const& offset, bool const& value);

bits_t delL(bits_t const& bits, unsigned int const& offset);
bits_t delL(bits_t const& bits, unsigned int const& offset, bool const& value);

bits_t delR(bits_t const& bits, unsigned int const& offset);
bits_t delR(bits_t const& bits, unsigned int const& offset, bool const& value);

std::istream& bitIn(std::istream& is, bits_t& bits);
std::ostream& bitOut(std::ostream& os, bits_t const& bits);

#endif
/**
 * @file BitEditor.cc
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "BitEditor.hh"

// =============================================================================
// FUNCTIONS
// =============================================================================

// -----------------------------------------------------------------------------
// GET - SET
// -----------------------------------------------------------------------------

bool get(bits_t const& bits, unsigned int const& offset)
{
    return (bits >> offset) & 1UL;
}

bits_t set(bits_t const& bits, unsigned int const& offset, bool const& value)
{   //      clear the value at offset   set the offset to value
    return (bits & ~(1UL << offset)) | (value << offset);
}

// -----------------------------------------------------------------------------
// INSERT LEFT/RIGHT
// -----------------------------------------------------------------------------

bits_t insL(bits_t const& bits, unsigned int const& offset, bool const& value)
{
    bits_t newBits{0};

    for (unsigned long i{0}; i < sizeof(bits_t)*8; ++i)
    {
        bool newValue;

        if (i < offset)
            newValue = get(bits, i);
        else if (i == offset)
            newValue = value;
        else
            newValue = get(bits, (i-1));

        newBits = set(newBits, i, newValue);
    }

    return newBits;
}

bits_t insR(bits_t const& bits, unsigned int const& offset, bool const& value)
{
    bits_t newBits{0};

    for (unsigned long i{0}; i < sizeof(bits_t)*8; ++i)
    {
        bool newValue;

        if (i < offset)
            newValue = get(bits, (i+1));
        else if (i == offset)
            newValue = value;
        else
            newValue = get(bits, i);

        newBits = set(newBits, i, newValue);
    }

    return newBits;
}

// -----------------------------------------------------------------------------
// DELETE LEFT/RIGHT
// -----------------------------------------------------------------------------

bits_t delL(bits_t const& bits, unsigned int const& offset)
{
    return delL(bits, offset, 0);
}

bits_t delL(bits_t const& bits, unsigned int const& offset, bool const& value)
{
    bits_t newBits{0};

    for (unsigned long i{0}; i < sizeof(bits_t)*8; ++i)
    {
        bool newValue;

        if (i == 0)
            newValue = value;
        else if (i <= offset)
            newValue = get(bits, (i-1));
        else
            newValue = get(bits, (i));

        newBits = set(newBits, i, newValue);
    }

    return newBits;
}

bits_t delR(bits_t const& bits, unsigned int const& offset)
{
    bool value{get(bits, (sizeof(bits_t)*8-1))}; // 0 or 1

    return delR(bits, offset, value);
}

bits_t delR(bits_t const& bits, unsigned int const& offset, bool const& value)
{
    bits_t newBits{0};

    for (unsigned long i{0}; i < sizeof(bits_t)*8; ++i)
    {
        bool newValue;

        if (i < offset)
            newValue = get(bits, i);
        else if (i == (sizeof(bits_t)*8-1))
            newValue = value;
        else
            newValue = get(bits, (i+1));

        newBits = set(newBits, i, newValue);
    }

    return newBits;
}

// -----------------------------------------------------------------------------
// BIT-IN/OUT
// -----------------------------------------------------------------------------

// FIXME: if the input starts with a 0 it gets converted to a 1
std::istream& bitIn(std::istream& is, bits_t& bits)
{
    bool buf;
    unsigned long const MAX{sizeof(bits_t)*8};

    std::cout << "\nEnter " << MAX << " bits:" << std::endl;

    for (unsigned long i{0}; i < sizeof(bits_t)*8; ++i)
    {
        is >> buf;
        bits = set(bits, i, buf);
    }
    return is;
}

std::ostream& bitOut(std::ostream& os, bits_t const& bits)
{
    unsigned long const MAX{sizeof(bits_t)*8};
    bool bufBits[MAX];

    for (unsigned long i{0}; i < MAX; ++i)
    {
        bufBits[MAX-i-1] = get(bits, i);
    }

    // for (unsigned long i{max-1}; i >= 0; --i)
    for (bool value : bufBits)
    {
        os << value;
    }

    return os;
}
#ifndef RATIONAL_HH
#define RATIONAL_HH
#include <iostream>
#include <ostream>
#include <sys/select.h>
namespace GCD {
    int gcd(int numerator, int denumerator);
}

class Rational
{
public:
    using Integer = int;
    using Natural = int;

private:
    Integer numerator_;
    Natural denumerator_;
public:
    Rational();

    Rational(int const &numerator, int const &denumerator);

    Rational(Integer const &numerator);

    Integer numer();
    
    Natural denom();

    void print();

    const bool operator<(Rational const& r);
    const bool operator>(Rational const& r);
    const bool operator<=(Rational const& r);
    const bool operator>=(Rational const& r);
    const bool operator==(Rational const& r);

    Rational operator-(Rational const& r) const;
    Rational operator+(Rational const& r) const;
    Rational operator*(Rational const& r) const;
    Rational operator/(Rational const& r) const;
    
    void operator-=(Rational const& r);
    void operator+=(Rational const& r);
    void operator*=(Rational const& r);
    void operator/=(Rational const& r);

    Rational recip() const;

    Rational operator<<(std::istream& input);
    void operator>>(Rational r);
}; //class Rational
#endif
#ifndef RATIONAL_HH
#define RATIONAL_HH
#include <iostream>
#include <ostream>
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

    Integer numer() const;
    
    Natural denom() const;

    void print();
    Rational add(Rational const &other);

    const bool operator<(Rational const& r);
    const bool operator>(Rational const& r);
    const bool operator<=(Rational const& r);
    const bool operator>=(Rational const& r);
    const bool operator==(Rational const& r);
    
    void operator-=(Rational const& r);
    void operator+=(Rational const& r);
    void operator*=(Rational const& r);
    void operator/=(Rational const& r);

    Rational recip() const;


}; //class Rational

    Rational operator-(Rational const& r1, Rational const& r2);
    Rational operator+(Rational const& r1, Rational const& r2);
    Rational operator*(Rational const& r1, Rational const& r2);
    Rational operator/(Rational const& r1, Rational const& r2);

    std::ostream& operator<<(std::ostream& out, Rational& r);
    std::istream& operator>>(std::istream&, Rational r);
#endif
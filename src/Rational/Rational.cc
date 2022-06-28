#include <iostream>
#include "Rational.hh"
class Rational {
private:
  using Integer = int;
  using Natural = int;
  Integer numerator;
  Natural denominator;


public:


  std::string toString() const {
    return std::to_string(numerator) + " / " + std::to_string(denominator);
  }

  std::ostream &operator<<(std::ostream &out) const {
    return out << toString() << std::endl;
  }

/*  std::ostream &operator>>(std::istream in) const {

  }*/


  bool operator<(Rational const& r2) const {
    return (this->numerator * r2.denominator) <
           (r2.numerator * this->denominator);
  }
  bool operator>(Rational r2) const {
    return (this->numerator * r2.denominator) >
           (r2.numerator * this->denominator);
  }
  bool operator<=(Rational r2) const {
    return (this->numerator * r2.denominator) <=
           (r2.numerator * this->denominator);
  }
  bool operator>=(Rational r2) const {
    return (this->numerator * r2.denominator) >=
           (r2.numerator * this->denominator);
  }
  rational::Rational operator-(Rational r2) const {
    return rational::Rational{(this->numerator * r2.denominator) -
                        (r2.numerator * this->denominator),
                    this->denominator * r2.denominator};
  }
  rational::Rational operator+(Rational r2) const {
    return rational::Rational{(this->numerator * r2.denominator) +
                        (r2.numerator * this->denominator),
                    this->denominator * r2.denominator};
  }
  rational::Rational operator*(Rational r2) const {
    return rational::Rational{(this->numerator * r2.numerator),
                    this->denominator * r2.denominator};
  }
  /*Rational operator/(Rational r2) const {
    return Rational{(this->numerator * r2.denominator),
                    this->numerator * r2.denominator};
  }
  Rational operator+=(Rational const& r)
  {
    this->denominator = (this->numerator * r.denominator) +
                        (r.numerator * this->denominator);
    this->numerator = this->denominator * r.denominator;
    return *this;
  }
  Rational operator-=(Rational r) const
  {
    r = r - *this;
    return r;
  }
  Rational operator*=(Rational r) const
  {
    r = r * *this;
    return r;
  }
  Rational operator/=(Rational r) const
  {
    r = r / *this;
    return r;
  }
  Rational recip() const
  {
      return Rational{this->denominator, this->numerator};
  }
  Integer getNumerator() const
  {
    return numerator;
  }*/

  Natural getDenominator() const { return denominator; }
};

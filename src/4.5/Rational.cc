#include "Rational.hh"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

Rational::Rational() : numerator_{0}, denumerator_{1}
{
}

Rational::Rational(Integer const &numerator) : numerator_(numerator), denumerator_(1)
{
}

Rational::Rational(int const &numerator, int const &denumerator) : numerator_(numerator), denumerator_(denumerator)
{
    int gcd = GCD::gcd(this->numerator_, this->denumerator_);
    this->numerator_ /= gcd;
    this->denumerator_ /= gcd;
    if (this->denumerator_ < 0)
    {
        this->denumerator_ *= -1;
    }
}

int GCD::gcd(int numerator, int denumerator)
{
    if (numerator < denumerator)
    {
        return gcd(denumerator, numerator);
    }
    if (numerator == 0)
    {
        return denumerator;
    }
    return gcd(denumerator, numerator % denumerator);
}

Rational::Integer Rational::numer() const
{
    return this->numerator_;
}

Rational::Natural Rational::denom() const
{
    return this->denumerator_;
}

void Rational::print()
{
    std::cout << this->numerator_ << '/' << this->denumerator_ << std::endl;
}

Rational Rational::add(Rational const &other)
{
    return *this + other;
}

Rational Rational::recip() const
{
    Rational ret{this->denumerator_, this->numerator_};
    return ret;
}

const bool Rational::operator<(Rational const &r)
{
    return (this->numerator_ * r.denumerator_) < (r.numerator_ * this->denumerator_);
}

const bool Rational::operator>(Rational const &r)
{
    return (this->numerator_ * r.denumerator_) > (r.numerator_ * this->denumerator_);
}

const bool Rational::operator<=(Rational const &r)
{
    return (this->numerator_ * r.denumerator_) <= (r.numerator_ * this->denumerator_);
}

const bool Rational::operator>=(Rational const &r)
{
    return (this->numerator_ * r.denumerator_) >= (r.numerator_ * this->denumerator_);
}

const bool Rational::operator==(const Rational &r)
{
    return (this->numerator_ * r.denumerator_) == (r.numerator_ * this->denumerator_);
}

Rational operator-(Rational const& r1, Rational const& r2) 
{
    Rational ret{r1.numer() - r2.numer(), r1.denom() - r2.denom()};
    return ret;
}

Rational operator+(Rational const &r1, Rational const& r2) 
{
    Rational ret{r1.numer() + r2.numer(), r1.denom() + r2.denom()};
    return ret;
}

Rational operator*(Rational const &r1, Rational const& r2) 
{
    Rational ret{r1.numer() * r2.numer(), r1.denom() * r2.denom()};
    return ret;
}

Rational operator/(Rational const &r1, Rational const& r2) 
{
    Rational ret{r1.numer() * r2.denom(), r1.numer() * r2.denom()};
    return ret;
}

void Rational::operator-=(Rational const &r)
{
    this->numerator_ = this->numerator_ - r.numerator_;
    this->denumerator_ = this->denumerator_ - r.denumerator_;
}

void Rational::operator+=(Rational const &r)
{
    this->numerator_ = this->numerator_ + r.numerator_;
    this->denumerator_ = this->denumerator_ + r.denumerator_;
}

void Rational::operator*=(Rational const &r)
{
    this->numerator_ = this->numerator_ * r.numerator_;
    this->denumerator_ = this->denumerator_ * r.denumerator_;
}
void Rational::operator/=(Rational const &r)
{
    this->numerator_ = this->numerator_ / r.numerator_;
    this->denumerator_ = this->denumerator_ / r.denumerator_;
}

std::ostream& operator<<(std::ostream& out, Rational& r)
{
    out << r.denom() + '/' + r.numer();
    return out;
    
}

std::istream& operator>>(std::istream& in, Rational& r)
{
    Rational::Integer numer;
    char slash;
    Rational::Natural denum;
    in >> numer;
    in >> slash;
    in >> denum;
    r = Rational{numer, denum};
    return in;
}

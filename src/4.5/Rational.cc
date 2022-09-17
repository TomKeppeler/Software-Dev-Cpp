#include "Rational.hh"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

    Rational::Rational() : numerator_{0}, denumerator_{1}
    {}

    Rational::Rational(Integer const &numerator) : numerator_(numerator), denumerator_(1)
    {}

    Rational::Rational(int const &numerator, int const &denumerator) : numerator_(numerator), denumerator_(denumerator)
    {
        int gcd = GCD::gcd(this->numerator_, this->denumerator_);
        this->numerator_ /= gcd;
        this->denumerator_ /= gcd;
        if (this->denumerator_ < 0) {
            this->denumerator_*= -1;
        }
    }

    int GCD::gcd(int numerator, int denumerator) {
        if(numerator < denumerator) {
            return gcd(denumerator, numerator);
        }
        if (numerator == 0) {
            return denumerator;
        }
        return gcd(denumerator, numerator%denumerator);
    }

    Rational::Integer Rational::numer(){
        return this->numerator_;
    }
    
    Rational::Natural Rational::denom(){
        return this->denumerator_;
    }

    void Rational::print()
    {
        std::cout << this->numerator_ << '/' << this->denumerator_ << std::endl;
    }

    const bool Rational::operator<(Rational const& r) {
        return (this->numerator_ * r.denumerator_) <
            (r.numerator_ * this->denumerator_);
    }

    const bool Rational::operator>(Rational const& r) {
        return (this->numerator_ * r.denumerator_) >
            (r.numerator_ * this->denumerator_);
    }

    const bool Rational::operator<=(Rational const& r) {
        return (this->numerator_ * r.denumerator_) <=
            (r.numerator_ * this->denumerator_);
    }

    const bool Rational::operator>=(Rational const& r) {
        return (this->numerator_ * r.denumerator_) >=
            (r.numerator_ * this->denumerator_);
    }

    const bool Rational::operator==(const Rational &r)  {
        return (this->numerator_ * r.denumerator_) ==
            (r.numerator_ * this->denumerator_);
    }

    Rational Rational::operator-(Rational const& r) const{
        Rational ret{this->numerator_ - r.numerator_, 
            this->denumerator_ - r.denumerator_};
        return ret;
    }

    Rational Rational::operator+(Rational const& r) const {
        Rational ret{this->numerator_ + r.numerator_,
                    this->denumerator_ + r.denumerator_};
        return ret;
    }

    Rational Rational::operator*(Rational const& r) const {
        Rational ret{this->numerator_ * r.numerator_,
                    this->denumerator_ * r.denumerator_};
        return ret;
    }

    Rational Rational::operator/(Rational const& r) const {
        Rational ret{this->numerator_ * r.denumerator_, 
                    this->numerator_ * r.denumerator_};
        return ret;
    }

    void Rational::operator-=(Rational const& r){
        this->numerator_ = this->numerator_ - r.numerator_;
        this->denumerator_ = this->denumerator_ - r.denumerator_;
    }

    void Rational::operator+=(Rational const& r){
        this->numerator_ = this->numerator_ + r.numerator_;
        this->denumerator_ = this->denumerator_ + r.denumerator_;
    }

    void Rational::operator*=(Rational const& r){
        this->numerator_ = this->numerator_ * r.numerator_;
        this->denumerator_ = this->denumerator_ * r.denumerator_;
    }
    void Rational::operator/=(Rational const& r){
        this->numerator_ = this->numerator_ / r.numerator_;
        this->denumerator_ = this->denumerator_ / r.denumerator_;
    }
    

    Rational Rational::recip() const {
        Rational ret{this->denumerator_, this->numerator_};
        return ret;
    }
    Rational Rational::operator<<(std::istream& input) {
        Rational::Integer numer; 
        char slash;
        Rational::Natural denum;
        std::cin >> numer;
        std::cin >> slash;
        std::cin >> denum;
        return Rational{numer, denum};
    }

    void Rational::operator>>(Rational r) {
        std::cout << r.denom() + '/' + r.numer(); 
    }   
#include "Rational.hh"
#include <iostream>
#include <ostream>
#include <string>

namespace linalg {

    Rational::Rational() : numerator_{0}, denumerator_{1}
    {}

    Rational::Rational(Integer const &numerator) : numerator_(numerator), denumerator_(1)
    {}

    Rational::Rational(int const &numerator, int const &denumerator) : numerator_(numerator), denumerator_(denumerator)
    {
        int gcd = Rational::gcd(this->numerator_, this->denumerator_);
        this->numerator_ /= gcd;
        this->denumerator_ /= gcd;
        if (this->denumerator_ < 0) {
            this->denumerator_*= -1;
        }
    }

    int Rational::gcd(int a, int b){
        if(a < b) {
            return gcd(b, a);
        }
        if (a == 0) {
            return b;
        }
        return gcd(b, a%b);
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

    bool Rational::operator<(Rational const& r) const {
        return (this->numerator_ * r.denumerator_) <
            (r.numerator_ * this->denumerator_);
    }

    bool Rational::operator>(Rational const& r) const {
        return (this->numerator_ * r.denumerator_) >
            (r.numerator_ * this->denumerator_);
    }

    bool Rational::operator<=(Rational const& r) const {
        return (this->numerator_ * r.denumerator_) <=
            (r.numerator_ * this->denumerator_);
    }

    bool Rational::operator>=(Rational const& r) const {
        return (this->numerator_ * r.denumerator_) >=
            (r.numerator_ * this->denumerator_);
    }

    bool Rational::operator==(const Rational &r) const {
        return (this->numerator_ * r.denumerator_) ==
            (r.numerator_ * this->denumerator_);
    }

    Rational Rational::operator-(Rational const& r) const{
        this->numerator_ = this->numerator_ - r.numerator_;
        this->denumerator_ = this->denumerator_ - r.denumerator_;
    }

    Rational Rational::operator+(Rational const& r) const{
        this->numerator_ = this->numerator_ + r.numerator_;
        this->denumerator_ = this->denumerator_ + r.denumerator_;
    }

    Rational Rational::operator*(Rational const& r) const{
        this->numerator_ = this->numerator_ * r.numerator_;
        this->denumerator_ = this->denumerator_ * r.denumerator_;
    }
    Rational Rational::operator/(Rational const& r) const{
        this->numerator_ = this->numerator_ / r.numerator_;
        this->denumerator_ = this->denumerator_ / r.denumerator_;
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
    

    Rational Rational::recip() {
        return Rational{this->denumerator_, this->numerator_};
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
}
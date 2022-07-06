#ifndef RATIONAL_HH
#define RATIONAL_HH
#include <iostream>

namespace linalg
{
class Rational;

int gcd(int a, int b);

class Rational
{
public:
    using Integer = int;
    using Natural = int;

private:
    Integer numerator_;
    Natural denumerator_;

public:
    Rational() : numerator_{0}, denumerator_{1}
    {}

    Rational(int const &numerator, int const &denumerator) : numerator_(numerator), denumerator_(denumerator)
    {
        int gcd = linalg::gcd(this->numerator_, this->denumerator_);
        this->numerator_ /= gcd;
        this->denumerator_ /= gcd;
        if (this->denumerator_ < 0) {
            this->denumerator_*= -1;
        }
    }

    Rational(Integer const &numerator) : numerator_(numerator), denumerator_(1)
    {}

    void print()
    {
        std::cout << this->numerator_ << '/' << this->denumerator_ << std::endl;
    }
}; //class Rational

} // namespace linalg
#endif
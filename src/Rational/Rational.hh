#ifndef RATIONAL_HH
#define RATIONAL_HH

#include <iostream>
namespace rational
{
  class Rational
  {
  private:
    using Integer = int;
    using Natural = int;
    Integer numerator;
    Natural denominator;
  public:
    Rational() : numerator{0}, denominator{1} {}

    Rational(int numerator) : numerator{abs(numerator)}, denominator{1} {}
    Rational(int num, int den) : numerator{abs(num)}, denominator{abs(den)} {
      reduce(num, den);
    }
    void readIn() {
      int num = 0, den = 0;
      std::cout << "numerator: " << std::flush;
      std::cin >> num;

      std::cout << "denominator: " << std::flush;
      std::cin >> den;
      numerator = abs(num);
      denominator = abs(den);
      reduce(num, den);
    }
  private:
    int greatestCommonDivisor(int a, int b) {
      if (b == 0){
        return a;
      } else {
        return greatestCommonDivisor(b, a % b);
      }
    }
  void reduce(int num, int den) {
      int gcd = greatestCommonDivisor(num, den);
      numerator /= gcd;
      denominator /= gcd;
    }

  int abs(int a) {
    if (a < 0) {
      a *= -1;
    }
      return a;
    }
  };
} // namespace rational

#endif

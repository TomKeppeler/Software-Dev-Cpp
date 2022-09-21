#include <cmath>

#include "Rational.hpp"


int gcd(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);

	if(a == 0) return b;
	if(b == 0) return a;

	int h;
	do {
		h = a % b;
		a = b;
		b = h;
	}while(b != 0);

	return a;
}

Rational::Rational() : Rational(0) {}
Rational::Rational(Integer num) : num{num}, denom{1} {}
Rational::Rational(Integer num, Natural denom) : num{num}, denom{denom} {
	reduce();
}

Rational::Integer Rational::numerator() const {
	return num;
}
Rational::Natural Rational::denominator() const {
	return denom;
}

Rational Rational::recip() const {
	Integer n = (num < 0) ? -denom : denom;
	Natural d = std::abs(num);

	return Rational(n, d);
}

void Rational::reduce() {
	int g{gcd(num, denom)};

	num /= g;
	denom /= g;
}

Rational& Rational::operator+=(const Rational& r) {
	*this = *this + r;
	return *this;
}
Rational& Rational::operator-=(const Rational& r) {
	*this = *this - r;
	return *this;
}
Rational& Rational::operator*=(const Rational& r) {
	*this = *this * r;
	return *this;
}
Rational& Rational::operator/=(const Rational& r) {
	*this = *this / r;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) {
	return out << r.numerator() << "/" << r.denominator();
}
std::istream& operator>>(std::istream& in, Rational& r) {
	Rational::Integer num;
	Rational::Natural denom;

	std::istream& result{in >> num >> denom};

	r = Rational{num, denom};

	return result;
}

bool operator==(const Rational& r1, const Rational& r2) {
	return r1.numerator() == r2.numerator() && r1.denominator() == r2.denominator();
}
bool operator!=(const Rational& r1, const Rational& r2) {
	return !(r1 == r2);
}
bool operator<(const Rational& r1, const Rational& r2) {
	return r1.numerator() * r2.denominator() < r1.denominator() * r2.numerator();
}
bool operator>(const Rational& r1, const Rational& r2) {
	return r1.numerator() * r2.denominator() > r1.denominator() * r2.numerator();
}
bool operator<=(const Rational& r1, const Rational& r2) {
	return !(r1 > r2);
}
bool operator>=(const Rational& r1, const Rational& r2) {
	return !(r1 < r2);
}

Rational operator-(const Rational& r) {
	return Rational(-r.numerator(), r.denominator());
}
Rational operator+(const Rational& r1, const Rational& r2) {
	return Rational(r1.numerator() * r2.denominator() + r2.numerator() * r1.denominator(), r1.denominator() * r2.denominator());
}
Rational operator-(const Rational& r1, const Rational& r2) {
	return Rational(r1.numerator() * r2.denominator() - r2.numerator() * r1.denominator(), r1.denominator() * r2.denominator());
}
Rational operator*(const Rational& r1, const Rational& r2) {
	return Rational(r1.numerator() * r2.numerator(), r1.denominator() * r2.denominator());
}
Rational operator/(const Rational& r1, const Rational& r2) {
	return Rational(r1.numerator() * r2.denominator(), r1.denominator() * r2.numerator());
}


int main() {
	Rational r;

	std::cin >> r;

	Rational r1{};
	Rational r2{3};
	Rational r3{2};
	Rational r4{3, 6};
	Rational r5{1, 2};

	std::string sep{std::string(20, '-')};

	std::cout << sep << std::endl;
	std::cout << "r = " << r << std::endl;
	std::cout << "r1 = " << r1 << std::endl;
	std::cout << "r2 = " << r2 << std::endl;
	std::cout << "r3 = " << r3 << std::endl;
	std::cout << "r4 = " << r4 << std::endl;
	std::cout << "r5 = " << r5 << std::endl;
	std::cout << sep << std::endl;
	std::cout << "-r4 = " << -r4 << std::endl;
	std::cout << "r2 + r3 = " << r2 + r3 << std::endl;
	std::cout << "r4 - r5 = " << r4 - r5 << std::endl;
	std::cout << "r2 * r5 = " << r2 * r5 << std::endl;
	std::cout << "r3 / r4 = " << r3 / r4 << std::endl;
	std::cout << sep << std::endl;
	std::cout << "r = " << r << std::endl;
	std::cout << "r1 = " << r1 << std::endl;
	std::cout << "r2 = " << r2 << std::endl;
	std::cout << "r3 = " << r3 << std::endl;
	std::cout << "r4 = " << r4 << std::endl;
	std::cout << "r5 = " << r5 << std::endl;
	std::cout << sep << std::endl;

	return 0;
}


#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>


class Rational {
	public:
		using Integer = int;
		using Natural = unsigned int;
	
	private:
		Integer num;
		Natural denom;
	
	public:
		Rational();
		Rational(Integer num);
		Rational(Integer num, Natural denom);

		Integer numerator() const;
		Natural denominator() const;

		Rational recip() const;
	
	private:
		void reduce();
	
	public:
		Rational& operator+=(const Rational&);
		Rational& operator-=(const Rational&);
		Rational& operator*=(const Rational&);
		Rational& operator/=(const Rational&);
};

std::ostream& operator<<(std::ostream&, const Rational&);
std::istream& operator>>(std::istream&, Rational&);

bool operator==(const Rational&, const Rational&);
bool operator!=(const Rational&, const Rational&);
bool operator<(const Rational&, const Rational&);
bool operator>(const Rational&, const Rational&);
bool operator<=(const Rational&, const Rational&);
bool operator>=(const Rational&, const Rational&);

Rational operator-(const Rational&);
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

#endif // RATIONAL_HPP

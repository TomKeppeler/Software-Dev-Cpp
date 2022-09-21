#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>


class Complex {
	public:
		using Real = int;
	
	private:
		Real real_;
		Real imag_;
	
	public:
		Complex();
		Complex(Real real);
		Complex(Real real, Real imag);

		Real real() const;
		Real imag() const;

		Complex conj() const;
	
	public:
		Complex& operator+=(const Complex&);
		Complex& operator-=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator/=(const Complex&);
};

std::ostream& operator<<(std::ostream&, const Complex&);
std::istream& operator>>(std::istream&, Complex&);

Complex operator-(const Complex&);
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);

#endif // COMPLEX_HPP

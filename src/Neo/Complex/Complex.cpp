#include "Complex.hpp"


Complex::Complex() : Complex(0, 0) {}
Complex::Complex(Real real) : Complex(real, 0) {}
Complex::Complex(Real real, Real imag) : real_{real}, imag_{imag} {}

Complex::Real Complex::real() const {
	return real_;
}
Complex::Real Complex::imag() const {
	return imag_;
}

Complex Complex::conj() const {
	return Complex(real_, -imag_);
}

Complex& Complex::operator+=(const Complex& c) {
	*this = *this + c;
	return *this;
}
Complex& Complex::operator-=(const Complex& c) {
	*this = *this - c;
	return *this;
}
Complex& Complex::operator*=(const Complex& c) {
	*this = *this * c;
	return *this;
}
Complex& Complex::operator/=(const Complex& c) {
	*this = *this / c;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
	return out << c.real() << "+i" << c.imag();
}
std::istream& operator>>(std::istream& in, Complex& c) {
	Complex::Real real;
	Complex::Real imag;

	std::istream& result{in >> real >> imag};

	c = Complex(real, imag);

	return result;
}

Complex operator-(const Complex& c) {
	return Complex(-c.real(), c.imag());
}
Complex operator+(const Complex& c1, const Complex& c2) {
	return Complex(c1.real() + c2.real(), c1.imag() + c2.imag());
}
Complex operator-(const Complex& c1, const Complex& c2) {
	return Complex(c1.real() - c2.real(), c1.imag() - c2.imag());
}
Complex operator*(const Complex& c1, const Complex& c2) {
	Complex::Real real{c1.real() * c2.real() - c1.imag() * c2.imag()};
	Complex::Real imag{c1.real() * c2.imag() + c1.imag() * c2.real()};

	return Complex(real, imag);
}
Complex operator/(const Complex& c1, const Complex& c2) {
	Complex::Real real{c1.real() * c2.real() + c1.imag() * c2.imag()};
	Complex::Real imag{c1.real() * c2.imag() - c1.imag() * c2.real()};
	Complex::Real tmp{};

	return Complex(real / tmp, imag / tmp);
}

int main() {
	return 0;
}

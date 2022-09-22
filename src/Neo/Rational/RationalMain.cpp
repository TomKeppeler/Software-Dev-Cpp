#include "Rational.hpp"

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
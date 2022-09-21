#include "Rational.hh"

int static const SIZE = 10;

int main() {
    Rational *r = new Rational[SIZE];
    std::string ret = "";
    for (int i = 0; i < SIZE; i++) {
        r[i] = Rational{2*i+1, 2*i+5};
        ret += r[i].numer() + "/" + r[i].denom();
    }

    std::cout << ret << std::endl;
    delete r;
    return 0; 
}
#include "Rational.hh"
#include <ostream>

namespace linalge {

    
    int gcd(int a, int b){
        if(a < b) {
            return gcd(b, a);
        }
        if (a == 0) {
            return b;
        }
        return gcd(b, a%b);
    }
}
#include <iostream>
#include <cmath>
class pi_number{

public:
    float a;

    pi_number(float a = 0): a(a){};
    ~pi_number() = default;

    pi_number operator*(const pi_number &n) const{
        pi_number p;
        float d = a*M_PI;
        p.a = d;
        return p;
    }

    friend std::ostream &operator <<(std::ostream &out, const pi_number &num){
        out << num.a << " ";
        return out;
    }

};


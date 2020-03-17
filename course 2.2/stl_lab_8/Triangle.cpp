#include <iostream>
#include "Shape.h"

class Triangle : public Shape {

public:

    Triangle(int x_, int y_) {
        x = x_;
        y = y_;
    }

    void Draw() {
        std::cout << "I'm a Triangle " << "( " << x << " ; " << y << " )" << std::endl;
    }

};

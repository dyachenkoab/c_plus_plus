#include <iostream>
#include "Shape.h"

class Circle : public Shape {

public:

    Circle(int x_, int y_) {
        x = x_;
        y = y_;
    }

    void Draw() {
        std::cout << "I'm a Circle "<< "( " << x << " ; " << y << " )"<< std::endl;
    }

};

#include <iostream>
#include "Shape.h"

class Square : public Shape {

public:

    Square(int x_, int y_) {
        x = x_;
        y = y_;
    }

    void Draw(){
        std::cout << "I'm a Square " << "( " << x << " ; " << y << " )" << std::endl;
    }

};

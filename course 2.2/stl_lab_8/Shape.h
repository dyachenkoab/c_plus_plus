
#ifndef N_LAB8_SHAPE_H
#define N_LAB8_SHAPE_H

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

class Shape {
protected:

    int x = 0;
    int y = 0;

public:

    void IsMoreLeft(Shape s);

    void IsUpper(Shape s);

    virtual void Draw();

    ~Shape() = default;

    void print_Draw(std::list<Shape *> l);

    void sort_from_right_to_left(std::list<Shape *> &l);

    void sort_from_left_to_right(std::list<Shape *> &l);

    void sort_vec(std::vector<Shape> &l);

    void sort_from_upper_to_lower(std::list<Shape *> &l);

    void sort_from_lower_to_upper(std::list<Shape *> &l);

    friend std::ostream &operator<<(std::ostream &out, Shape &p) {
        out << p.x << " ; " << p.y << std::endl;
        return out;
    }

//    Shape() = default;
    Shape(int x = 0, int y = 0) : x(x), y(y) {};

    Shape(const Shape &s) = default;
//---------------------------------------------------------------------
/*
    Shape operator=(const Shape &s) {
        x = s.x;
        y = s.y;
        return *this;
    }
    bool operator!=(const Shape &s) {
        return x != s.x;
    }

    bool operator<(const Shape &s) const {
        return (x > s.x);
    }



   friend bool operator>(const Shape &s, const Shape &p) {
        return (p.x > s.x);
    }
    friend bool operator<(const Shape &s, const Shape &p) {
        return (p.x < s.x);
    }
*/

    bool operator>(const Shape &s) const {
        return (x > s.x);
    }

    Shape operator*(const Shape &s) const {
        Shape sh;
        int i = x * 3;
        sh.x = i;
        sh.y = s.y;
        return sh;
    }


};

#endif //N_LAB8_SHAPE_H

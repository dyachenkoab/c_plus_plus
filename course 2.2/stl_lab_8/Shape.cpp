#include <iostream>
#include <vector>
#include "Shape.h"

void Shape::IsMoreLeft(Shape s) {

    if (this->x < s.x) {
        std::cout << "left";
    } else if (this->x == s.x) {
        std::cout << "matches";
    } else std::cout << "right";

    std::cout << '\n';
}

void Shape::IsUpper(Shape s) {

    if (this->y < s.y) {
        std::cout << "lower";
    } else if (this->y == s.y) {
        std::cout << "matches";
    } else std::cout << "higher";

    std::cout << '\n';
}

void Shape::Draw() {
    std::cout << "I'm a Shape" << std::endl;
}

void Shape::print_Draw(std::list<Shape *> l) {

    for_each(l.begin(), l.end(), [](Shape *p) { return p->Draw(); });
    std::cout << '\n';
}

void Shape::sort_from_right_to_left(std::list<Shape *> &l) {

/*
    std::vector<Shape*> vs ;
    std::move(l.begin(), l.end(), std::back_inserter(vs));
//    std::cout << *vs[0];

    auto ds = std::ref(vs);

//    std::vector<std::reference_wrapper<Shape*>> ds = {vs.begin(), vs.end()};

    for (auto x : ds.get()){
        std::cout << *x << " ";
    }
    std::cout << '\n';
//    std::cout << ds.get().size() <<'\n';


    std::sort(ds.get().begin(), ds.get().end());
//    std::random_shuffle(ds.get().begin(), ds.get().end());

    for (auto x : ds.get()){
        std::cout << *x << " ";
    }
//     std::vector<std::reference_wrapper<Shape*>> vs(l.begin(), l.end());
//     std::cout << vs[0];

//    sort(vs.begin(), vs.end());
*/
    std::cout << "-------- sort_from_right_to_left --------" << '\n';

    l.sort([](Shape *p, Shape *v) { return v->x < p->x; });

    for_each(l.begin(), l.end(), [](Shape *p) { return p->Draw(); });
    std::cout << '\n';
}

void Shape::sort_vec(std::vector<Shape> &l) {

    std::sort(l.begin(), l.end(), std::greater<Shape>());

    std::transform(l.begin(), l.end(), l.begin(), l.begin(), std::multiplies<Shape>());

    for (auto x : l) {
        std::cout << x << " ";
    }
}

void Shape::sort_from_left_to_right(std::list<Shape *> &l) {

    std::cout << "-------- sort_from_left_to_right --------" << '\n';

    l.sort([](Shape *p, Shape *v) { return v->x > p->x; });

    for_each(l.begin(), l.end(), [](Shape *p) { return p->Draw(); });
    std::cout << '\n';
}

void Shape::sort_from_lower_to_upper(std::list<Shape *> &l) {

    std::cout << "-------- sort_from_lower_to_upper --------" << '\n';

    l.sort([](Shape *p, Shape *v) { return v->y > p->y; });

    for_each(l.begin(), l.end(), [](Shape *p) { return p->Draw(); });
    std::cout << '\n';
}

void Shape::sort_from_upper_to_lower(std::list<Shape *> &l) {

    std::cout << "-------- sort_from_upper_to_lower --------" << '\n';

    l.sort([](Shape *p, Shape *v) { return v->y < p->y; });

    for_each(l.begin(), l.end(), [](Shape *p) { return p->Draw(); });
    std::cout << '\n';
}


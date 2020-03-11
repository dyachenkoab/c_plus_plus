typedef struct Point Point;
typedef struct Shape Shape;

#include <iostream>
#include <vector>

struct Shape {
    Shape() : sum(0) {}

    void operator()(Shape s) { sum += s.vertex_num; }

    int sum;
    int vertex_num;

    std::vector<Point> vertexes;

    friend std::ostream &operator<<(std::ostream &out, const Shape &sh){
        out << sh.vertex_num << " ";
        return out;
    }
};

struct Point {
    int x;
    int y;

};

struct count_shapes {

    /* считаем объекты по количеству вершин */

    count_shapes(const int &s) : number(s) {}

    bool operator()(const Shape &shape) const {
        return shape.vertex_num == number;
    }

    int number;
};

struct count_squares {

    /* сравниваем длины сторон */

    count_squares() = default;

    bool operator()(const Shape &shape) const {
        return ((shape.vertexes[2].x - shape.vertexes[1].x) == (shape.vertexes[1].y - shape.vertexes[0].y) &&\
        (shape.vertexes[3].x - shape.vertexes[1].x) == (shape.vertexes[3].y - shape.vertexes[2].y));
    }
};



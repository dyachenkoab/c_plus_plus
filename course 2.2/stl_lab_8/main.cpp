/*
*    1. Разработать программу, которая, используя только стандартные алгоритмы и функторы, умножает каждый элемент
*    списка чисел с плавающей  точкой на число PI
*
*    2. Разработать программу, которая:
*        a. Реализует иерархию геометрических фигур состоящую из:
*            i. Класс Shape.
*                1. Содержит информацию о положении центра фигуры (координаты x и y).
*                2. Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее
*                (определяется по положению центра) чем фигура переданная в качестве аргумента
*                3. Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше
*                (определяется по положению центра) чем фигура переданная в качестве аргумента
*                4. Определяет чисто виртаульную функцию рисования Draw (каждая фигура в реализации этой функци
*                должна выводить на стандартный вывод свое название и положение центра)
*            ii. Класс Circle производный от класса Shape
*                1. Реализует Draw
*            iii. Класс Triangle производный от класса Shape
*                1. Реализует Draw
*            iv. Класс Square производный от класса Shape
*                1. Реализует Draw
*
*        b. Содержит список list<Shape*>, заполенный указателями на различные фигуры
*
*        c. С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры
*
*        d. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева-направо
*        (имется в виду, что в начале списка должны идти фигуры находящиеся левее, координата x )
*        и выводит фигуры (Draw)
*
*        e. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа-налево
*        и выводит фигуры
*
*        f. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху-вниз
*        и выводит фигуры
*
*        g. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу-вверх
*        и выводит фигуры
*/

#include <list>
#include "Shape.h"
#include "pi_number.cpp"
#include "Square.cpp"
#include "Triangle.cpp"
#include "Circle.cpp"

using namespace std;

int main() {

    Shape shape;

/*
    Square *s = new Square(1, 2);
    Triangle *t = new Triangle(5,5);
    Circle *c = new Circle(2,3);
    Square *sq = new Square(6, 4);
    Triangle *tr = new Triangle(3,6);
    Circle *ci = new Circle(4,1);

    list<Shape*> l = {s, t, c, sq, tr, ci};
*/
    list<Shape *> l = {
            new Square(1, 2),
            new Triangle(5, 5),
            new Circle(2, 3),
            new Square(6, 4),
            new Triangle(3, 6),
            new Circle(4, 1),
    };

    shape.print_Draw(l);

    shape.sort_from_right_to_left(l);
    shape.sort_from_left_to_right(l);
    shape.sort_from_upper_to_lower(l);
    shape.sort_from_lower_to_upper(l);

    Square *s = new Square(1, 2);
    Triangle *t = new Triangle(5, 5);
    Circle *c = new Circle(2, 3);

    s->IsMoreLeft(*c);
    s->IsUpper(*t);

/*
    Square squ(1,3);
    Triangle tri(3,5);
    Circle cir(6,2);

    vector<Shape> vs = {squ, tri, cir};
    shape.sort_vec(vs);
*/

//----------------------power pi--------------------------
    vector<pi_number> vf{
            pi_number(1.3),
            pi_number(9.4),
            pi_number(5.5)
    };

//    transform(vf.begin(), vf.end(), vf.begin(), [](pi_number i){return i.a*3.14;});
    transform(vf.begin(), vf.end(), vf.begin(), vf.begin(), multiplies<pi_number>());

    cout << '\n' << "--------- power pi ---------" << '\n';
    for (auto x : vf) {
        cout << x << " ";
    }


    return 0;
}
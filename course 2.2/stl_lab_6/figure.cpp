/*
    2. Написать программу, которая выполняет следующие действия (все операции должны выполняться с помощью
    стандартных алгоритмов):
        a. Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником, квадратом,
        прямоугольником или пятиугольником. Структура описывающая геометрическую фигуру  определена ниже,
        b. Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник добавляет к общему
        числу 3, квадрат 4 и т.д.)
        c. Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
        d. Удаляет все пятиугольники
        e. На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой)
        каждой фигуры, т.е. первый элемент этого вектора содержит координаты одной из вершин первой фигуры,
        второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
        f. Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом
        прямоугольники.
        g. Распечатывает вектор после каждого этапа работы

        Геометрическая фигура задается следующей структурой:

        typedef  struct
        {
            int vertex_num;             // количество вершин, для треугольника 3, для квадрата и
                                        // прямоугольника 4, для пятиугольника 5
            vector<Point> vertexes;     // вектор содержащий координаты вершин фигуры
                                        // Для треугольника содержит 3 элемента
         				                // Для квадрата и прямоугольника содержит 4
                                        // элемента
                                        // Для пятиугольника 5 элементов
        } Shape;
        -------------------------------------------------
        typedef struct
        {
            int x,y;

        } Point;

 */
#include "structs.cpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

class Figure {

    void fill_points(vector<Point> &point_vec, int i) {

        /*
         * заполняем точки по количеству вершин.
         * квадрат или прямоугольник - решает случай
        */

        for (int j = 0; j < i; ++j) {
            if (i == 4) {
                int square_or_rectangle = rand() % 2;
                if (square_or_rectangle) {
                    make_square(point_vec);
                } else {
                    make_rectangle(point_vec);
                }
                break;
            } // if
            Point point;
            int points = rand_1_10();
            point.x = points;

            points = rand_1_10();
            point.y = points;

            point_vec.push_back(point);
        }
    }

    void make_square(vector<Point> &vp) {

        /*
         * вычисляем размер стороны квадрата, и первой точки. Создаём массивы смежных точек.
         * Поочерёдно записываем точки в структуру так, чтобы получить квадрат
         * в декартовой системе координат
        */

        int side = rand_1_10();

        int x1 = rand_1_10();
        int y1 = rand_1_10();

        int mas_x[] = {x1, x1 + side};
        int mas_y[] = {y1, y1 + side};

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                Point p;
                p.x = mas_x[i];
                p.y = mas_y[j];
                vp.push_back(p);
            }
        }
    }

    void make_rectangle(vector<Point> &vp) {

        /*
         * вычисляем размер сторон прямоугольника и если они не равны, создаём массивы смежных точек.
         * Поочерёдно записываем точки в структуру так, чтобы получить прямоугольник
         * в декартовой системе координат
        */

        while (true) {
            int side1 = rand_1_10();
            int side2 = rand_1_10();

            if (side1 != side2) {
                int x1 = rand_1_10();
                int y1 = rand_1_10();

                int mas_x[] = {x1, x1 + side1};
                int mas_y[] = {y1, y1 + side2};

                for (int i = 0; i < 2; ++i) {
                    for (int j = 0; j < 2; ++j) {
                        Point p;
                        p.x = mas_x[i];
                        p.y = mas_y[j];
                        vp.push_back(p);
                    }
                }
                break;
            }
        }
    }

    int rand_1_10() {
        return (rand() % 10 + 1);
    }

public:

    void fill_Shapes(vector<Shape> &shape_vec) {
        for (int j = 0; j < 10; ++j) {
            Shape shape;
            int i = 3 + rand() % 3; // решаем, кто следующий с вершинами от 3х, до 5ти

            shape.vertex_num = i;
            fill_points(shape.vertexes, i);

            shape_vec.push_back(shape);
        }

        for_each(shape_vec.begin(), shape_vec.end(), [](Shape n) { std::cout << n.vertex_num << " "; });
        cout << endl;
    }

    void points_number(const vector<Shape> &vs) {

                     /*суммирует вершины через конструктор*/

        Shape sh = for_each(vs.begin(), vs.end(), Shape());
        cout << "points number: " << sh.sum << endl;

    }

    void shapes_number(const vector<Shape> &vs) {

        int triangles = count_if(vs.begin(), vs.end(), count_shapes(3));
        cout << "triangles: " << triangles << endl;

        int square = count_if(vs.begin(), vs.end(), count_squares());
        cout << "square: " << square << endl;

        int rectangle = count_if(vs.begin(), vs.end(), count_shapes(4));
        cout << "rectangle: " << rectangle - square << endl;

        int pentagon = count_if(vs.begin(), vs.end(), count_shapes(5));
        cout << "pentagon: " << pentagon << endl;

    }

    void remove_pentagon(vector<Shape> &vs) {

        vs.erase(remove_if(vs.begin(), vs.end(), count_shapes(5)), vs.end());

        cout << "without pentagons: ";
        for (Shape x : vs) {
            cout << x;
        }
        cout << endl;
    }

    void make_new_vector(const vector<Shape> &vs) {

        vector<Point> vp;

               /* возвращает первую структуру точек на каждой итерации и записывает в новый вектор */

        transform(vs.begin(), vs.end(), back_inserter(vp),
                  [](auto const &vs) { return vs.vertexes[0]; });

        for_each(vp.begin(), vp.end(), [](Point p) { cout << "(" << p.x << " ; " << p.y << ")" << endl; });
    }

    void make_partition(vector<Shape> &vs) {

         /* меняет положение элементов в соответствии с предикатом, возвращает итератор на следующий элемент */

        auto part = partition(vs.begin(), vs.end(), count_shapes(3));
        auto part_1 = partition(part, vs.end(), count_squares());

        for (Shape x : vs) {
            cout << x;
        }
        cout << endl;
    }

};



/*
*       Строка Строка для для проверки проверки
*
*    1. Написать программу, которая выполняет следующие действия:
*        a. Читает содержимое текстового файла
*        b. Выделяет слова, словом считаются последовательность символов разделенных пробелами и/или знаками табуляции
*        и/или символами новой строки
*        c. Вывести список слов присутствующий в тексте без повторений (имеется в виду, что одно и то же слово может
*        присутствовать в списке только один раз)
*/
#include "figure.cpp"
#include "unrepetable.cpp"

using namespace std;

int main() {
    srand(time(NULL));

    {
       unrepetable ur;
       ur.show_unrepetable_strings();
    }

/*    {
        vector<Shape> sh;
        Figure figure;

        figure.fill_Shapes(sh);
        figure.points_number(sh);
        figure.shapes_number(sh);
        figure.make_new_vector(sh);
        figure.make_partition(sh);
        figure.remove_pentagon(sh);

    }*/

    return 0;
}



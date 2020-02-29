/* 1. Реализовать очередь с приоритетом по заданому интерфейсу.
  В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета (low, normal, high)

 Элементы из очереди извлекаются в соответствии с их приоритетами (сначала извлекаются элементы с приоритетом high, потом normal, потом low),
 элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления.

В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают свой приоритет
 до high и «обгоняют» элементы с приоритетом normal.

    2. Разработайте программу, которая
        a. Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений
        (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
        b. Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент,
        предпоследний элемент, третий элемент и т.д.
        Например если список содержит:
        1 2 3 4 5 6 7 8
        то вывод будет иметь вид
        1 8 2 7 3 6 4 5
 */
#include "priority.cpp"

using namespace std;

void vec_fill(list<int> &lst);

int recurs(list<int>::iterator lst_begin, list<int>::iterator lst_end);

int main() {
//    srand((unsigned) time(nullptr));
/*
    list<int> lst;
    list<int>::iterator ls, ls2(ls);


    vec_fill(lst);
    for (int l : lst) {
        cout << l << " ";

    }
    cout << endl;

    ls = lst.begin();
    ls2 = lst.end();
    recurs(ls, --ls2);
*/

    QueueWithPriority le;
    QueueElement al = {"high1"};
    QueueElement bl = {"low1"};
    QueueElement cl = {"norm1"};
    QueueElement dl = {"high2"};
    QueueElement el = {"norm2"};
    QueueElement fl = {"low2"};
    QueueElement il = {"low3"};
    QueueElement jl = {"norm3"};
    QueueElement kl = {"high3"};
    le.PutElementToQueue(al, HIGH);
    le.PutElementToQueue(bl, LOW);
    le.PutElementToQueue(cl, NORMAL);
    le.PutElementToQueue(dl, HIGH);
    le.PutElementToQueue(el, NORMAL);
    le.PutElementToQueue(fl, LOW);
    le.PutElementToQueue(il, LOW);
    le.PutElementToQueue(jl, NORMAL);
    le.PutElementToQueue(kl, HIGH);

    le.print();

    le.Accelerate();

    le.print();

    auto i = le.GetElementFromQueue();
    cout << i.name;
    return 0;
}

void vec_fill(list<int> &lst) {
    for (int i = 0; i < 14; i++) {
        lst.push_back(rand() % 20);
    }
}

int recurs(list<int>::iterator lst_begin, list<int>::iterator lst_end) {
    if (lst_begin != lst_end) {
        if (distance(lst_begin, lst_end) == 1) {
            cout << *lst_begin << " ";
            cout << *lst_end;
            return 0;
        }
        cout << *lst_begin << " ";
        cout << *lst_end << " ";
        return recurs(++lst_begin, --lst_end);
    } else {
        cout << *lst_begin;
        return 0;
    }
}
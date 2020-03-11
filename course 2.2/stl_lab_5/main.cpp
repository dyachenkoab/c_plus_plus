/*      Написать программу, которая выполняет следующие действия:
        a. Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным
        образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк,
        индекс строки генерируется случайным образом)
        b. Выводит полученный вектор на печать
        c. Сортирует вектор следующим образом:
            i. По возрастанию key1
            ii. Если key1 одинаковые, то по возрастанию key2
            iii. Если key1 и key2 одинаковые, то по возрастанию длинны строки str
        d. Выводит полученный вектор на печать

        DataStruct определена следующим образом:
        typedef struct
        {
        int       key1;
        int       key2;
        string    str;
        } DataStruct;
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int key1;
    int key2;
    string str;
} DataStruct;

DataStruct fill();

bool compare(DataStruct a, DataStruct b);

void print(vector<DataStruct> ds);

ostream &operator<<(ostream &out, DataStruct &dt);

vector<string> s = {"un", "due", "tree", "quattro", "chinquee", "sei", "sette", "otto", "nove", "diechi"};

int main() {
    srand(time(nullptr));
    auto ds = new vector<DataStruct>;

    for (int i = 0; i < 10; ++i) {
        ds->push_back(fill());
    }

    print(*ds);
    cout << endl;

    vector<DataStruct>::iterator it, it2;
    it = ds->begin();
    it2 = ds->end();

    sort(it, it2, compare);

    print(*ds);

    delete ds;

    return 0;
}

DataStruct fill() {
    auto d = new DataStruct();
    int i = rand() % 10;

    d->key1 = rand() % 11 + (-5);
    d->key2 = rand() % 11 + (-5);
    d->str = s.at(i);

    return *d;
}

ostream &operator<<(ostream &out, DataStruct &dt) {
    out << "key1 :" << dt.key1 << ", key2: " << dt.key2 << ", str: " << dt.str << endl;
    return out;
}


bool compare(DataStruct a, DataStruct b) {
    if ((a.key1 == b.key1) && (a.key2 == b.key2)) {
        return (a.str > b.str);
    } else if (a.key1 == b.key1) {
        return a.key2 < b.key2;
    }
    return a.key1 < b.key1;
}

void print(vector<DataStruct> ds) {
    for (DataStruct d : ds) {
        cout << d;
    }
}

#include <unordered_set>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iterator>
using namespace std;

class unrepetable {

    string filename = "/home/podkyr/CLionProjects/n_lab6/main.cpp";

    void file_reader(char *buff, int len) {

        ifstream fin;
        fin.open(filename, ios::in);
        if (fin) {
            for (int j = 0; j < len; ++j) {
                buff[j] = fin.get();
            }
        }
    }

    int size() {

        /* вычисляем размер файла */

        ifstream fin;
        fin.open(filename, ios::in);
        int len = 0;
        if (fin) {
            fin.seekg(0, fin.end);
            len = fin.tellg();
        }
        return len;
    }

public:

    void show_unrepetable_strings() {

       /* уникальность обеспечивается неупорядоченым множеством, делим по пробелам с помощью strtok */

        unordered_set<string> set_of_str;
        int i = size();
        char s[i];

        if (i > 0) {
            file_reader(s, i);
            char *d = strtok(s, " \n\v\f\r\t");
            while (d) {
                set_of_str.insert(d);
                d = strtok(NULL, " \n\v\f\r\t");
            }
        }

        copy(set_of_str.begin(), set_of_str.end(), ostream_iterator<string>(cout, "\n"));
    }
};
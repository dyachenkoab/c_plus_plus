/*Разработать программу, которая должна сделать следующее:
    1. Прочитать содержимое текстового файла. Файл может содержать:
        a. Слова – состоят из латинских строчных и заглавных букв, а также цифр, длинна слова должна быть не более 20 символов
        b. Знаки препинания – «.», «,» «!» «?» «:» «;»
        c. Пробельные символы – пробел, табуляция, символ новой строки.

    2. Отформатировать текст следующим образом:
        a. Не должно быть  пробельных символов отличных от пробела
        b. Не должно идти подряд более одного пробела
        c. Между словом и знаком препинания не должно быть пробела
        d. После знака препинания всегда должен идти пробел
        e. Слова длиной более 10 символов заменяются на слово «Vau!!!»

    3. Преобразовать полученный текст в набор строка, каждая из которых содержит целое количество строк (слово должно 
    целиком находиться в строке) и ее длинна не превышает 40 символов.*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void from_file_to_vec(string &s);

void separate_punct(string &s);

void change_symb_to_space(string &s);

string remove_extra_spaces(string &s);

void change_long_words(string &s);

void separate_to_tokens(string &s, vector<string> &v_s);

int main() {

    vector<string> v_string;
    string s = "";
    from_file_to_vec(s);
    separate_punct(s);
    change_symb_to_space(s);
    s = remove_extra_spaces(s);
    change_long_words(s);
    separate_to_tokens(s, v_string);

    for (string str : v_string) {
        cout << str << endl;
    }

    return 0;
}

void from_file_to_vec(string &s) {
    ifstream fin;                                       
    fin.open("/home/podkyr/file.txt", ios::in);      
    int len = 0;
    if (fin) {

        fin.seekg(0, fin.end);                              
        len = fin.tellg();
        fin.seekg(0, fin.beg);

        char buff[len];

        fin.read(buff, len);                               

        s.append(buff, len);
    }
}

void separate_punct(string &s) {
    int i = 0;
    int j = 1;

    for (i; i < s.size(); ++i, ++j) {                      // отделяем пунктуацию от букв .first -> . first
        if (ispunct(s.at(i)) && isgraph(s.at(j))) {
            if (s.at(i) == '-') continue;
            s.insert(j, " ");
        }
    }
}

void change_symb_to_space(string &s) {
    int i = 0;
    int j = 1;
    if (iscntrl(s.at(0))) { s.replace(0, 1, " "); }

    for (i, j; j < s.size(); ++i, ++j) {                                  // меняем отдельно стоящие символы на
        if (iscntrl(s.at(j)) || isspace(s.at(i)) && ispunct(s.at(j))) {   // пробелы
            s.replace(j, 1, " ");
        }

    }
}

string remove_extra_spaces(string &s) {
    string snew = "";                                       //удаляем лишние пробелы
    string::iterator it, it_next, it_end;
    it = s.begin();
    it_next = s.begin() + 1;
    it_end = s.end();

    for (it; it < it_end - 1; ++it, ++it_next) {
        if (((*it == ' ') && (*it_next == ' '))) {
            continue;
        }
        snew.push_back(*it);
    }
    return snew;
}

void change_long_words(string &s) {
    string::iterator it, it_next, it_end;
    it = s.begin();
    it_next = s.begin();                                //заменяем слова >10ти букв
    it_end = s.end();
    string word_to_change = "Vau!!!";

    for (it_next; it < it_end;) {
        if ((it_next - it) > 10) {
            s.replace(it, it_next, word_to_change);
            it += word_to_change.size();
        }
        if (!isalpha(*it)) {
            it++;
            it_next = it;
        }
        while (!isalpha(*it_next)) {
            it_next++;
            it = it_next;
            if (it_next == it_end) { break; }
        }
        while (*it_next == '-' || isalpha(*it_next)) {
            it_next++;
        }
    }
}

void separate_to_tokens(string &s, vector<string> &v_s) {       //разбиваем на строки до 40 символов

    int j = 0;
    for (int i = 40; i < s.size(); i += 40) {
        while (!isspace(s.at(i))) {
            i--;
        }
        v_s.push_back(s.substr(j, i - j));
        j = i + 1;
    }
}

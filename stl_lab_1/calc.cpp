#include "calc.h"

void calc::vec_fill(vector<int> &vec, int num){
    for(int i = 0; i < num; i++){
        vec.push_back(rand()%30);
    }
}

//------------------------------------------------------------
void calc::bsort_at(vector<int> &vec) {
    if (vec.size() > 1) {
        int x = 0;
        for (int i = 0; i < vec.size() - 2; i++) {
            for (int j = 0; j < vec.size() - 1; j++) {
                if (vec.at(j) > vec.at(j + 1)) {
                    x = vec.at(j);
                    vec.at(j) = vec.at(j + 1);
                    vec.at(j + 1) = x;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void calc::bsort_it(vector<int> &vec) {
    vector<int>::iterator it_begin, it_begin2;
    int temp = 0;
    if (vec.size() > 1) {
        it_begin = vec.begin();


        for (it_begin; it_begin < vec.end() - 2; it_begin++) {
            for (it_begin2 = vec.end() - 1; it_begin < it_begin2; it_begin2--) {
                if (*it_begin > *it_begin2) {
                    temp = *it_begin;
                    *it_begin = *it_begin2;
                    *it_begin2 = temp;
                }
            }
        }
    }
}

//-----------------------------------------------------
void calc::from_file_to_vec(vector<string> &s_vec) {
    ifstream fin;                                       //открываем поток
    fin.open("/home/podkyr/file.txt", ios::in);      //поток будет закрыт при отработке функции

    if (fin) {
        fin.seekg(0, fin.end);                              //определяем длину
        int len = fin.tellg();
        fin.seekg(0, fin.beg);

        char buff[len];

        fin.read(buff, len);                                //считываем
        s_vec.assign(1, buff);
    }                      //добавляем в вектор
    printvec(s_vec);
}

//---------------------------------------------------
void calc::delOdd_addOne(vector<int> &vec) {
    vector<int>::iterator it;
    int n;

    cout << "Введите целые числа, 0 - конец ввода: " << endl;
    while (true) {
        cin >> n;
        if (!n || isalpha(n)) break;
        vec.push_back(n);
    }

    if (vec.back() == 1) {
        for (it = vec.begin(); it < vec.end(); it++) {
            if (((*it) % 2) == 0) {
                vec.erase(it);
            }
        }
    } else if (vec.back() == 2) {
        for (int i = 0; i < vec.size(); i++) {
            if ((vec[i] % 3) == 0) {
                it = vec.begin();
                vec.insert(it + i + 1, 3, 1);
            }
        }
    }
    //printvec(vec);
}

//------------------------------------------------------
void calc::fillRandom(double *array, int size) {
    /*default_random_engine ran{ } ;
    uniform_real_distribution<>
            ureal{-1,1};
    for (int i = 0; i < size; i++) {
        array[i] = (ureal(ran));
    }*/

    for (int i = 0; i < size; i++) {
        array[i] = (double) rand() / RAND_MAX * (1.0 - (-1.0)) + (-1.0);
    }


}

void calc::check_d_vec(int size) {
    if (size > 0) {
        vector<double> d_vec(size, 0);
        fillRandom(&d_vec[0], size);

        printvec(d_vec);
        bsort_brace(d_vec);
        printvec(d_vec);

    } else {
        cout << "Размер меньше 1" << endl;
    }
}

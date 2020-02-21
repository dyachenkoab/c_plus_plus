#ifndef N_LAB1_1_CALC_H
#define N_LAB1_1_CALC_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <random>

using namespace std;

class calc {
    int size;
    vector<int> vec;
    vector<string> s_vec;
public:
//    calc(vector<int> ivec, int size, vector<string> s_vec){
//        this.ivec(0,0);
//    }
    void vec_fill(vector<int> &vec, int num);

    void bsort_at(vector<int> &vec);

    void bsort_it(vector<int> &vec);

    void from_file_to_vec(vector<string> &s_vec);

    void delOdd_addOne(vector<int> &vec);

    void fillRandom(double *array, int size);

    void check_d_vec(int size);
    template<typename T>
    void printvec(vector<T> &vec) {
        for (T it : vec) {
            cout << it << " ";
        }
        cout << endl;
    }

    template<typename T>
    void bsort_brace(vector<T> &vec) {
        T x = 0;
        if (vec.size() > 1) {
            for (int i = 0; i < vec.size() - 2; i++) {
                for (int j = 0; j < vec.size() - 1; j++) {
                    if (vec[j] > vec[j + 1]) {
                        x = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = x;
                    }
                }
            }
        } else {
            cout << "Размер меньше 2 " << endl;
        }
    }
};


#endif //N_LAB1_1_CALC_H

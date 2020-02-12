#include "calc.h"


int main() {
    srand((unsigned) time(nullptr));
    vector<int> ivec;
    int size = 25;
    vector<int> vec;
    vector<string> s_vec;
    calc cl;
 //       cl.check_d_vec(7);
    /*cl.check_d_vec(10);
    cl.check_d_vec(15);
    cl.check_d_vec(25);
    cl.check_d_vec(50);
    cl.check_d_vec(100);*/
//    vector<int> ivec;
 //   cl.vec_fill(vec, size);
//    printvec(vec);
 //   cl.bsort_brace(vec);
  //  cl.printvec(vec);
    cl.from_file_to_vec(s_vec);
    cout << s_vec[0];
//    cl.delOdd_addOne(vec);


    return 0;
}


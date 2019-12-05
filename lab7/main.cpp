#include "train.cpp"
#include <iostream>
using namespace std;

int main()
{
train train1("21", "Ласточка","","","","sob;sob1;sob2");
//train train2(train1);

train1.set_Info("sob5");
// train1.set_Info("sob1");
// train1.erase();
cout << train1;
//train1.correct_info(1, "");

train1.erase();
cout << train1;
*train1.trainMember("station") = string ("Вокзальная");
cout << train1;
//cout << train2;


    return 0;
}

#include <iostream>
#include "task_m.h"

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    task_m t; // = new task_m();
    t.show();

    return app.exec();
}

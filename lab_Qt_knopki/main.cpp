#include <QApplication>
#include "MyButton.h"


int main(int argc, char** argv)
{

    QApplication app(argc, argv);

    MyButton objbutton("foo1", "foo2", 10, 30, 10, 10, 50);
    objbutton.createbutton();
    objbutton.show();


    return app.exec();
}

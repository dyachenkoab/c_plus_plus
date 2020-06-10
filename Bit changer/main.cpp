#include <QtWidgets>
#include <widget.h>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlApplicationEngine>

/*Составить программу на Qt/QML позволяющую наглядно видеть битовое
* представление некоторого числа и имеющую возможность изменения этого
* числа путем &quot;включения/выключения&quot; битов. Графический интерфейс
* реализовать на QML.
* Условия которые необходимо выполнить:
* 1) Число от 0 до 255;
* 2) Изначально число равно нулю;
* 3) Число в интерфейсе отображается в шестнадцатеричном представлении
* (без префикса '0x'), например число 255 будет иметь вид «FF»;
* 4) Должна быть возможность ввести число вручную (с клавиатуры, в hex-
* представлении);
* 5) При вкл\выкл битов меняется и само число. И наоборот, при изменении
* числа должны меняться биты (собственно сама программа);
* 6) Должна быть возможность добавить к текущему числу сумму чисел из
* текстового файла input.txt (числа в файле от 0 до 100, разделены пробелами и
* переводами строк). При выходе числа за пределы 0-255 оставить только
* младшие биты;
* 7) Сделать кнопку, при нажатии на которую все биты инвертируются, т.е. все
* нули в числе заменяются на единицы, а все единицы на нули;
* 8) Все данные и сложные операции с ними должны храниться в C++ бэкенде;
* 9) Просим вас по возможности не забывать про читаемость и простоту кода и
* адекватность именований функций и переменных.
* */

int main(int argc, char **argv) {

    QGuiApplication app(argc, argv);

    widget toCpp;
    QQuickView *view = new QQuickView();
    view->rootContext()->setContextProperty("widget", &toCpp);
    view->setSource(QUrl::fromLocalFile("src/FileMenu.qml"));

    QQmlEngine *engine = view->engine();
    QObject *fromQml = reinterpret_cast<QObject *>(view->rootObject());

    QObject::connect(fromQml, SIGNAL(sendIndex(int)), &toCpp, SLOT(radioIndex(int)));
    QObject::connect(fromQml, SIGNAL(sendNum(QString)), &toCpp, SLOT(hexInput(QString)));
    QObject::connect(fromQml, SIGNAL(openFile(QString)), &toCpp, SLOT(fileOpen(QString)));
    QObject::connect(fromQml, SIGNAL(invert()), &toCpp, SLOT(invertBits()));
    QObject::connect(engine, &QQmlApplicationEngine::quit, &QGuiApplication::quit);

    view->show();

    return app.exec();


}


#include <QtWidgets>
#include <widget.h>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlApplicationEngine>

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


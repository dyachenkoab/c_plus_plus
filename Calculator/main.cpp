#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "layer.h"

/*
* Написать на языке C библиотеку которая выполняет простейшие функции
* калькулятора (сложение, вычитание, умножение, деление) исходный файл
* должен быть с расширением *.c
* Написать основную программу на языке C++ (можно с применением Qt) которая
* принимает аргументы простейшего выражения (например: a + b), если
* аргументов нет предлагает ввести данные, выполнение операции должно
* выполняться библиотекой написанной ранее
* результат выражения должен записываться в файл с расширение .json
* программа должна собираться cmake (как минимум на Linux)
* 
* Дополнительно: вместо принятия аргуметов, можете написать простое gui с
* использованием qt/qml
*/


int
main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;

  QQmlContext* context = engine.rootContext();

  Layer layer;
  context->setContextProperty("Layer", &layer);

  const QUrl url(QUrl::fromLocalFile("src/Main.qml"));

  QObject::connect(
    &engine,
    &QQmlApplicationEngine::objectCreated,
    &app,
    [url](QObject* obj, const QUrl& objUrl) {
      if (!obj && url == objUrl)
        QCoreApplication::exit(-1);
    },
    Qt::QueuedConnection);

  engine.load(url);

  QObject *fromQml = engine.rootObjects().at(0);

  QObject::connect(fromQml, SIGNAL(sendText(QString)), &layer, SLOT(split(QString)));

  return app.exec();
}

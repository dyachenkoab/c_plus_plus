#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "layer.h"

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

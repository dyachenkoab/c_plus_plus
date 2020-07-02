#ifndef LAYER_H
#define LAYER_H

#include <QObject>
#include <QDebug>

class Layer : public QObject
{
    Q_OBJECT

    wchar_t *arr = new wchar_t[sizeof(wchar_t)*2];

    float result;


    void save(float result);

public:
    explicit Layer(QObject *parent = nullptr);

signals:
    void changeIndex(float x);

public slots:
    void res(QStringList list);
    void split(QString text);

};

#endif // LAYER_H

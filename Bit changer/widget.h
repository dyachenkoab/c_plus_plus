#include <QObject>

#ifndef TEST3_WIDGET_H
#define TEST3_WIDGET_H

class widget : public QObject {
Q_OBJECT

    std::vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 0};
    int size_ = vec.size();
    int result = 0;

public:
    widget(QObject *parent = 0);

    ~widget();

    void convertToBin(int num);

    void convertToDec();

    void renewForms();

signals:

    void changeIndex(int ind, int x);

    void showResult(int res);

    void changeRadio(int ind);

public slots:

    void radioIndex(int ind);

    void hexInput(const QString& str);

    void fileOpen(const QString& url);

    void invertBits();

};

#endif //TEST3_WIDGET_H

#include <widget.h>
#include <QtWidgets/QFileDialog>
#include <QtCore/QTextStream>

widget::widget(QObject *parent) : QObject(parent) {}

widget::~widget() {}

void widget::radioIndex(int ind) {

    if (!vec.at(ind)) {
        vec.at(ind) = 1;
    } else {
        vec.at(ind) = 0;
    }

    emit changeIndex(ind, vec.at(ind));
    convertToDec();

    emit showResult(result);
}

void widget::hexInput(const QString &str) {

    bool b = true;
    result = str.toInt(&b, 16);

    convertToBin(result);
    renewForms();
}

void widget::convertToBin(int num) {

    vec.assign(8, 0);
    int i = size_ - 1;

    while (i != -1) {
        if (num % 2 == 0) {
            vec.at(i) = 0;
        } else {
            vec.at(i) = 1;
        }
        num = num >> 1;
        i--;
    }
}

void widget::convertToDec() {

    int double_ = 0;
    for (int i = 0; i < size_; ++i) {
        double_ = double_ * 2 + vec.at(i);
    }
    result = double_;

}

void widget::invertBits() {

    for (int i = 0; i < size_; ++i) {
        if (!vec.at(i)) {
            vec.at(i) = 1;
        } else {
            vec.at(i) = 0;
        }
    }

    convertToDec();
    renewForms();
}

void widget::fileOpen(const QString &url) {

    int i = 0;

    QString sfile = QUrl((QUrl) url).path();
    QFile file(sfile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);

    while (!in.atEnd()) {
        in >> dec >> i;
        result += i;
    }

    file.close();

    convertToBin(result);
    renewForms();
}

void widget::renewForms() {

    for (int i = 0; i < size_; ++i) {
        emit changeIndex(i, vec.at(i));
    }
    emit showResult(result);
}
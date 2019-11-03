#pragma once

#include <QtCore/QString>
#include <QtWidgets>
#include <iostream>
#include <QEvent>
#include <QKeyEvent>
#include <QMainWindow>
using namespace std;

class MyButton : public QWidget
{
Q_OBJECT

private:
    QString str1{}, str2{};
    qint16 left{}, right{}, top{}, bottom{}, spacing{};
    QPushButton *b1 = nullptr;
    QPushButton *b2 = nullptr;
    QHBoxLayout *phbxLayout = nullptr;

public:
    ~MyButton()
    {
        delete b1;
        delete b2;
        delete phbxLayout;
    }

    MyButton(QString buttonname1, QString buttonname2, qint16 left1, qint16 right1, qint16 top1, qint16 bottom1,
             qint16 spacing1)
    {
        setvalue(buttonname1, buttonname2, left1, right1, top1, bottom1, spacing1);
    }

    void setvalue(QString &buttonname1, QString &buttonname2, qint16 left1, qint16 right1, qint16 top1, qint16 bottom1,
                  qint16 spacing1)
    {
        str1 = buttonname1;
        str2 = buttonname2;
        left = left1;
        right = right1;
        top = top1;
        bottom = bottom1;
        spacing = spacing1;
    }

    public slots:

    void slotbutton1()
    {
        emit cout << "1" << endl;
    }
    void slotbutton2()
    {
        emit cout << "2" << endl;
    }

    void keyPressEvent(QKeyEvent *event)
    {
        if (event->key() == Qt::Key_Escape)
                cout << "esc" << endl;
    }

    void createbutton()
    {
        b1 = new QPushButton(str1);
        b2 = new QPushButton(str2);
        phbxLayout = new QHBoxLayout;
        phbxLayout->setContentsMargins(left, top, right, bottom);
        phbxLayout->setSpacing(spacing);
        phbxLayout->addWidget(b1);
        phbxLayout->addWidget(b2);
        setLayout(phbxLayout);

        connect(b1, SIGNAL(clicked()), this, SLOT(slotbutton1()));
        connect(b2, SIGNAL(clicked()), this, SLOT(slotbutton2()));
    }
};


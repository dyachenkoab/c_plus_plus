//
// Created by podkyr on 09.02.2020.
//
#ifndef QT_TASK_PROTORYPE_TASK_M_H
#define QT_TASK_PROTORYPE_TASK_M_H
#pragma once

#include <QtCore/QString>
#include <QtWidgets>
#include <iostream>
#include <QEvent>
#include <QKeyEvent>
#include <QMainWindow>

class task_m : public QWidget {
Q_OBJECT
    QTableView *left_column = new QTableView; // таблица заголовков
    QTextEdit *right_column = new QTextEdit;  // поле ввода

    QStringListModel *model = new QStringListModel; //
    QItemSelectionModel *selection = new QItemSelectionModel {model,this};

    QGridLayout *mainLayout = new QGridLayout;          //главный слой
    QGridLayout *secondLayout = new QGridLayout;        //слой с заголовками

    QLineEdit *nameLine = new QLineEdit;    //строка ввода
    QTextEdit *adressText = new QTextEdit; //
    QTextEdit *scheld_line = new QTextEdit; //

    QPushButton *button_plus = new QPushButton {"+"};   //кнопка
    QPushButton *button_minus = new QPushButton {"-"};

    QModelIndex numR;
    QVariant cell_data;

    QMap<QString, QString> notes;

    QString old_header;
    QString old_Note;

public slots:
    void add_row();
    void del_row();
    void view_selected_cell(QModelIndex i);

public:
    task_m(QWidget *parent = 0);

    ~task_m();
};


#endif //QT_TASK_PROTORYPE_TASK_M_H

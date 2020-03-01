#include <QtCore/QString>
#include <QtWidgets>
#include <iostream>
#include <QEvent>
#include <QKeyEvent>
#include <QMainWindow>

#ifndef QT_TASK_PROTORYPE_TASK_M_H
#define QT_TASK_PROTORYPE_TASK_M_H
#pragma once

class task_m : public QWidget {
Q_OBJECT
    int menuButtonSize = 50;
    //std::string iconPath = ""; хочу сделать часть пути переменной,
                                // но пока не разобрался почему не получилось
    QTableView *taskListTable = new QTableView; // Перече
    QTextEdit *taskText = new QTextEdit;  // поле ввода

    QLabel *taskListLabel = new QLabel;
    QLabel *currentDateLabel = new QLabel;
    QLineEdit *taskName = new QLineEdit; //строка ввода

    QStringListModel *model = new QStringListModel; //
    QItemSelectionModel *selection = new QItemSelectionModel {model,this};

    //Слои
    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *menuLayout = new QGridLayout;
    QGridLayout *taskListLayout = new QGridLayout;
    QGridLayout *taskLayout = new QGridLayout;

    QLineEdit *nameLine = new QLineEdit;    //строка ввода
    QTextEdit *adressText = new QTextEdit; //
    QTextEdit *scheld_line = new QTextEdit; //

    //Кнопки
    QPushButton *addTaskButton = new QPushButton;   //кнопка
    QPushButton *removeTaskButton = new QPushButton ;
    QPushButton *calendarButton = new QPushButton ;
    QPushButton *contactsButton = new QPushButton ;
    QPushButton *trashButton = new QPushButton ;
    QPushButton *loadbutton = new QPushButton("load");
    QPushButton *savebutton = new QPushButton("save");

    //QDialog *removeConfirm = new QDialog; // Диалоговое окно удаления


    QModelIndex numR;
    QVariant cell_data;

    QMap<QString, QString> notes;


    QString old_header;
    QString old_task;
    QString old_Note;

public slots:
    void add_record();
    void del_row();
    void view_selected_cell(QModelIndex i);
    void save_to_file();
    void load_from_file();

public:
    task_m(QWidget *parent = 0);

    ~task_m();

};

#endif //QT_TASK_PROTORYPE_TASK_M_H

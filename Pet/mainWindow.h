#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tableWidget.h"
#include <QAction>
#include <QDockWidget>
#include <QMenu>
#include <QMenuBar>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>

class mainWindow : public QMainWindow
{
    Q_OBJECT

    tableWidget* table;

    QPushButton* button_base = new QPushButton("load_base");
    QPushButton* button_spec = new QPushButton("load_spec");
    QPushButton* add_rowB = new QPushButton("add row");
    QPushButton* del_rowB = new QPushButton("delete row");
    QPushButton* calc = new QPushButton("calc sum");
    QPushButton* calc_total = new QPushButton("calc total");

    QWidget* wgt = new QWidget(this);
    //    QWidget* but = new QWidget(this);

    QGridLayout* layout = new QGridLayout();
    QVBoxLayout* vbox = new QVBoxLayout();

  public:
    mainWindow();
    ~mainWindow() = default;
};
#endif // MAINWINDOW_H

#include "mainWindow.h"
mainWindow::mainWindow() : QMainWindow(), table(new tableWidget(this))
{
    button_spec->setDisabled(true);
    //    QAction* butt_base = new QAction("&load_base", this);
    //    QMenu* base;

    //    base = menuBar()->addMenu("&load");
    //    base->addAction(butt_base);

    vbox->addWidget(button_base);
    vbox->addWidget(button_spec);
    vbox->addWidget(add_rowB);
    vbox->addWidget(del_rowB);
    vbox->addWidget(calc);
    vbox->addWidget(calc_total);

    //    but->setLayout(vbox);

    layout->addLayout(vbox, 0, 1);
    layout->addWidget(table, 0, 0);
    //    layout->addWidget(but, 0, 1);

    wgt->setLayout(layout);

    setCentralWidget(wgt);

    //    QObject::connect(
    //      butt_base, &QAction::triggered, table, &tableWidget::load_base);

    QObject::connect(button_base, &QAbstractButton::clicked, this, [this]() {
        button_spec->setEnabled(true);
    });

    QObject::connect(
      button_base, &QAbstractButton::clicked, table, &tableWidget::load_base);

    QObject::connect(
      button_spec, &QAbstractButton::clicked, table, &tableWidget::load_spec);

    QObject::connect(
      add_rowB, &QAbstractButton::clicked, table, &tableWidget::add_row);

    QObject::connect(
      del_rowB, &QAbstractButton::clicked, table, &tableWidget::del_row);

    QObject::connect(
      calc, &QAbstractButton::clicked, table, &tableWidget::calc_sum);

    QObject::connect(
      calc_total, &QAbstractButton::clicked, table, &tableWidget::calc_total);
};

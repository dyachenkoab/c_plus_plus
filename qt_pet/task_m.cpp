//
// Created by podkyr on 09.02.2020.
//

#include "task_m.h"

task_m::task_m(QWidget *parent) : QWidget(parent) {

    button_plus->setFixedSize(150, 25);
    button_minus->setFixedSize(150, 25);

    model->setStringList(QStringList() << "Item1"
                                       << "Item2"
                                       << "Item3");
    selection->setModel(model);

    left_column->setModel(model);
    left_column->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    left_column->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(button_plus, SIGNAL(clicked()), this, SLOT(add_row()));
    connect(button_minus, SIGNAL(clicked()), this, SLOT(del_row()));
    connect(left_column, SIGNAL(clicked(QModelIndex)), this, SLOT(view_selected_cell(QModelIndex)));

    mainLayout->setSpacing(10);
    secondLayout->setSpacing(10);
    secondLayout->setHorizontalSpacing(50);
    secondLayout->setVerticalSpacing(50);

   // mainLayout->addWidget(nameLine, 1, 2);
    mainLayout->addWidget(right_column, 2, 2);
    mainLayout->addWidget(button_plus, 1, 1);
    mainLayout->addWidget(button_minus, 1, 2);
    secondLayout->addWidget(left_column, 1, 1, 1, 2);

    mainLayout->addLayout(secondLayout, 2, 1);

    setLayout(mainLayout);
    setWindowTitle(tr("Simple Address Book"));


    notes["Item1"] = "wazzup1";
    notes["Item2"] = "wazzup2";
    notes["Item3"] = "wazzup3";


}

task_m::~task_m() {

}

void task_m::add_row() {
    model->insertRow(model->rowCount()); //добавление строки в таблицу

}

void task_m::del_row() {
    model->removeRow(left_column->currentIndex().row());
}
void task_m::view_selected_cell(QModelIndex i){
    cell_data = model->data( i, Qt::DisplayRole);
    old_header = cell_data.toString();
    right_column->setText(notes.value(old_header));
}



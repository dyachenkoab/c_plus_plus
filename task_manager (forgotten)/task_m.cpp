#include "task_m.h"

task_m::task_m(QWidget *parent) : QWidget(parent) {

    addTaskButton->setFixedSize(menuButtonSize, menuButtonSize);
    addTaskButton->setIcon(QIcon("../img/icons/add.png"));
    addTaskButton->setIconSize(QSize(menuButtonSize, menuButtonSize));

    removeTaskButton->setFixedSize(menuButtonSize, menuButtonSize);
    removeTaskButton->setIcon(QIcon("../img/icons/remove.png"));
    removeTaskButton->setIconSize(QSize(menuButtonSize, menuButtonSize));

    calendarButton->setFixedSize(menuButtonSize, menuButtonSize);
    calendarButton->setIcon(QIcon("../img/icons/calendar.png"));
    calendarButton->setIconSize(QSize(menuButtonSize, menuButtonSize));

    contactsButton->setFixedSize(menuButtonSize, menuButtonSize);
    contactsButton->setIcon(QIcon("../img/icons/contacts.png"));
    contactsButton->setIconSize(QSize(menuButtonSize, menuButtonSize));

    trashButton->setFixedSize(menuButtonSize, menuButtonSize);
    trashButton->setIcon(QIcon("../img/icons/trash.png"));
    trashButton->setIconSize(QSize(menuButtonSize, menuButtonSize));

    taskListLabel->setText("Список задач");
    currentDateLabel->setText(QDate::currentDate().toString());


    model->setStringList(QStringList() << "Item1"
                                       << "Item2"
                                       << "Item3");
    selection->setModel(model);

    taskListTable->setModel(model);
    taskListTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    taskListTable->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(addTaskButton, SIGNAL(clicked()), this, SLOT(add_record()));
    connect(removeTaskButton, SIGNAL(clicked()), this, SLOT(del_row()));
    connect(taskListTable, SIGNAL(clicked(QModelIndex)), this, SLOT(view_selected_cell(QModelIndex)));
    connect(loadbutton, SIGNAL(clicked()), this, SLOT(load_from_file()));
    connect(savebutton, SIGNAL(clicked()), this, SLOT(save_to_file()));

    mainLayout->setSpacing(10);

    mainLayout->addLayout(menuLayout, 0, 0);
    mainLayout->addLayout(taskListLayout, 0, 1);
    mainLayout->addLayout(taskLayout, 0, 2);

    menuLayout->addWidget(addTaskButton, 0, 0, Qt::AlignTop);
    menuLayout->addWidget(removeTaskButton, 1, 0, Qt::AlignTop);
    menuLayout->addWidget(calendarButton, 2, 0, Qt::AlignTop);
    menuLayout->addWidget(contactsButton, 3, 0, Qt::AlignTop);
    menuLayout->addWidget(trashButton, 4, 0, Qt::AlignTop);
    menuLayout->addWidget(loadbutton, 5, 0, Qt::AlignTop);
    menuLayout->addWidget(savebutton, 6, 0, Qt::AlignTop);

    taskListLayout->addWidget(taskListLabel, 0, 0, Qt::AlignCenter);
    taskListLayout->addWidget(taskListTable, 1, 0, 8, 0);

    taskLayout->addWidget(currentDateLabel, 0, 0, Qt::AlignCenter);
    taskLayout->addWidget(taskName, 1, 0);
    taskLayout->addWidget(taskText, 2, 0, 8, 0);

    //   secondLayout->setSpacing(10);
    //  secondLayout->setHorizontalSpacing(50);
    // secondLayout->setVerticalSpacing(50);

    // mainLayout->addWidget(nameLine, 1, 2);

    // mainLayout->addWidget(button_plus, 1, 1);
    // mainLayout->addWidget(button_minus, 2, 1);
    //mainLayout->addWidget(left_column, 3, 1);
    // mainLayout->addWidget(right_column, 2, 2, 2, 0);



    //mainLayout->addLayout(secondLayout, 2, 1);


    setLayout(mainLayout);
    setWindowTitle(tr("Simple Address Book"));


    notes["Item1"] = "wazzup1";
    notes["Item2"] = "wazzup2";
    notes["Item3"] = "wazzup3";


}

task_m::~task_m() {

}

void task_m::add_record() {
    cell_data = model->data(taskListTable->currentIndex());
    old_task = taskName->text();
    old_Note = cell_data.toString();
    if (!notes.contains(old_Note)) {
        notes.insert(old_Note, old_task);
        QMessageBox::information(this, tr("Add Successful"),
                                 tr("\"%1\" has been added to your address book.").arg(old_Note));
    }
    model->insertRow(model->rowCount()); //добавление строки в таблицу

}

void task_m::del_row() {
    model->removeRow(taskListTable->currentIndex().row());
}

void task_m::view_selected_cell(QModelIndex i) {
    cell_data = model->data(i, Qt::DisplayRole);
    old_header = cell_data.toString();
    taskName->setText(notes.value(old_header));
}

void task_m::save_to_file() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Address Book"), "",
                                                    tr("Address Book (*.abk);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_3);
        out << notes;
    }
}

void task_m::load_from_file() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Address Book"), "",
                                                    tr("Address Book (*.abk);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_3);
        notes.empty();   // очищаем существующие контакты
        in >> notes;
    }
    if (notes.isEmpty()) {
        QMessageBox::information(this, tr("No contacts in file"),
                                 tr("The file you are attempting to open contains no contacts."));
    } else {
        QMap<QString, QString>::iterator i = notes.begin();
        QMap<QString, QString>::iterator j = notes.end();
        QStringList list;
        while(i != j){
        list << i.key();
        model->setStringList(list);
        ++i;
        }
    }
}

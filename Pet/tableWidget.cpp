#include "tableWidget.h"
#include <QtCore/qfloat16.h>
#include <QtXlsx>
#include <iostream>
#include <qdebug.h>

tableWidget::tableWidget(QWidget* parent) : QTableWidget(parent)
{
    counterRows = 1;
    counterColumns = 1;
    setColumnCount(7);
    setRowCount(1);

    setHorizontalHeaderLabels(headers);
}

// ----------------- implements ------------------------------
QString
tableWidget::openFile()
{
    QString fileName =
      QFileDialog::getOpenFileName(this,
                                   tr("Open Excel Book"),
                                   "/home/",
                                   tr("Excel Book (*.xlsx);;All Files (*)"));
    if (fileName.isEmpty())
    {
        return nullptr;
    } else
    {
        return fileName;
    }
    //    item->setFlags(item->flags() &  ~Qt::ItemIsEditable);
}
//------------------------------------------------------------------
void
tableWidget::load_base()
{
    QString data_place = "/home/podkyr/grad.xlsx"; // openFile();
    if (!data_place.isEmpty())
    {
        QXlsx::Document doc(data_place);

        counterRows = rowCounter(doc);
        counterColumns = colCounter(doc);

        for (int i = 1; i < counterRows; ++i)
        {
            data_s cell;
            for (int j = 1; j < counterColumns; ++j)
            {
                //                    qDebug() << doc.read(i, j);
                switch (j)
                {
                    case 1:
                        cell.name = doc.read(i, j).toString().toLower();
                        break;
                    case 2:
                        cell.type = doc.read(i, j);
                        break;
                    case 3:
                        cell.price = doc.read(i, j);
                        break;
                    case 4:
                        cell.price_with_nds_10 = doc.read(i, j);
                        break;
                    case 5:
                        cell.price_with_nds_30 = doc.read(i, j);
                        data_.push_back(cell);
                        break;
                    default:
                        break;
                }
            }
        }
        auto p = 0;
        for (auto x : data_)
        {
            qDebug() << ++p << x.name << " ";
        }
        qDebug() << " ";
    }
}
//------------------------------------------------------
void
tableWidget::load_spec()
{
    QString data_place = "/home/podkyr/spec.xlsx"; // openFile();
    if (!data_place.isEmpty())
    {
        QXlsx::Document doc(data_place);

        QVariant cell_t;
        QString ss;
        QStringList list;

        int i = 1;
        int j = 1;

        counterRows = rowCounter(doc);
        counterColumns = colCounter(doc);

        for (i = 1; i < counterRows; ++i)
        {
            data_spec cell;
            ss = doc.read(i, 1).toString().toLower();
            insertRow(i);

            for (j = 1; j < counterColumns; ++j)
            {
                QTableWidgetItem* item = new QTableWidgetItem;

                cell_t = doc.read(i, j);

                item->setData(Qt::EditRole, cell_t);
                setItem(i - 1, j - 1, item);

                switch (j)
                {
                    case 1:
                        cell.name = doc.read(i, j).toString().toLower();
                        break;
                    case 2:
                        cell.quantity = doc.read(i, j).Int;
                        data_sp.push_back(cell);
                        break;
                    default:
                        break;
                }
            } // for j

            list = make_dict(ss, dict, diametr);
            qDebug() << list.size();
            int ind = 0;
            auto ite = std::end(data_);
            auto itb = std::begin(data_);

            if (list.size() > 1)
            {

                while (ind < list.size())
                {
                    ite = std::partition(itb, ite, compa(list.at(ind)));
                    ++ind;
                }

                //        for (itb = data_.begin(); itb < ite; ++itb) {
                //          qDebug() << itb->name << " ";
                //        }
                //        qDebug() << " ";

                auto itb = data_.begin();

                std::vector<data_s> v(itb, ite);

                //        for (auto x : v) {
                //          qDebug() << x.name << " ";
                //        }
                //        qDebug() << " ";

                if (v.size() == 0)
                    continue;

                auto result1 = std::find(v.begin(), v.end(), list.at(ind - 1));
                if (result1 != std::end(v))
                {
                    setColumnCount(j + 4);

                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setData(Qt::EditRole, result1->type);
                    setItem(i - 1, j - 1, item);

                    QTableWidgetItem* item1 = new QTableWidgetItem;
                    item1->setData(Qt::EditRole, result1->price);
                    setItem(i - 1, j, item1);

                    QTableWidgetItem* item2 = new QTableWidgetItem;
                    item2->setData(Qt::EditRole, result1->price_with_nds_10);
                    setItem(i - 1, j + 1, item2);

                    QTableWidgetItem* item3 = new QTableWidgetItem;
                    item3->setData(Qt::EditRole, result1->price_with_nds_30);
                    setItem(i - 1, j + 2, item3);

                } else
                    continue;
            } // if list.size
        }     // for i
    }         // if !data_place.isEmpty
}
//-----------------------------------------------------------------------------
QStringList
tableWidget::make_dict(QString& input,
                       QMap<QString, bool> dicct,
                       const QString& d)
{
    QStringList split_list = input.split(" ");
    QStringList keys;
    int index = 0;
    QMap<QString, bool>::iterator it;

    index = split_list.indexOf(d);
    if (index != -1)
    {
        ++index;
        it = dicct.begin();

        while (it != dicct.end())
        {

            if (split_list.contains(it.key()))
            {
                it.value() = true;
                ++it;
            } else
                ++it;
        }

        //        while (it != dicct.end())
        //        {
        //            QByteArray b;
        //            QByteArray p;

        //            b.append(it.key());
        //            p.append(input);
        ////            qDebug() << p.indexOf(b);

        //            if (p.indexOf(b) != -1)
        //            {
        //                it.value() = true;
        //                ++it;
        //            } else
        //                ++it;
        //        }

        it = dicct.begin();
        while (it != dicct.end())
        {
            if (*it == true)
            {
                keys.append(it.key());
            }
            ++it;
        }
        while (split_list.at(index) == "")
        {
            ++index;
        }
        QString str = d + " " + split_list.at(index) + " ";
        keys.append(str);
    } // if index

    /* словарь, в котором содержатся ключи прилагательные, а поиск ведётся -
       если есть диаметр (первый(основной) ключ, вставляется последним), ключ,
       может ещё ключ, делает максимальную выборку	*/

    return keys;
};
//----------------------------------------------------------------------------------------
int
tableWidget::rowCounter(const QXlsx::Document& doc)
{
    int i = 1;
    while (doc.read(i, 1).isValid())
    {
        ++i;
    }
    return i;
}

int
tableWidget::colCounter(const QXlsx::Document& doc)
{
    int i = 1;
    while (doc.read(1, i).isValid())
    {
        ++i;
    }
    return i;
}
//------------------------------------------------------------------------------------------
void
tableWidget::add_row()
{
    insertRow(rowCount());
}

void
tableWidget::del_row()
{
    removeRow(currentIndex().row());
}
//------------------------------------------------------------------------------------------

void
tableWidget::calc_sum()
{
    float flo = 0.0;
    QTableWidgetItem* iteem = new QTableWidgetItem;

    for (int i = 0; i < counterRows; ++i)
    {
        iteem = item(i, 1);
        QTableWidgetItem* iteem2 = new QTableWidgetItem;
        if (iteem)
        {
            flo = iteem->data(Qt::EditRole).toFloat();
            iteem = item(i, 3);
            if (iteem)
            {
                flo *= iteem->data(Qt::EditRole).toFloat();
                iteem2->setData(Qt::EditRole, flo);
                setItem(i, 6, iteem2);
            }
        }
    }
}

//------------------------------------------------------------------------------------------

void
tableWidget::calc_total()
{
    int col = columnCount();

    QTableWidgetItem* hed = new QTableWidgetItem;
    hed->setData(Qt::DisplayRole, "total");
    setVerticalHeaderItem(counterRows - 1, hed);

    float flo = 0.0;
    QTableWidgetItem* iteem = new QTableWidgetItem;

    for (int i = 3; i < col; ++i)
    {
        QTableWidgetItem* iteem2 = new QTableWidgetItem;
        flo = 0.0;

        for (int j = 0; j < counterRows - 2; ++j)
        {
            iteem = item(j, i);
            if (iteem)
            {
                flo += iteem->data(Qt::EditRole).toFloat();
            }
        }

        iteem2->setData(Qt::EditRole, flo);
        setItem(counterRows - 1, i, iteem2);
    }
}

//------------------------------------------------------------------------------------------
void
tableWidget::testXls()
{
    //     QString data_place = "/home/podkyr/grad.xlsx"; //openFile();
    //    if (data_place.isEmpty()) true;
    //         else
    //         {
    //// 		     QXlsx::Document
    /// doc("/home/podkyr/grad_price.xlsx");

    //           QXlsx::Document doc(data_place);
    /*  while(true)
      {
      QVariant cell = doc.read(counterRows, 1);
        qDebug() << cell;

      if (!cell.isValid()) break;
  //             if (counterRows == 32) break;

      insertRow(counterRows-1);

      QTableWidgetItem *item = new QTableWidgetItem;
      item->setData(Qt::EditRole, cell);

      setItem(counterRows-1, 0, item);
      ++counterRows;

           while(true)
           {
                 QVariant cell = doc.read(1, counterColumns);

                 if(!cell.isValid()) break;
  //                        if(counterColumns == 7) break;

                 insertColumn(counterColumns-1);

                 QTableWidgetItem *item = new QTableWidgetItem;
                 item->setData(Qt::EditRole, cell);
                      qDebug() << cell;

                 setItem(0, counterColumns-1, item);
                 ++counterColumns;
           }

    }

   for(int i = 2; i < counterRows; ++i)
   {
       for(int j = 2; j < counterColumns; ++j)
       {
           QTableWidgetItem *item = new QTableWidgetItem;

           QVariant cell = doc.read(i, j);

           item->setData(Qt::EditRole, cell);
           setItem(i-1, j-1, item);
            qDebug() << cell;

        }

   }*/
}

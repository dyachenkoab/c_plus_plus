#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include "data_s.h"
#include <QString>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <QtXlsx>

typedef struct
{
    QString name;
    int quantity;

} data_spec;
//---------------------------------------------------------------------
struct comp : std::unary_function<data_s, bool>
{
    const QString comp_string;

    comp(const QString& comp_string) : comp_string(comp_string) {}

    bool operator()(const data_s& s) const { return s.name == comp_string; }
};
//--------------------------------------------------------------------
struct compa : std::unary_function<data_s, bool>
{
    const QString comp_string;

    compa(const QString& comp_string) : comp_string(comp_string) {}

    bool operator()(const data_s& s) const
    {
        return s.name.contains(comp_string);
    }
};
//--------------------------------------------------------------------
class tableWidget : public QTableWidget
{
    Q_OBJECT

    friend class data_s;

    QStringList headers { "name",   "quantity", "type", "price",
                          "nds_10", "nds_30",   "sum" };

    int counterRows;
    int counterColumns;
    QList<data_s> data_;
    QList<data_spec> data_sp;

    QString diametr { "д" };

    QMap<QString, bool> dict {
        { "труба", false },     { "металлопластиковая", false },
        { "pp-r", false },      { "стекловолокном", false },
        { "алюминием", false }, { "вгп", false },
        { "э/св", false },      { "оцинкованая", false }
    };

  public:
    tableWidget(QWidget* parent = nullptr);

    QString openFile();

    void testXls();

    QStringList make_dict(QString& input,
                          QMap<QString, bool>,
                          const QString& d);

    int rowCounter(const QXlsx::Document& doc);

    int colCounter(const QXlsx::Document& doc);

    void calc_sum();

    void calc_total();

  public slots:
    void load_base();

    void load_spec();

    void add_row();

    void del_row();
};
#endif // TABLEWIDGET_H

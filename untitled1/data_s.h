#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QVariant>

class data_s
{
    friend class tableWidget;

  public:
    QString name;
    QVariant type;
    QVariant price;
    QVariant price_with_nds_10;
    QVariant price_with_nds_30;

    data_s() {}

    ~data_s() = default;

    bool operator==(const QString& s) const { return name.contains(s); }
};

#endif // DATA_H

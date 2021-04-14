#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <iostream>

class DataBase : public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit DataBase( QObject *parent = nullptr );

    QSqlDatabase db;

    enum Roles { DateRole = Qt::UserRole + 1, TimeRole, NameRole, ColorRole, NumberPlateRole, AccuracyRole, PhotoRole, CamId };

    ~DataBase()
    {
        db.removeDatabase( "test" );
    } //= default;

    //    bool openDataBase();        // Открытие базы данных
    //    bool createTable();         // Создание базы таблицы в базе данных
    QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
    QHash<int, QByteArray> roleNames() const;

public slots:
    bool inserIntoTable( const QVariantList &data ); // Добавление записей в таблицу
    bool inserIntoTable(const QString &date, const QString &time, const QString &name, const QString &color, const QString &numberplate, const QString &accuracy, const QString &photo );
    bool removeRecord( const int id ); // Удаление записи из таблицы по её id
    int numberPlateSearch(const QString &dateFrom, const QString &dateTo, const QString &timeFrom, const QString &timeTo, const QString &name, const QString &color, const QString &numberplate);

    void setEmpty();
    QStringList suggestions(const QString &who, const QString &word);

    void updateModel();
    int getId( int row );
signals:
};

#endif // DATABASE_H

#include "database.h"

#define TABLE		  "cars"
#define TABLE_DATE	  "date"
#define TABLE_TIME	  "time"
#define TABLE_NAME	  "name"
#define TABLE_NUMBERPLATE "numberplate"
#define TABLE_COLOR	  "color"
#define TABLE_PHOTO	  "photo"
#define TABLE_ACCURACY	  "accuracy"

DataBase::DataBase( QObject *parent ) : QSqlQueryModel( parent ), db( QSqlDatabase::addDatabase( "QPSQL", "test" ) )
{
    db.setDatabaseName( "radar" );
    db.setUserName( "user4" );

    //    bool b = db.open();
    !db.open() ? qDebug() << "NOPE" << db.lastError() : qDebug() << "CONNECTED";

    //    this->updateModel();

    //	if ( !db.open() )
    //		qDebug() << "NOPE" << db.lastError();
    //	else
    //		qDebug() << "CONNECTED";
}

/* Метод для вставки записи в базу данных
 * */
bool DataBase::inserIntoTable( const QVariantList &data )
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare( "INSERT INTO " TABLE " (" TABLE_DATE ", " TABLE_TIME ", " TABLE_NAME ", " TABLE_COLOR ", " TABLE_NUMBERPLATE
               ", " TABLE_ACCURACY ", " TABLE_PHOTO " ) "
               "VALUES (:date, :time, :name, :numberplate, :accuracy, :photo)" );
    query.bindValue( ":date", data[0].toString() );
    query.bindValue( ":time", data[1].toString() );
    query.bindValue( ":name", data[2].toString() );
    query.bindValue( ":color", data[3].toString() );
    query.bindValue( ":numberplate", data[4].toString() );
    query.bindValue( ":accuracy", data[5].toString() );
    query.bindValue( ":photo", data[6].toString() );

    // После чего выполняется запросом методом exec()
    if ( !query.exec() ) {
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else
        return true;

    return false;
}

/* Второй метод для вставки записи в базу данных
 * */
bool DataBase::inserIntoTable( const QString &date, const QString &time, const QString &name, const QString &color, const QString &numberplate,
                   const QString &accuracy, const QString &photo )
{
    QVariantList data;
    data.append( date );
    data.append( time );
    data.append( name );
    data.append( color );
    data.append( numberplate );
    data.append( accuracy );
    data.append( photo );

    if ( inserIntoTable( data ) )
        return true;
    else
        return false;
}

/* Метод для удаления записи из таблицы
 * */
bool DataBase::removeRecord( const int id )
{
    // Удаление строки из базы данных будет производитсья с помощью SQL-запроса
    QSqlQuery query;

    // Удаление производим по id записи, который передается в качестве аргумента функции
    query.prepare( "DELETE FROM " TABLE " WHERE id= :ID ;" );
    query.bindValue( ":ID", id );

    // Выполняем удаление
    if ( !query.exec() ) {
        qDebug() << "error delete row " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

QStringList DataBase::suggestions( const QString &who, const QString &word )
{
    QSqlQuery query( db );
    QString word1;
    QStringList lst;

    if ( word.isEmpty() )
        word1 = " is not null";
    else
        word1 = " LIKE '" + word + "%'";

    if ( who == "color" )
        qDebug() << query.exec( QString( "SELECT DISTINCT color FROM cars WHERE color %1" ).arg( word1 ) );
    if ( who == "name" )
        qDebug() << query.exec( QString( "SELECT DISTINCT name FROM cars WHERE name %1" ).arg( word1 ) );
    if ( who == "numberplate" )
        qDebug() << query.exec( QString( "SELECT numberplate FROM cars WHERE numberplate %1" ).arg( word1 ) );

    //    if (!query.prepare( "SELECT numberplate FROM cars WHERE numberplate :word") )
    //        qDebug() << "not PREP";

    //        qDebug() << word1 << " word1";
    //        query.bindValue( ":word", word1 );
    //    query.bindValue( ":name", name1 );

    //    query.first();
    while ( query.next() ) {
        lst.append( query.value( 0 ).toString() );
        qDebug() << query.value( 0 ).toString();
    }

    return lst;
}

void DataBase::setEmpty()
{
    this->clear();
}

QVariant DataBase::data( const QModelIndex &index, int role ) const
{

    // Определяем номер колонки, адрес так сказать, по номеру роли
    int columnId = role - Qt::UserRole - 1;
    // Создаём индекс с помощью новоиспечённого ID колонки
    QModelIndex modelIndex = this->index( index.row(), columnId );

    /* И с помощью уже метода data() базового класса
     * вытаскиваем данные для таблицы из модели
     * */
    return QSqlQueryModel::data( modelIndex, Qt::DisplayRole );
}

QHash<int, QByteArray> DataBase::roleNames() const
{
    /* То есть сохраняем в хеш-таблицу названия ролей
     * по их номеру
     * */
    QHash<int, QByteArray> roles;
    roles[DateRole] = "date";
    roles[TimeRole] = "time";
    roles[NameRole] = "name";
    roles[ColorRole] = "color";
    roles[NumberPlateRole] = "numberplate";
    roles[AccuracyRole] = "accuracy";
    roles[PhotoRole] = "photo";
    roles[CamId] = "camid";
    return roles;
}

int DataBase::numberPlateSearch( const QString &dateFrom, const QString &dateTo, const QString &timeFrom, const QString &timeTo, const QString &name,
                 const QString &color, const QString &numberplate )
{

    qDebug() << "dateFrom: " << dateFrom << " dateTo: " << dateTo << "timeFrom: " << timeFrom << " timeTo: " << timeTo << " name: " << name
         << " color: " << color << " numberplate: " << numberplate;

    QString timeFrom1;
    QString timeTo1;
    QString name1;
    QString color1;
    QString numberplate1;
    QString dateFrom1;
    QString dateTo1;

    QStringList ldateTo = dateTo.split( '.' );
    QStringList ldateFrom = dateFrom.split( '.' );

    if ( dateFrom.isEmpty() )
        dateFrom1 = "";
    else
        dateFrom1 = " AND date>'" + QString( ldateFrom.at( 2 ) + "-" + ldateFrom.at( 1 ) + "-" + ldateFrom.at( 0 ) ) + "'";

    if ( dateTo.isEmpty() )
        dateTo1 = "";
    else
        dateTo1 = " AND date<'" + QString( ldateTo.at( 2 ) + "-" + ldateTo.at( 1 ) + "-" + ldateTo.at( 0 ) ) + "'";

    if ( timeFrom.isEmpty() )
        timeFrom1 = "";
    else
        timeFrom1 = " AND time>'" + timeFrom + "'";

    if ( timeTo.isEmpty() )
        timeTo1 = "";
    else
        timeTo1 = " AND time<'" + timeTo + "'";

    if ( name.isEmpty() )
        name1 = " is not null";
    else
        name1 = "='" + name + "'";

    if ( color.isEmpty() )
        color1 = " is not null";
    else
        color1 = "='" + color + "'";

    if ( numberplate.isEmpty() )
        numberplate1 = " is not null";
    else if ( numberplate == "?" )
        numberplate1 = " LIKE '?%'";
    else
        numberplate1 = "='" + numberplate + "'";

    QString st = "SELECT * FROM " TABLE " WHERE color" + color1 + " AND name" + name1 + " AND numberplate" + numberplate1 + dateFrom1 + dateTo1 +
             timeFrom1 + timeTo1;

    // Обновление производится SQL-запросом к базе данных

    this->setQuery( st, db );

    //    this->setQuery( "SELECT * FROM " TABLE " WHERE color" + color1 + " and name" + name1, db );
    //    this->setQuery( "SELECT * FROM " TABLE " WHERE name" + name1 + " AND numberplate" + numberplate1, db );

    //    QSqlQuery query(db);

    //    if (!query.prepare( "SELECT * FROM cars WHERE color= :color;") )
    //        qDebug() << "not PREP";

    //    query.bindValue( ":color", color1 );
    //    query.bindValue( ":name", name1 );

    //    qDebug() << query.exec(QString("SELECT * FROM cars" " WHERE color %1" " and name %2" " and numberplate
    //    %3").arg(color1).arg(name1).arg(numberplate1)); query.first(); while(query.next()){
    //        qDebug() << query.value(3).toString();
    //    }

    qDebug() << st;
    return this->rowCount();
}

// Метод обновления таблицы в модели представления данных
void DataBase::updateModel()
{
    // Обновление производится SQL-запросом к базе данных
    this->setQuery(
        "SELECT " TABLE_TIME ", " TABLE_NAME ", " TABLE_COLOR ", " TABLE_NUMBERPLATE ", " TABLE_ACCURACY ", " TABLE_PHOTO " FROM " TABLE, db );
}

int DataBase::getId( int row )
{
    return this->data( this->index( row, 0 ), AccuracyRole ).toInt();
}

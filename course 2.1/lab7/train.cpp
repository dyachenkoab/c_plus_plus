#include <string>
#include <cstring>
#include "Array.cpp"
using namespace std;

class train {
    string number;
    string train_type, station;
    string start_time, path_time;
    Array<string> info;

public:
    void addInfo(Array<string> &ar); // конструктор копирования контейнера
    void set_Info(const string &record); //добавить запись
    void correct_info(int numb, const string& record); //редактировать запись
    void erase(); //удалить все записи из контейнера
//----------------------------------------------------------------------------------
    friend ostream & operator << (ostream &, train &); //перегрузка вывода
    train & operator =(train const&); //перегрузка присваивания
    train(const train &); //конструктор копирования
    ~train();
    string* trainMember(const char* Name); //вставка значения на нужное место
    train(const char *number, const char *t_type, const char *station, const char *s_time, const char *p_time,const char* inf); //коструктор по умолчанию
};
///////////////////////////////////////////////////////////////////////////////////////////

train::train(const char* num = "", const char *t_type = "", const char *stat = "", const char *s_time = "", const char *p_time = "", const char *inf = ""): \
              number(num), train_type(t_type), station(stat), start_time(s_time), path_time(p_time)
{   char *p = nullptr;
    if(p=StrTok(inf,";"))
    {
    info.Add(p);
    while (p = StrTok(nullptr, ";"))
        info.Add(p);
    }
}
train::~train() = default;
//--------------------------------------------------
train::train(const train &tr)
{   number = tr.number;
    train_type = tr.train_type;
    station = tr.station;
    start_time = tr.start_time;
    path_time = tr.path_time;
    info = tr.info;
    cout << " copy " << endl;
}
//--------------------------------------------------
train &train::operator=(train const &tr)
{   number = tr.number;
    train_type = tr.train_type;
    station = tr.station;
    start_time = tr.start_time;
    path_time = tr.path_time;
    info = tr.info;
    return *this;
}
//--------------------------------------------------
ostream &operator<<(ostream &out, train &tr)
{
    out << "Номер: " << tr.number << ", поезд: " << tr.train_type << ", станция отправления: " << tr.station \
    << ", время отправления: " << tr.start_time << ", время в пути: " << tr.path_time << endl;

    for(int i = 0;i<tr.info.Size();i++)
    out << tr.info[i] << endl;
    return out;
}
//--------------------------------------------------


//--------------------------------------------------
string * train::trainMember(const char* Name)
{
    if(!strcmp(Name,"number"))
        return &number;
    if(!strcmp(Name,"type"))
        return &train_type;
    if(!strcmp(Name,"station"))
        return &station;
    if(!strcmp(Name,"start"))
        return &start_time;
    if(!strcmp(Name,"path"))
        return &path_time;
    return nullptr;
}
//--------------------------------------------------
void train::addInfo(Array<string> &ar)
    {
        for(int i=0;i<info.Size();i++)
            ar.Add(info[i]);
        cout << "copy";
    }
//--------------------------------------------------
void train::set_Info(const string& record)
{
    info.Add(record);
}
//--------------------------------------------------
void train::correct_info(int numb, const string &record = nullptr)
{  if (!record[0])
    info.Erase(numb);
    else
    {
        info.Erase(numb);
        info.Add(record);
    }
}
//--------------------------------------------------
void train::erase()
{
    info.Clear();
}
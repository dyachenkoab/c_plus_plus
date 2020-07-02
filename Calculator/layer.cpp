#include "layer.h"
#include "QRegularExpression"
#include "library.h"
#include <QDebug>
#include <QFile>

Layer::Layer(QObject* parent)
  : QObject(parent)
{}

void
Layer::save(float result)
{
  QFile file("in.json");
  if (!file.open(QIODevice::WriteOnly))
    return;

  QTextStream out(&file);
  out << "{ \"var\": " << qSetRealNumberPrecision(8) << result << " }";

  file.close();
}

void
Layer::split(QString text)
{

  QStringList list;

  QRegularExpression re("(\\+|-)?((?:\\d+(?:\\.\\d*)?|\\.\\d+))(\\+|-|\\*|\\/"
                        ")((?:\\d+(?:\\.\\d*)?|\\.\\d+))");
  QRegularExpressionMatch match;

  QRegularExpressionMatchIterator i = re.globalMatch(text);

  match = i.next();

  for (int j = 1; j < 5; j++) {
    list << match.captured(j);
  }

  res(list);
}

void
Layer::res(QStringList list)
{
  bool ok;

  float f = list.at(1).toFloat(&ok);

  if (!list.at(0).isEmpty()) {
    f = -f;
  }

  float s = list.at(3).toFloat(&ok);

  list.at(2).toWCharArray(arr);
  arr[1] = (wchar_t)'\0';

  result = convertSymb(arr, f, s);

  emit changeIndex(result);

  save(result);
}

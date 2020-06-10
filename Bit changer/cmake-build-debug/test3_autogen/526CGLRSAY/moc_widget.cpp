/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widget_t {
    QByteArrayData data[14];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widget_t qt_meta_stringdata_widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "widget"
QT_MOC_LITERAL(1, 7, 11), // "changeIndex"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "ind"
QT_MOC_LITERAL(4, 24, 1), // "x"
QT_MOC_LITERAL(5, 26, 10), // "showResult"
QT_MOC_LITERAL(6, 37, 3), // "res"
QT_MOC_LITERAL(7, 41, 11), // "changeRadio"
QT_MOC_LITERAL(8, 53, 10), // "radioIndex"
QT_MOC_LITERAL(9, 64, 8), // "hexInput"
QT_MOC_LITERAL(10, 73, 3), // "str"
QT_MOC_LITERAL(11, 77, 8), // "fileOpen"
QT_MOC_LITERAL(12, 86, 3), // "url"
QT_MOC_LITERAL(13, 90, 10) // "invertBits"

    },
    "widget\0changeIndex\0\0ind\0x\0showResult\0"
    "res\0changeRadio\0radioIndex\0hexInput\0"
    "str\0fileOpen\0url\0invertBits"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,
       7,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   60,    2, 0x0a /* Public */,
       9,    1,   63,    2, 0x0a /* Public */,
      11,    1,   66,    2, 0x0a /* Public */,
      13,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widget *_t = static_cast<widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeIndex((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->showResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeRadio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->radioIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->hexInput((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->fileOpen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->invertBits(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widget::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget::changeIndex)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget::showResult)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget::changeRadio)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_widget.data,
      qt_meta_data_widget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widget.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void widget::changeIndex(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void widget::showResult(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void widget::changeRadio(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'mainForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainForm_t {
    QByteArrayData data[13];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_mainForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_mainForm_t qt_meta_stringdata_mainForm = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 4),
QT_MOC_LITERAL(4, 26, 5),
QT_MOC_LITERAL(5, 32, 11),
QT_MOC_LITERAL(6, 44, 10),
QT_MOC_LITERAL(7, 55, 6),
QT_MOC_LITERAL(8, 62, 9),
QT_MOC_LITERAL(9, 72, 4),
QT_MOC_LITERAL(10, 77, 12),
QT_MOC_LITERAL(11, 90, 13),
QT_MOC_LITERAL(12, 104, 1)
    },
    "mainForm\0newSession\0\0exit\0about\0"
    "connectPort\0serialRead\0update\0writeData\0"
    "data\0debugHandler\0changeHandler\0i\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08,
       3,    0,   60,    2, 0x08,
       4,    0,   61,    2, 0x08,
       5,    0,   62,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    1,   65,    2, 0x08,
      10,    0,   68,    2, 0x08,
      11,    1,   69,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void mainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainForm *_t = static_cast<mainForm *>(_o);
        switch (_id) {
        case 0: _t->newSession(); break;
        case 1: _t->exit(); break;
        case 2: _t->about(); break;
        case 3: _t->connectPort(); break;
        case 4: _t->serialRead(); break;
        case 5: _t->update(); break;
        case 6: _t->writeData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 7: _t->debugHandler(); break;
        case 8: _t->changeHandler((*reinterpret_cast< qint32(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject mainForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainForm.data,
      qt_meta_data_mainForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *mainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainForm.stringdata))
        return static_cast<void*>(const_cast< mainForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'tablesavetoexcel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Thread/tablesavetoexcel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tablesavetoexcel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TableSaveToExcel_t {
    QByteArrayData data[8];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TableSaveToExcel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TableSaveToExcel_t qt_meta_stringdata_TableSaveToExcel = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TableSaveToExcel"
QT_MOC_LITERAL(1, 17, 17), // "sig_openExcelFile"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "tableSaveToExcel"
QT_MOC_LITERAL(4, 53, 13), // "QTableWidget*"
QT_MOC_LITERAL(5, 67, 5), // "table"
QT_MOC_LITERAL(6, 73, 5), // "title"
QT_MOC_LITERAL(7, 79, 8) // "fileName"

    },
    "TableSaveToExcel\0sig_openExcelFile\0\0"
    "tableSaveToExcel\0QTableWidget*\0table\0"
    "title\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableSaveToExcel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, QMetaType::QString,    5,    6,    7,

       0        // eod
};

void TableSaveToExcel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TableSaveToExcel *_t = static_cast<TableSaveToExcel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_openExcelFile(); break;
        case 1: _t->tableSaveToExcel((*reinterpret_cast< QTableWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTableWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (TableSaveToExcel::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TableSaveToExcel::sig_openExcelFile)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TableSaveToExcel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TableSaveToExcel.data,
      qt_meta_data_TableSaveToExcel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TableSaveToExcel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableSaveToExcel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TableSaveToExcel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TableSaveToExcel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TableSaveToExcel::sig_openExcelFile()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

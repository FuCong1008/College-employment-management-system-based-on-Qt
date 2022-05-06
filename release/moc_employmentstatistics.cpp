/****************************************************************************
** Meta object code from reading C++ file 'employmentstatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubScreen/employmentstatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employmentstatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EmploymentStatistics_t {
    QByteArrayData data[10];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmploymentStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmploymentStatistics_t qt_meta_stringdata_EmploymentStatistics = {
    {
QT_MOC_LITERAL(0, 0, 20), // "EmploymentStatistics"
QT_MOC_LITERAL(1, 21, 25), // "slot_showTableItemToolTip"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 5), // "index"
QT_MOC_LITERAL(4, 54, 27), // "slot_btn_lookDetail_clicked"
QT_MOC_LITERAL(5, 82, 20), // "on_tbn_major_clicked"
QT_MOC_LITERAL(6, 103, 20), // "on_tbn_class_clicked"
QT_MOC_LITERAL(7, 124, 19), // "on_tbn_post_clicked"
QT_MOC_LITERAL(8, 144, 22), // "on_tbn_company_clicked"
QT_MOC_LITERAL(9, 167, 19) // "on_tbn_city_clicked"

    },
    "EmploymentStatistics\0slot_showTableItemToolTip\0"
    "\0index\0slot_btn_lookDetail_clicked\0"
    "on_tbn_major_clicked\0on_tbn_class_clicked\0"
    "on_tbn_post_clicked\0on_tbn_company_clicked\0"
    "on_tbn_city_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmploymentStatistics[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EmploymentStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmploymentStatistics *_t = static_cast<EmploymentStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showTableItemToolTip((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->slot_btn_lookDetail_clicked(); break;
        case 2: _t->on_tbn_major_clicked(); break;
        case 3: _t->on_tbn_class_clicked(); break;
        case 4: _t->on_tbn_post_clicked(); break;
        case 5: _t->on_tbn_company_clicked(); break;
        case 6: _t->on_tbn_city_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject EmploymentStatistics::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmploymentStatistics.data,
      qt_meta_data_EmploymentStatistics,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EmploymentStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmploymentStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmploymentStatistics.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EmploymentStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

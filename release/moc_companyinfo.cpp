/****************************************************************************
** Meta object code from reading C++ file 'companyinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubScreen/companyinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'companyinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CompanyInfo_t {
    QByteArrayData data[16];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CompanyInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CompanyInfo_t qt_meta_stringdata_CompanyInfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CompanyInfo"
QT_MOC_LITERAL(1, 12, 25), // "slot_showTableItemToolTip"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "index"
QT_MOC_LITERAL(4, 45, 23), // "slot_tableWidgetAddItem"
QT_MOC_LITERAL(5, 69, 21), // "VariableSet::Company&"
QT_MOC_LITERAL(6, 91, 3), // "com"
QT_MOC_LITERAL(7, 95, 43), // "slot_tableWidget_customContex..."
QT_MOC_LITERAL(8, 139, 3), // "pos"
QT_MOC_LITERAL(9, 143, 24), // "slot_ActionDeliverResume"
QT_MOC_LITERAL(10, 168, 20), // "slot_delCurRowRecord"
QT_MOC_LITERAL(11, 189, 22), // "slot_alterCurRowRecord"
QT_MOC_LITERAL(12, 212, 21), // "slot_saveCurRowRecord"
QT_MOC_LITERAL(13, 234, 25), // "on_btn_addCompany_clicked"
QT_MOC_LITERAL(14, 260, 26), // "on_btn_saveToExcel_clicked"
QT_MOC_LITERAL(15, 287, 34) // "on_tableWidget_companyInfo_cl..."

    },
    "CompanyInfo\0slot_showTableItemToolTip\0"
    "\0index\0slot_tableWidgetAddItem\0"
    "VariableSet::Company&\0com\0"
    "slot_tableWidget_customContextMenuRequested\0"
    "pos\0slot_ActionDeliverResume\0"
    "slot_delCurRowRecord\0slot_alterCurRowRecord\0"
    "slot_saveCurRowRecord\0on_btn_addCompany_clicked\0"
    "on_btn_saveToExcel_clicked\0"
    "on_tableWidget_companyInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CompanyInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       9,    0,   73,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    1,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void CompanyInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CompanyInfo *_t = static_cast<CompanyInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showTableItemToolTip((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->slot_tableWidgetAddItem((*reinterpret_cast< VariableSet::Company(*)>(_a[1]))); break;
        case 2: _t->slot_tableWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->slot_ActionDeliverResume(); break;
        case 4: _t->slot_delCurRowRecord(); break;
        case 5: _t->slot_alterCurRowRecord(); break;
        case 6: _t->slot_saveCurRowRecord(); break;
        case 7: _t->on_btn_addCompany_clicked(); break;
        case 8: _t->on_btn_saveToExcel_clicked(); break;
        case 9: _t->on_tableWidget_companyInfo_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CompanyInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CompanyInfo.data,
      qt_meta_data_CompanyInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CompanyInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CompanyInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CompanyInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CompanyInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

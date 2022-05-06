/****************************************************************************
** Meta object code from reading C++ file 'employmentinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubScreen/employmentinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'employmentinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EmploymentInfo_t {
    QByteArrayData data[15];
    char stringdata0[319];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmploymentInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmploymentInfo_t qt_meta_stringdata_EmploymentInfo = {
    {
QT_MOC_LITERAL(0, 0, 14), // "EmploymentInfo"
QT_MOC_LITERAL(1, 15, 25), // "slot_showTableItemToolTip"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "index"
QT_MOC_LITERAL(4, 48, 23), // "slot_tableWidgetAddItem"
QT_MOC_LITERAL(5, 72, 25), // "VariableSet::Stu_Company&"
QT_MOC_LITERAL(6, 98, 6), // "stuCom"
QT_MOC_LITERAL(7, 105, 32), // "on_btn_addEmploymentInfo_clicked"
QT_MOC_LITERAL(8, 138, 20), // "on_btn_reset_clicked"
QT_MOC_LITERAL(9, 159, 37), // "on_combox_province_currentTex..."
QT_MOC_LITERAL(10, 197, 4), // "arg1"
QT_MOC_LITERAL(11, 202, 20), // "on_btn_query_clicked"
QT_MOC_LITERAL(12, 223, 36), // "on_combox_faculty_currentText..."
QT_MOC_LITERAL(13, 260, 26), // "on_btn_saveToExcel_clicked"
QT_MOC_LITERAL(14, 287, 31) // "on_tableWidget_workInfo_clicked"

    },
    "EmploymentInfo\0slot_showTableItemToolTip\0"
    "\0index\0slot_tableWidgetAddItem\0"
    "VariableSet::Stu_Company&\0stuCom\0"
    "on_btn_addEmploymentInfo_clicked\0"
    "on_btn_reset_clicked\0"
    "on_combox_province_currentTextChanged\0"
    "arg1\0on_btn_query_clicked\0"
    "on_combox_faculty_currentTextChanged\0"
    "on_btn_saveToExcel_clicked\0"
    "on_tableWidget_workInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmploymentInfo[] = {

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
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    1,   67,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,
      13,    0,   74,    2, 0x08 /* Private */,
      14,    1,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void EmploymentInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmploymentInfo *_t = static_cast<EmploymentInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showTableItemToolTip((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->slot_tableWidgetAddItem((*reinterpret_cast< VariableSet::Stu_Company(*)>(_a[1]))); break;
        case 2: _t->on_btn_addEmploymentInfo_clicked(); break;
        case 3: _t->on_btn_reset_clicked(); break;
        case 4: _t->on_combox_province_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_btn_query_clicked(); break;
        case 6: _t->on_combox_faculty_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_btn_saveToExcel_clicked(); break;
        case 8: _t->on_tableWidget_workInfo_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EmploymentInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EmploymentInfo.data,
      qt_meta_data_EmploymentInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EmploymentInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmploymentInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EmploymentInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EmploymentInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE

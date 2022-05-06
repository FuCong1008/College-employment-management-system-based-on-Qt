/****************************************************************************
** Meta object code from reading C++ file 'studentinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubScreen/studentinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'studentinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StudentInfo_t {
    QByteArrayData data[18];
    char stringdata0[360];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StudentInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StudentInfo_t qt_meta_stringdata_StudentInfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "StudentInfo"
QT_MOC_LITERAL(1, 12, 25), // "slot_showTableItemToolTip"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5), // "index"
QT_MOC_LITERAL(4, 45, 23), // "slot_tableWidgetAddItem"
QT_MOC_LITERAL(5, 69, 21), // "VariableSet::Student&"
QT_MOC_LITERAL(6, 91, 3), // "stu"
QT_MOC_LITERAL(7, 95, 43), // "slot_tableWidget_customContex..."
QT_MOC_LITERAL(8, 139, 3), // "pos"
QT_MOC_LITERAL(9, 143, 20), // "slot_delCurRowRecord"
QT_MOC_LITERAL(10, 164, 22), // "slot_alterCurRowRecord"
QT_MOC_LITERAL(11, 187, 21), // "slot_saveCurRowRecord"
QT_MOC_LITERAL(12, 209, 23), // "slot_queryEmploymentStu"
QT_MOC_LITERAL(13, 233, 26), // "slot_queryNotEmploymentStu"
QT_MOC_LITERAL(14, 260, 15), // "slot_resetTable"
QT_MOC_LITERAL(15, 276, 21), // "on_btn_addStu_clicked"
QT_MOC_LITERAL(16, 298, 26), // "on_btn_saveToExcel_clicked"
QT_MOC_LITERAL(17, 325, 34) // "on_tableWidget_studentInfo_cl..."

    },
    "StudentInfo\0slot_showTableItemToolTip\0"
    "\0index\0slot_tableWidgetAddItem\0"
    "VariableSet::Student&\0stu\0"
    "slot_tableWidget_customContextMenuRequested\0"
    "pos\0slot_delCurRowRecord\0"
    "slot_alterCurRowRecord\0slot_saveCurRowRecord\0"
    "slot_queryEmploymentStu\0"
    "slot_queryNotEmploymentStu\0slot_resetTable\0"
    "on_btn_addStu_clicked\0on_btn_saveToExcel_clicked\0"
    "on_tableWidget_studentInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StudentInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    3,

       0        // eod
};

void StudentInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StudentInfo *_t = static_cast<StudentInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slot_showTableItemToolTip((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->slot_tableWidgetAddItem((*reinterpret_cast< VariableSet::Student(*)>(_a[1]))); break;
        case 2: _t->slot_tableWidget_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->slot_delCurRowRecord(); break;
        case 4: _t->slot_alterCurRowRecord(); break;
        case 5: _t->slot_saveCurRowRecord(); break;
        case 6: _t->slot_queryEmploymentStu(); break;
        case 7: _t->slot_queryNotEmploymentStu(); break;
        case 8: _t->slot_resetTable(); break;
        case 9: _t->on_btn_addStu_clicked(); break;
        case 10: _t->on_btn_saveToExcel_clicked(); break;
        case 11: _t->on_tableWidget_studentInfo_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject StudentInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StudentInfo.data,
      qt_meta_data_StudentInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StudentInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StudentInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StudentInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StudentInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

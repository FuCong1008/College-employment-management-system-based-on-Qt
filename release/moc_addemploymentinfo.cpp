/****************************************************************************
** Meta object code from reading C++ file 'addemploymentinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubScreen/addemploymentinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addemploymentinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddEmploymentInfo_t {
    QByteArrayData data[10];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddEmploymentInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddEmploymentInfo_t qt_meta_stringdata_AddEmploymentInfo = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AddEmploymentInfo"
QT_MOC_LITERAL(1, 18, 18), // "sig_employmentInfo"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 25), // "VariableSet::Stu_Company&"
QT_MOC_LITERAL(4, 64, 6), // "stuCom"
QT_MOC_LITERAL(5, 71, 20), // "on_btn_reset_clicked"
QT_MOC_LITERAL(6, 92, 21), // "on_btn_submit_clicked"
QT_MOC_LITERAL(7, 114, 36), // "on_combox_faculty_currentText..."
QT_MOC_LITERAL(8, 151, 4), // "arg1"
QT_MOC_LITERAL(9, 156, 40) // "on_combox_subProvince_current..."

    },
    "AddEmploymentInfo\0sig_employmentInfo\0"
    "\0VariableSet::Stu_Company&\0stuCom\0"
    "on_btn_reset_clicked\0on_btn_submit_clicked\0"
    "on_combox_faculty_currentTextChanged\0"
    "arg1\0on_combox_subProvince_currentTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddEmploymentInfo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    1,   44,    2, 0x08 /* Private */,
       9,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void AddEmploymentInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddEmploymentInfo *_t = static_cast<AddEmploymentInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_employmentInfo((*reinterpret_cast< VariableSet::Stu_Company(*)>(_a[1]))); break;
        case 1: _t->on_btn_reset_clicked(); break;
        case 2: _t->on_btn_submit_clicked(); break;
        case 3: _t->on_combox_faculty_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_combox_subProvince_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AddEmploymentInfo::*_t)(VariableSet::Stu_Company & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddEmploymentInfo::sig_employmentInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddEmploymentInfo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddEmploymentInfo.data,
      qt_meta_data_AddEmploymentInfo,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddEmploymentInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddEmploymentInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddEmploymentInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddEmploymentInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AddEmploymentInfo::sig_employmentInfo(VariableSet::Stu_Company & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

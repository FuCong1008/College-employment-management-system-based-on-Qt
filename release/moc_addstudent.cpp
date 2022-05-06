/****************************************************************************
** Meta object code from reading C++ file 'addstudent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SubScreen/addstudent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addstudent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddStudent_t {
    QByteArrayData data[9];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddStudent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddStudent_t qt_meta_stringdata_AddStudent = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AddStudent"
QT_MOC_LITERAL(1, 11, 15), // "sig_studentInfo"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 21), // "VariableSet::Student&"
QT_MOC_LITERAL(4, 50, 3), // "stu"
QT_MOC_LITERAL(5, 54, 21), // "on_btn_submit_clicked"
QT_MOC_LITERAL(6, 76, 20), // "on_btn_reset_clicked"
QT_MOC_LITERAL(7, 97, 36), // "on_combox_faculty_currentText..."
QT_MOC_LITERAL(8, 134, 4) // "arg1"

    },
    "AddStudent\0sig_studentInfo\0\0"
    "VariableSet::Student&\0stu\0"
    "on_btn_submit_clicked\0on_btn_reset_clicked\0"
    "on_combox_faculty_currentTextChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddStudent[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x08 /* Private */,
       6,    0,   38,    2, 0x08 /* Private */,
       7,    1,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void AddStudent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddStudent *_t = static_cast<AddStudent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_studentInfo((*reinterpret_cast< VariableSet::Student(*)>(_a[1]))); break;
        case 1: _t->on_btn_submit_clicked(); break;
        case 2: _t->on_btn_reset_clicked(); break;
        case 3: _t->on_combox_faculty_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AddStudent::*_t)(VariableSet::Student & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddStudent::sig_studentInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject AddStudent::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddStudent.data,
      qt_meta_data_AddStudent,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddStudent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddStudent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddStudent.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddStudent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddStudent::sig_studentInfo(VariableSet::Student & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

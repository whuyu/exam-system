/****************************************************************************
** Meta object code from reading C++ file 'teacherquestion.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../teacherquestion.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'teacherquestion.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_teacherquestion_t {
    QByteArrayData data[9];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_teacherquestion_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_teacherquestion_t qt_meta_stringdata_teacherquestion = {
    {
QT_MOC_LITERAL(0, 0, 15), // "teacherquestion"
QT_MOC_LITERAL(1, 16, 11), // "showteacher"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "receivelogin"
QT_MOC_LITERAL(4, 42, 25), // "on_questionSelect_clicked"
QT_MOC_LITERAL(5, 68, 24), // "on_questionBlank_clicked"
QT_MOC_LITERAL(6, 93, 25), // "on_questionAnswer_clicked"
QT_MOC_LITERAL(7, 119, 17), // "on_Return_clicked"
QT_MOC_LITERAL(8, 137, 31) // "on_importSelectquestion_clicked"

    },
    "teacherquestion\0showteacher\0\0receivelogin\0"
    "on_questionSelect_clicked\0"
    "on_questionBlank_clicked\0"
    "on_questionAnswer_clicked\0on_Return_clicked\0"
    "on_importSelectquestion_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_teacherquestion[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void teacherquestion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        teacherquestion *_t = static_cast<teacherquestion *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showteacher(); break;
        case 1: _t->receivelogin(); break;
        case 2: _t->on_questionSelect_clicked(); break;
        case 3: _t->on_questionBlank_clicked(); break;
        case 4: _t->on_questionAnswer_clicked(); break;
        case 5: _t->on_Return_clicked(); break;
        case 6: _t->on_importSelectquestion_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (teacherquestion::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&teacherquestion::showteacher)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject teacherquestion::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_teacherquestion.data,
      qt_meta_data_teacherquestion,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *teacherquestion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *teacherquestion::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_teacherquestion.stringdata0))
        return static_cast<void*>(const_cast< teacherquestion*>(this));
    return QWidget::qt_metacast(_clname);
}

int teacherquestion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void teacherquestion::showteacher()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
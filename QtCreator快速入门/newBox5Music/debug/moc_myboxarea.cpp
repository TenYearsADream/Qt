/****************************************************************************
** Meta object code from reading C++ file 'myboxarea.h'
**
** Created: Sat Apr 17 14:12:03 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../myboxarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myboxarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyBoxArea[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      21,   10,   10,   10, 0x05,
      32,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   10,   10,   10, 0x0a,
      64,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyBoxArea[] = {
    "MyBoxArea\0\0moveEnd()\0gameOver()\0"
    "fullRowNumChange(int)\0newItem()\0"
    "boxMoveOneStepDown()\0"
};

const QMetaObject MyBoxArea::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_MyBoxArea,
      qt_meta_data_MyBoxArea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyBoxArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyBoxArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyBoxArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyBoxArea))
        return static_cast<void*>(const_cast< MyBoxArea*>(this));
    return QFrame::qt_metacast(_clname);
}

int MyBoxArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moveEnd(); break;
        case 1: gameOver(); break;
        case 2: fullRowNumChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: newItem(); break;
        case 4: boxMoveOneStepDown(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void MyBoxArea::moveEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MyBoxArea::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MyBoxArea::fullRowNumChange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

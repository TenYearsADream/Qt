/****************************************************************************
** Meta object code from reading C++ file 'mybox.h'
**
** Created: Thu Apr 29 17:25:35 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mybox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mybox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyBox[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,    7,    6,    6, 0x08,
      53,    7,    6,    6, 0x08,
      91,    6,    6,    6, 0x08,
     123,    6,    6,    6, 0x08,
     150,    6,    6,    6, 0x08,
     176,    6,    6,    6, 0x08,
     209,    6,    6,    6, 0x08,
     234,    6,    6,    6, 0x08,
     260,    6,    6,    6, 0x08,
     281,    6,    6,    6, 0x08,
     303,    6,    6,    6, 0x08,
     327,    6,    6,    6, 0x08,
     350,    6,    6,    6, 0x08,
     380,    6,    6,    6, 0x08,
     400,    6,    6,    6, 0x08,
     439,    6,    6,    6, 0x08,
     461,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyBox[] = {
    "MyBox\0\0value\0on_horizontalSlider_2_valueChanged(int)\0"
    "on_horizontalSlider_valueChanged(int)\0"
    "on_downKeyRadioButton_clicked()\0"
    "on_backOptionBtn_clicked()\0"
    "on_setOptionBtn_clicked()\0"
    "on_gameGridRadioButton_clicked()\0"
    "on_gameExitBtn_clicked()\0"
    "on_gameStartBtn_clicked()\0"
    "on_backBtn_clicked()\0on_pauseBtn_clicked()\0"
    "on_reStartBtn_clicked()\0boxMove_timer_UpDate()\0"
    "gameAreaRotate_timer_UpDate()\0"
    "mask_timer_UpDate()\0"
    "gameAreaFrame_lineWidth_timer_UpDate()\0"
    "second_timer_UpDate()\0loopMusic()\0"
};

const QMetaObject MyBox::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyBox,
      qt_meta_data_MyBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyBox))
        return static_cast<void*>(const_cast< MyBox*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: on_downKeyRadioButton_clicked(); break;
        case 3: on_backOptionBtn_clicked(); break;
        case 4: on_setOptionBtn_clicked(); break;
        case 5: on_gameGridRadioButton_clicked(); break;
        case 6: on_gameExitBtn_clicked(); break;
        case 7: on_gameStartBtn_clicked(); break;
        case 8: on_backBtn_clicked(); break;
        case 9: on_pauseBtn_clicked(); break;
        case 10: on_reStartBtn_clicked(); break;
        case 11: boxMove_timer_UpDate(); break;
        case 12: gameAreaRotate_timer_UpDate(); break;
        case 13: mask_timer_UpDate(); break;
        case 14: gameAreaFrame_lineWidth_timer_UpDate(); break;
        case 15: second_timer_UpDate(); break;
        case 16: loopMusic(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

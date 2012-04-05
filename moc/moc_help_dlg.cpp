/****************************************************************************
** Meta object code from reading C++ file 'help_dlg.h'
**
** Created: Sat 31. Mar 16:34:54 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../help_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'help_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_help_dlg[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_help_dlg[] = {
    "help_dlg\0\0on_pushButton_ok_clicked()\0"
};

const QMetaObject help_dlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_help_dlg,
      qt_meta_data_help_dlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &help_dlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *help_dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *help_dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_help_dlg))
        return static_cast<void*>(const_cast< help_dlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int help_dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButton_ok_clicked(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'categories_dlg.h'
**
** Created: Sat 31. Mar 16:34:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../categories_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'categories_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_categories_dlg[] = {

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
      22,   16,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_categories_dlg[] = {
    "categories_dlg\0\0index\0"
    "on_listWidget_categories_clicked(QModelIndex)\0"
};

const QMetaObject categories_dlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_categories_dlg,
      qt_meta_data_categories_dlg, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &categories_dlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *categories_dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *categories_dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_categories_dlg))
        return static_cast<void*>(const_cast< categories_dlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int categories_dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_listWidget_categories_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

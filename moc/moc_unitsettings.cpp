/****************************************************************************
** Meta object code from reading C++ file 'unitsettings.h'
**
** Created: Sat 31. Mar 16:34:52 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../unitsettings.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unitsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UnitSettings[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      35,   13,   13,   13, 0x08,
      73,   13,   13,   13, 0x08,
     114,   13,   13,   13, 0x08,
     141,   13,   13,   13, 0x08,
     224,  172,   13,   13, 0x08,
     297,  286,   13,   13, 0x08,
     344,   13,   13,   13, 0x08,
     377,  286,   13,   13, 0x08,
     419,   13,   13,   13, 0x08,
     455,  172,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UnitSettings[] = {
    "UnitSettings\0\0setListWidgetUnits()\0"
    "on_pushButton_NewCategories_clicked()\0"
    "on_pushButton_DeleteCategories_clicked()\0"
    "on_pushButton_ok_clicked()\0"
    "on_pushButton_cancel_clicked()\0"
    "currentRow,currentColumn,previousRow,previousColumn\0"
    "on_tableWidget_categories_currentCellChanged(int,int,int,int)\0"
    "row,column\0on_tableWidget_categories_cellChanged(int,int)\0"
    "on_pushButton_NewUnits_clicked()\0"
    "on_tableWidget_units_cellChanged(int,int)\0"
    "on_pushButton_DeleteUnits_clicked()\0"
    "on_tableWidget_units_currentCellChanged(int,int,int,int)\0"
};

const QMetaObject UnitSettings::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UnitSettings,
      qt_meta_data_UnitSettings, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UnitSettings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UnitSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UnitSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UnitSettings))
        return static_cast<void*>(const_cast< UnitSettings*>(this));
    return QDialog::qt_metacast(_clname);
}

int UnitSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setListWidgetUnits(); break;
        case 1: on_pushButton_NewCategories_clicked(); break;
        case 2: on_pushButton_DeleteCategories_clicked(); break;
        case 3: on_pushButton_ok_clicked(); break;
        case 4: on_pushButton_cancel_clicked(); break;
        case 5: on_tableWidget_categories_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: on_tableWidget_categories_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: on_pushButton_NewUnits_clicked(); break;
        case 8: on_tableWidget_units_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: on_pushButton_DeleteUnits_clicked(); break;
        case 10: on_tableWidget_units_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

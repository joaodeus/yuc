/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat 31. Mar 16:34:51 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      46,   41,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     232,   11,   11,   11, 0x08,
     259,   11,   11,   11, 0x08,
     291,   11,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     360,   11,   11,   11, 0x08,
     391,   11,   11,   11, 0x08,
     419,   11,   11,   11, 0x08,
     446,   11,   11,   11, 0x08,
     472,   11,   11,   11, 0x08,
     501,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0event\0showEvent(QShowEvent*)\0"
    "item\0on_tableWidget_units_results_itemChanged(QTableWidgetItem*)\0"
    "setTextfromBtnClicked(QString)\0"
    "clicked_del()\0clicked_clear()\0"
    "on_pushButton_categories_clicked()\0"
    "on_actionSettings_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_actionCategories_triggered()\0"
    "on_pushButton_show_hide_clicked()\0"
    "on_pushButton_plus_minus_clicked()\0"
    "on_pushButton_update_clicked()\0"
    "on_actionFormat_triggered()\0"
    "on_actionReset_triggered()\0"
    "on_actionHelp_triggered()\0"
    "on_pushButton_exit_clicked()\0"
    "on_pushButton_settings_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 1: on_tableWidget_units_results_itemChanged((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: setTextfromBtnClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: clicked_del(); break;
        case 4: clicked_clear(); break;
        case 5: on_pushButton_categories_clicked(); break;
        case 6: on_actionSettings_triggered(); break;
        case 7: on_actionAbout_triggered(); break;
        case 8: on_actionCategories_triggered(); break;
        case 9: on_pushButton_show_hide_clicked(); break;
        case 10: on_pushButton_plus_minus_clicked(); break;
        case 11: on_pushButton_update_clicked(); break;
        case 12: on_actionFormat_triggered(); break;
        case 13: on_actionReset_triggered(); break;
        case 14: on_actionHelp_triggered(); break;
        case 15: on_pushButton_exit_clicked(); break;
        case 16: on_pushButton_settings_clicked(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

/********************************************************************************
** Form generated from reading UI file 'unitsettings.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITSETTINGS_H
#define UI_UNITSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_UnitSettings
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_NewCategories;
    QPushButton *pushButton_DeleteCategories;
    QTableWidget *tableWidget_categories;
    QPushButton *pushButton_NewUnits;
    QPushButton *pushButton_DeleteUnits;
    QTableWidget *tableWidget_units;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *UnitSettings)
    {
        if (UnitSettings->objectName().isEmpty())
            UnitSettings->setObjectName(QString::fromUtf8("UnitSettings"));
        UnitSettings->resize(268, 392);
        gridLayout = new QGridLayout(UnitSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_NewCategories = new QPushButton(UnitSettings);
        pushButton_NewCategories->setObjectName(QString::fromUtf8("pushButton_NewCategories"));

        gridLayout->addWidget(pushButton_NewCategories, 0, 0, 1, 1);

        pushButton_DeleteCategories = new QPushButton(UnitSettings);
        pushButton_DeleteCategories->setObjectName(QString::fromUtf8("pushButton_DeleteCategories"));

        gridLayout->addWidget(pushButton_DeleteCategories, 0, 1, 1, 1);

        tableWidget_categories = new QTableWidget(UnitSettings);
        tableWidget_categories->setObjectName(QString::fromUtf8("tableWidget_categories"));
        tableWidget_categories->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_categories->setSortingEnabled(false);
        tableWidget_categories->setRowCount(0);
        tableWidget_categories->setColumnCount(0);

        gridLayout->addWidget(tableWidget_categories, 1, 0, 1, 2);

        pushButton_NewUnits = new QPushButton(UnitSettings);
        pushButton_NewUnits->setObjectName(QString::fromUtf8("pushButton_NewUnits"));

        gridLayout->addWidget(pushButton_NewUnits, 2, 0, 1, 1);

        pushButton_DeleteUnits = new QPushButton(UnitSettings);
        pushButton_DeleteUnits->setObjectName(QString::fromUtf8("pushButton_DeleteUnits"));

        gridLayout->addWidget(pushButton_DeleteUnits, 2, 1, 1, 1);

        tableWidget_units = new QTableWidget(UnitSettings);
        tableWidget_units->setObjectName(QString::fromUtf8("tableWidget_units"));
        tableWidget_units->setSortingEnabled(false);

        gridLayout->addWidget(tableWidget_units, 3, 0, 1, 2);

        pushButton_ok = new QPushButton(UnitSettings);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        gridLayout->addWidget(pushButton_ok, 4, 0, 1, 1);

        pushButton_cancel = new QPushButton(UnitSettings);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        gridLayout->addWidget(pushButton_cancel, 4, 1, 1, 1);


        retranslateUi(UnitSettings);

        QMetaObject::connectSlotsByName(UnitSettings);
    } // setupUi

    void retranslateUi(QDialog *UnitSettings)
    {
        UnitSettings->setWindowTitle(QApplication::translate("UnitSettings", "Settings", 0, QApplication::UnicodeUTF8));
        pushButton_NewCategories->setText(QApplication::translate("UnitSettings", "New", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteCategories->setText(QApplication::translate("UnitSettings", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_NewUnits->setText(QApplication::translate("UnitSettings", "New", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteUnits->setText(QApplication::translate("UnitSettings", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("UnitSettings", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("UnitSettings", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UnitSettings: public Ui_UnitSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITSETTINGS_H

/********************************************************************************
** Form generated from reading UI file 'unitsettings.ui'
**
** Created: Fri 6. Jan 20:19:43 2012
**      by: Qt User Interface Compiler version 4.7.4
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
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UnitSettings
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_categories;
    QGridLayout *gridLayout;
    QPushButton *pushButton_NewCategories;
    QPushButton *pushButton_DeleteCategories;
    QListWidget *listWidget;
    QGroupBox *groupBox_units;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_NewUnits;
    QPushButton *pushButton_DeleteUnits;
    QListWidget *listWidget_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UnitSettings)
    {
        if (UnitSettings->objectName().isEmpty())
            UnitSettings->setObjectName(QString::fromUtf8("UnitSettings"));
        UnitSettings->resize(269, 416);
        gridLayout_3 = new QGridLayout(UnitSettings);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_categories = new QGroupBox(UnitSettings);
        groupBox_categories->setObjectName(QString::fromUtf8("groupBox_categories"));
        gridLayout = new QGridLayout(groupBox_categories);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_NewCategories = new QPushButton(groupBox_categories);
        pushButton_NewCategories->setObjectName(QString::fromUtf8("pushButton_NewCategories"));

        gridLayout->addWidget(pushButton_NewCategories, 0, 0, 1, 1);

        pushButton_DeleteCategories = new QPushButton(groupBox_categories);
        pushButton_DeleteCategories->setObjectName(QString::fromUtf8("pushButton_DeleteCategories"));

        gridLayout->addWidget(pushButton_DeleteCategories, 0, 1, 1, 1);

        listWidget = new QListWidget(groupBox_categories);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_categories, 0, 0, 1, 1);

        groupBox_units = new QGroupBox(UnitSettings);
        groupBox_units->setObjectName(QString::fromUtf8("groupBox_units"));
        gridLayout_2 = new QGridLayout(groupBox_units);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_NewUnits = new QPushButton(groupBox_units);
        pushButton_NewUnits->setObjectName(QString::fromUtf8("pushButton_NewUnits"));

        gridLayout_2->addWidget(pushButton_NewUnits, 0, 0, 1, 1);

        pushButton_DeleteUnits = new QPushButton(groupBox_units);
        pushButton_DeleteUnits->setObjectName(QString::fromUtf8("pushButton_DeleteUnits"));

        gridLayout_2->addWidget(pushButton_DeleteUnits, 0, 1, 1, 1);

        listWidget_2 = new QListWidget(groupBox_units);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        gridLayout_2->addWidget(listWidget_2, 1, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_units, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(UnitSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(UnitSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), UnitSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UnitSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(UnitSettings);
    } // setupUi

    void retranslateUi(QDialog *UnitSettings)
    {
        UnitSettings->setWindowTitle(QApplication::translate("UnitSettings", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_categories->setTitle(QApplication::translate("UnitSettings", "Categories", 0, QApplication::UnicodeUTF8));
        pushButton_NewCategories->setText(QApplication::translate("UnitSettings", "New", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteCategories->setText(QApplication::translate("UnitSettings", "Delete", 0, QApplication::UnicodeUTF8));
        groupBox_units->setTitle(QApplication::translate("UnitSettings", "Units", 0, QApplication::UnicodeUTF8));
        pushButton_NewUnits->setText(QApplication::translate("UnitSettings", "New", 0, QApplication::UnicodeUTF8));
        pushButton_DeleteUnits->setText(QApplication::translate("UnitSettings", "Delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UnitSettings: public Ui_UnitSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITSETTINGS_H

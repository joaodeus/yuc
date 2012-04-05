/********************************************************************************
** Form generated from reading UI file 'settings_dlg.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_DLG_H
#define UI_SETTINGS_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_settings_dlg
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget;

    void setupUi(QDialog *settings_dlg)
    {
        if (settings_dlg->objectName().isEmpty())
            settings_dlg->setObjectName(QString::fromUtf8("settings_dlg"));
        settings_dlg->resize(255, 305);
        gridLayout = new QGridLayout(settings_dlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(settings_dlg);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);


        retranslateUi(settings_dlg);

        QMetaObject::connectSlotsByName(settings_dlg);
    } // setupUi

    void retranslateUi(QDialog *settings_dlg)
    {
        settings_dlg->setWindowTitle(QApplication::translate("settings_dlg", "Settings", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("settings_dlg", "Edit units", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("settings_dlg", "Reset", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("settings_dlg", "Help", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("settings_dlg", "About", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class settings_dlg: public Ui_settings_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_DLG_H

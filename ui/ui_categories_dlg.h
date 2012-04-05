/********************************************************************************
** Form generated from reading UI file 'categories_dlg.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORIES_DLG_H
#define UI_CATEGORIES_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_categories_dlg
{
public:
    QGridLayout *gridLayout;
    QListWidget *listWidget_categories;

    void setupUi(QDialog *categories_dlg)
    {
        if (categories_dlg->objectName().isEmpty())
            categories_dlg->setObjectName(QString::fromUtf8("categories_dlg"));
        categories_dlg->resize(216, 291);
        gridLayout = new QGridLayout(categories_dlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget_categories = new QListWidget(categories_dlg);
        listWidget_categories->setObjectName(QString::fromUtf8("listWidget_categories"));
        listWidget_categories->setSortingEnabled(false);

        gridLayout->addWidget(listWidget_categories, 0, 0, 1, 1);


        retranslateUi(categories_dlg);

        QMetaObject::connectSlotsByName(categories_dlg);
    } // setupUi

    void retranslateUi(QDialog *categories_dlg)
    {
        categories_dlg->setWindowTitle(QApplication::translate("categories_dlg", "Categories", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class categories_dlg: public Ui_categories_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORIES_DLG_H

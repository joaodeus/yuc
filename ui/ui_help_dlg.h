/********************************************************************************
** Form generated from reading UI file 'help_dlg.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_DLG_H
#define UI_HELP_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include "QtWebKit/QWebView"

QT_BEGIN_NAMESPACE

class Ui_help_dlg
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *help_dlg)
    {
        if (help_dlg->objectName().isEmpty())
            help_dlg->setObjectName(QString::fromUtf8("help_dlg"));
        help_dlg->resize(327, 398);
        gridLayout = new QGridLayout(help_dlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(help_dlg);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("qrc:/help/Yuc.html"));

        gridLayout->addWidget(webView, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(225, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_ok = new QPushButton(help_dlg);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        gridLayout->addWidget(pushButton_ok, 1, 1, 1, 1);


        retranslateUi(help_dlg);

        QMetaObject::connectSlotsByName(help_dlg);
    } // setupUi

    void retranslateUi(QDialog *help_dlg)
    {
        help_dlg->setWindowTitle(QApplication::translate("help_dlg", "Help", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("help_dlg", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class help_dlg: public Ui_help_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_DLG_H

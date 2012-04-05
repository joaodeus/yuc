/********************************************************************************
** Form generated from reading UI file 'about_dlg.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_DLG_H
#define UI_ABOUT_DLG_H

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

class Ui_About_Dlg
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;

    void setupUi(QDialog *About_Dlg)
    {
        if (About_Dlg->objectName().isEmpty())
            About_Dlg->setObjectName(QString::fromUtf8("About_Dlg"));
        About_Dlg->resize(325, 413);
        gridLayout = new QGridLayout(About_Dlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(About_Dlg);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("qrc:/help/about.html"));

        gridLayout->addWidget(webView, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(223, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pushButton_ok = new QPushButton(About_Dlg);
        pushButton_ok->setObjectName(QString::fromUtf8("pushButton_ok"));

        gridLayout->addWidget(pushButton_ok, 1, 1, 1, 1);


        retranslateUi(About_Dlg);

        QMetaObject::connectSlotsByName(About_Dlg);
    } // setupUi

    void retranslateUi(QDialog *About_Dlg)
    {
        About_Dlg->setWindowTitle(QApplication::translate("About_Dlg", "About", 0, QApplication::UnicodeUTF8));
        pushButton_ok->setText(QApplication::translate("About_Dlg", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class About_Dlg: public Ui_About_Dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_DLG_H

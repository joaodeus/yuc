/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionFormat;
    QAction *actionReset;
    QAction *actionHelp;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame_keypad;
    QGridLayout *gridLayout;
    QPushButton *pushButton_0;
    QPushButton *pushButton_5;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_E;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_del;
    QPushButton *pushButton_clear;
    QTableWidget *tableWidget_units_results;
    QPushButton *pushButton_categories;
    QPushButton *pushButton_plus_minus;
    QPushButton *pushButton_update;
    QPushButton *pushButton_show_hide;
    QPushButton *pushButton_settings;
    QPushButton *pushButton_exit;
    QMenuBar *menuBar;
    QMenu *menuSettings_2;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(275, 381);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionFormat = new QAction(MainWindow);
        actionFormat->setObjectName(QString::fromUtf8("actionFormat"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame_keypad = new QFrame(centralWidget);
        frame_keypad->setObjectName(QString::fromUtf8("frame_keypad"));
        frame_keypad->setFrameShape(QFrame::StyledPanel);
        frame_keypad->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_keypad);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_0 = new QPushButton(frame_keypad);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_0, 5, 0, 1, 1);

        pushButton_5 = new QPushButton(frame_keypad);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_5, 3, 1, 1, 1);

        pushButton_dot = new QPushButton(frame_keypad);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        sizePolicy.setHeightForWidth(pushButton_dot->sizePolicy().hasHeightForWidth());
        pushButton_dot->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_dot, 5, 1, 1, 1);

        pushButton_6 = new QPushButton(frame_keypad);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_6, 3, 2, 1, 1);

        pushButton_8 = new QPushButton(frame_keypad);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_3 = new QPushButton(frame_keypad);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_3, 4, 2, 1, 1);

        pushButton_7 = new QPushButton(frame_keypad);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(frame_keypad);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_4 = new QPushButton(frame_keypad);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_1 = new QPushButton(frame_keypad);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_1, 4, 0, 1, 1);

        pushButton_2 = new QPushButton(frame_keypad);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_2, 4, 1, 1, 1);

        pushButton_E = new QPushButton(frame_keypad);
        pushButton_E->setObjectName(QString::fromUtf8("pushButton_E"));

        gridLayout->addWidget(pushButton_E, 1, 0, 1, 1);

        pushButton_minus = new QPushButton(frame_keypad);
        pushButton_minus->setObjectName(QString::fromUtf8("pushButton_minus"));

        gridLayout->addWidget(pushButton_minus, 1, 1, 1, 1);

        pushButton_del = new QPushButton(frame_keypad);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        sizePolicy.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_del, 1, 2, 1, 1);

        pushButton_clear = new QPushButton(frame_keypad);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        gridLayout->addWidget(pushButton_clear, 5, 2, 1, 1);


        gridLayout_2->addWidget(frame_keypad, 5, 0, 1, 3);

        tableWidget_units_results = new QTableWidget(centralWidget);
        tableWidget_units_results->setObjectName(QString::fromUtf8("tableWidget_units_results"));
        tableWidget_units_results->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_units_results->setSortingEnabled(true);

        gridLayout_2->addWidget(tableWidget_units_results, 3, 0, 1, 3);

        pushButton_categories = new QPushButton(centralWidget);
        pushButton_categories->setObjectName(QString::fromUtf8("pushButton_categories"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_categories->sizePolicy().hasHeightForWidth());
        pushButton_categories->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(pushButton_categories, 0, 0, 1, 1);

        pushButton_plus_minus = new QPushButton(centralWidget);
        pushButton_plus_minus->setObjectName(QString::fromUtf8("pushButton_plus_minus"));

        gridLayout_2->addWidget(pushButton_plus_minus, 4, 1, 1, 1);

        pushButton_update = new QPushButton(centralWidget);
        pushButton_update->setObjectName(QString::fromUtf8("pushButton_update"));

        gridLayout_2->addWidget(pushButton_update, 4, 2, 1, 1);

        pushButton_show_hide = new QPushButton(centralWidget);
        pushButton_show_hide->setObjectName(QString::fromUtf8("pushButton_show_hide"));

        gridLayout_2->addWidget(pushButton_show_hide, 4, 0, 1, 1);

        pushButton_settings = new QPushButton(centralWidget);
        pushButton_settings->setObjectName(QString::fromUtf8("pushButton_settings"));

        gridLayout_2->addWidget(pushButton_settings, 0, 1, 1, 1);

        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        gridLayout_2->addWidget(pushButton_exit, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 275, 21));
        menuSettings_2 = new QMenu(menuBar);
        menuSettings_2->setObjectName(QString::fromUtf8("menuSettings_2"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(pushButton_clear, pushButton_dot);
        QWidget::setTabOrder(pushButton_dot, pushButton_0);
        QWidget::setTabOrder(pushButton_0, pushButton_1);
        QWidget::setTabOrder(pushButton_1, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_E);
        QWidget::setTabOrder(pushButton_E, pushButton_minus);
        QWidget::setTabOrder(pushButton_minus, pushButton_del);
        QWidget::setTabOrder(pushButton_del, pushButton_show_hide);
        QWidget::setTabOrder(pushButton_show_hide, pushButton_plus_minus);
        QWidget::setTabOrder(pushButton_plus_minus, pushButton_update);
        QWidget::setTabOrder(pushButton_update, pushButton_categories);
        QWidget::setTabOrder(pushButton_categories, tableWidget_units_results);

        menuBar->addAction(menuSettings_2->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuSettings_2->addAction(actionSettings);
        menuSettings_2->addAction(actionReset);
        menuAbout->addAction(actionHelp);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Converter", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionFormat->setText(QApplication::translate("MainWindow", "Format", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        pushButton_0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton_0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton_5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton_dot->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        pushButton_dot->setShortcut(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton_6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton_8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton_3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton_7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton_9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton_4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton_1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton_2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton_E->setText(QApplication::translate("MainWindow", "E", 0, QApplication::UnicodeUTF8));
        pushButton_E->setShortcut(QApplication::translate("MainWindow", "E", 0, QApplication::UnicodeUTF8));
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        pushButton_minus->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        pushButton_del->setText(QApplication::translate("MainWindow", "<<", 0, QApplication::UnicodeUTF8));
        pushButton_del->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        pushButton_clear->setShortcut(QApplication::translate("MainWindow", "C", 0, QApplication::UnicodeUTF8));
        pushButton_categories->setText(QApplication::translate("MainWindow", "Units", 0, QApplication::UnicodeUTF8));
        pushButton_categories->setShortcut(QApplication::translate("MainWindow", "U", 0, QApplication::UnicodeUTF8));
        pushButton_plus_minus->setText(QApplication::translate("MainWindow", "+/-", 0, QApplication::UnicodeUTF8));
        pushButton_plus_minus->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        pushButton_update->setText(QApplication::translate("MainWindow", "Update", 0, QApplication::UnicodeUTF8));
        pushButton_update->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        pushButton_show_hide->setText(QApplication::translate("MainWindow", "Hide", 0, QApplication::UnicodeUTF8));
        pushButton_show_hide->setShortcut(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
        pushButton_settings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        pushButton_settings->setShortcut(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        menuSettings_2->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

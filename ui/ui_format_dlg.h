/********************************************************************************
** Form generated from reading UI file 'format_dlg.ui'
**
** Created: Sat 31. Mar 16:38:57 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMAT_DLG_H
#define UI_FORMAT_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Format_Dlg
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_general;
    QRadioButton *radioButton_scientific;
    QRadioButton *radioButton_fixedDecimal;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox_automatic;
    QSpinBox *spinBox_decimalDigits;
    QLabel *label;
    QCheckBox *checkBox_groupDigits;

    void setupUi(QDialog *Format_Dlg)
    {
        if (Format_Dlg->objectName().isEmpty())
            Format_Dlg->setObjectName(QString::fromUtf8("Format_Dlg"));
        Format_Dlg->resize(211, 258);
        gridLayout_3 = new QGridLayout(Format_Dlg);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(Format_Dlg);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        radioButton_general = new QRadioButton(groupBox);
        radioButton_general->setObjectName(QString::fromUtf8("radioButton_general"));

        gridLayout->addWidget(radioButton_general, 0, 0, 1, 1);

        radioButton_scientific = new QRadioButton(groupBox);
        radioButton_scientific->setObjectName(QString::fromUtf8("radioButton_scientific"));

        gridLayout->addWidget(radioButton_scientific, 1, 0, 1, 1);

        radioButton_fixedDecimal = new QRadioButton(groupBox);
        radioButton_fixedDecimal->setObjectName(QString::fromUtf8("radioButton_fixedDecimal"));

        gridLayout->addWidget(radioButton_fixedDecimal, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

        buttonBox = new QDialogButtonBox(Format_Dlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(Format_Dlg);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox_automatic = new QCheckBox(groupBox_2);
        checkBox_automatic->setObjectName(QString::fromUtf8("checkBox_automatic"));

        gridLayout_2->addWidget(checkBox_automatic, 0, 0, 1, 2);

        spinBox_decimalDigits = new QSpinBox(groupBox_2);
        spinBox_decimalDigits->setObjectName(QString::fromUtf8("spinBox_decimalDigits"));
        spinBox_decimalDigits->setMinimum(1);
        spinBox_decimalDigits->setMaximum(50);
        spinBox_decimalDigits->setSingleStep(1);
        spinBox_decimalDigits->setValue(10);

        gridLayout_2->addWidget(spinBox_decimalDigits, 1, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        checkBox_groupDigits = new QCheckBox(groupBox_2);
        checkBox_groupDigits->setObjectName(QString::fromUtf8("checkBox_groupDigits"));

        gridLayout_2->addWidget(checkBox_groupDigits, 2, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 2);


        retranslateUi(Format_Dlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), Format_Dlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Format_Dlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(Format_Dlg);
    } // setupUi

    void retranslateUi(QDialog *Format_Dlg)
    {
        Format_Dlg->setWindowTitle(QApplication::translate("Format_Dlg", "Format", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Format_Dlg", "Format", 0, QApplication::UnicodeUTF8));
        radioButton_general->setText(QApplication::translate("Format_Dlg", "automatic", 0, QApplication::UnicodeUTF8));
        radioButton_scientific->setText(QApplication::translate("Format_Dlg", "scientific", 0, QApplication::UnicodeUTF8));
        radioButton_fixedDecimal->setText(QApplication::translate("Format_Dlg", "fixed decimal", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Format_Dlg", "Precision", 0, QApplication::UnicodeUTF8));
        checkBox_automatic->setText(QApplication::translate("Format_Dlg", "automatic precision", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Format_Dlg", "decimal digits", 0, QApplication::UnicodeUTF8));
        checkBox_groupDigits->setText(QApplication::translate("Format_Dlg", "group digits", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Format_Dlg: public Ui_Format_Dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMAT_DLG_H

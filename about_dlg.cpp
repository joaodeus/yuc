#include "about_dlg.h"
#include "ui_about_dlg.h"

About_Dlg::About_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_Dlg)
{
    ui->setupUi(this);
}

About_Dlg::~About_Dlg()
{
    delete ui;
}

void About_Dlg::on_pushButton_ok_clicked()
{
    close();
}

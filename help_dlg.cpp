#include "help_dlg.h"
#include "ui_help_dlg.h"

help_dlg::help_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_dlg)
{
    ui->setupUi(this);
}

help_dlg::~help_dlg()
{
    delete ui;
}

void help_dlg::on_pushButton_ok_clicked()
{
    close();
}

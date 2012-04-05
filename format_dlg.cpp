#include "format_dlg.h"
#include "ui_format_dlg.h"

Format_Dlg::Format_Dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Format_Dlg)
{
    ui->setupUi(this);
}

Format_Dlg::~Format_Dlg()
{
    delete ui;
}

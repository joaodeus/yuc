#include "categories_dlg.h"
#include "ui_categories_dlg.h"

categories_dlg::categories_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categories_dlg)
{
    ui->setupUi(this);
}

categories_dlg::~categories_dlg()
{
    delete ui;
}

#include "settings_dlg.h"
#include "ui_settings_dlg.h"

settings_dlg::settings_dlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings_dlg)
{
    ui->setupUi(this);
}

settings_dlg::~settings_dlg()
{
    delete ui;
}

void settings_dlg::on_listWidget_clicked(const QModelIndex &index)
{
    index_selected = index.row();
    close();
}

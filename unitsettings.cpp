#include "unitsettings.h"
#include "ui_unitsettings.h"

UnitSettings::UnitSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnitSettings)
{
    ui->setupUi(this);
}

UnitSettings::~UnitSettings()
{
    delete ui;
}

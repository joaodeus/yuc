#ifndef UNITSETTINGS_H
#define UNITSETTINGS_H

#include <QDialog>

namespace Ui {
class UnitSettings;
}

class UnitSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit UnitSettings(QWidget *parent = 0);
    ~UnitSettings();
    
private:
    Ui::UnitSettings *ui;
};

#endif // UNITSETTINGS_H

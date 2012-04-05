#ifndef ABOUT_DLG_H
#define ABOUT_DLG_H

#include <QDialog>

namespace Ui {
class About_Dlg;
}

class About_Dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit About_Dlg(QWidget *parent = 0);
    ~About_Dlg();
    
private slots:
    void on_pushButton_ok_clicked();

private:
    Ui::About_Dlg *ui;
};

#endif // ABOUT_DLG_H

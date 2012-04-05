#ifndef FORMAT_DLG_H
#define FORMAT_DLG_H

#include <QDialog>

namespace Ui {
class Format_Dlg;
}

class Format_Dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit Format_Dlg(QWidget *parent = 0);
    ~Format_Dlg();
    
private:
    Ui::Format_Dlg *ui;
};

#endif // FORMAT_DLG_H

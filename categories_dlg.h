#ifndef CATEGORIES_DLG_H
#define CATEGORIES_DLG_H

#include <QDialog>

namespace Ui {
class categories_dlg;
}

class categories_dlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit categories_dlg(QWidget *parent = 0);
    ~categories_dlg();
    
private:
    Ui::categories_dlg *ui;
};

#endif // CATEGORIES_DLG_H

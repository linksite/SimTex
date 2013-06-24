#ifndef DIALOGCONFIG_H
#define DIALOGCONFIG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class DialogConfig;
}

class DialogConfig : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogConfig(QWidget *parent = 0);
    ~DialogConfig();
public slots:
    void save(void);
    void saveAndClose(void);
    
private:
    Ui::DialogConfig *ui;
    QSettings settings;
};

#endif // DIALOGCONFIG_H

#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();
    void closeEvent(QCloseEvent* event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H

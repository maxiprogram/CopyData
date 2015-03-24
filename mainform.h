#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include "threadcopy.h"

namespace Ui {
class MainForm;
}

class MainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainForm(QWidget *parent = 0);
    ~MainForm();
    void ReadIni(int& time_update, QString& path_src, QString& path_dest);
    void WriteIni(int time_update, QString path_src, QString path_dest);

private slots:
    void onTimerCopy();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_action_3_triggered();

    void on_pushButton_4_clicked();

private:
    Ui::MainForm *ui;
    int time_update;
    QString path_src;
    QString path_dest;
    bool flag_copy;
    QTimer* timer;
    ThreadCopy* thread_copy;
};

#endif // MAINFORM_H

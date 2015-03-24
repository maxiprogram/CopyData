#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>
#include <QSystemTrayIcon>
#include <QCloseEvent>

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
    void closeEvent(QCloseEvent* event);

private slots:
    void onTimerCopy();

    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);

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
    QSystemTrayIcon* tray;
};

#endif // MAINFORM_H

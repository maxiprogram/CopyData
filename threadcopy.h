#ifndef THREADCOPY_H
#define THREADCOPY_H

#include <QThread>
#include <QMessageBox>
#include <QDate>
#include <QSystemTrayIcon>
#include <QDebug>

#include "copy.h"
#include "logfile.h"

class ThreadCopy:public QThread
{
public:
    ThreadCopy();
    void SetTray(QSystemTrayIcon* tray);
    void run();
private:
    QSystemTrayIcon* tray;
};

#endif // THREADCOPY_H

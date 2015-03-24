#ifndef THREADCOPY_H
#define THREADCOPY_H

#include <QThread>
#include <QMessageBox>
#include <QDate>
#include <QDebug>

#include "copy.h"
#include "logfile.h"

class ThreadCopy:public QThread
{
public:
    ThreadCopy();
    void run();
};

#endif // THREADCOPY_H

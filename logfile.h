#ifndef LOGFILE_H
#define LOGFILE_H

#include <QDate>
#include <QFile>
#include <QDebug>

class LogFile
{
public:
    LogFile();
    static QDate GetLastDate();
    static void SaveDate();
};

#endif // LOGFILE_H

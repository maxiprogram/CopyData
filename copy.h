#ifndef COPY_H
#define COPY_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QDebug>

class Copy
{
public:
    Copy();
    static bool CopyData(QString path_src, QString path_dest);
};

#endif // COPY_H

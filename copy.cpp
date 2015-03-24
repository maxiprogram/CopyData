#include "copy.h"

Copy::Copy()
{
}

bool Copy::CopyData(QString path_src, QString path_dest)
{
    QDir dir(path_dest);
    if (!dir.mkdir(path_dest))
        return false;
    QProcess proc;
    proc.setProgram("xcopy");
    QStringList arg;
    arg.append(path_src);
    arg.append(path_dest);
    arg.append("/E");
    proc.setArguments(arg);
    proc.open();
    qDebug()<<proc.program();
    if (!proc.waitForFinished())
    {
        qDebug()<<proc.errorString();
        return false;
    }
    qDebug()<<proc.readAll();
    proc.close();
    qDebug()<<"End copy";
    return true;
}

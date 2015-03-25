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
    //qDebug()<<proc.program();
    QFile f("info.log");
    f.open(QIODevice::Append);
    QByteArray buf;
    buf.append(proc.program()+"\r\n");
    for (int i=0; i<proc.arguments().size(); i++)
    {
        buf.append(proc.arguments().at(i));
        buf.append("\r\n");
    }
    f.write(buf);
    if (!proc.waitForFinished())
    {
        QByteArray buf;
        buf.insert(0, proc.errorString());
        buf.append("\r\n");
        f.write(buf);
        //qDebug()<<proc.errorString();
        return false;
    }
    f.write(proc.readAll());
    f.write("\r\n");
    //qDebug()<<proc.readAll();
    f.close();
    proc.close();
    qDebug()<<"End copy";
    return true;
}

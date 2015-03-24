#include "logfile.h"

LogFile::LogFile()
{
}

QDate LogFile::GetLastDate()
{
    QFile f("date_copy.log");
    if (f.open(QIODevice::ReadOnly))
    {
        f.seek(f.size()-10);
        QByteArray buf = f.read(10);
        //qDebug()<<"buf="<<buf;
        QDate date;
        date = QDate::fromString(buf, "dd.MM.yyyy");
        //qDebug()<<"date="<<date;
        f.close();
        return date;
    }else
    {
        qDebug()<<"Not read log";
        f.close();
        return QDate::currentDate();
    }
}

void LogFile::SaveDate()
{
    QFile f("date_copy.log");
    f.open(QIODevice::Append);
    QString result = QDate::currentDate().toString("dd.MM.yyyy");
    QByteArray buf;
    buf.insert(0, result);
    f.write(buf);
    f.close();
}

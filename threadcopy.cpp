#include "threadcopy.h"

ThreadCopy::ThreadCopy()
{

}

void ThreadCopy::run()
{
    QString path_src = this->property("path_src").toString();
    QString path_dest = this->property("path_dest").toString();
    if (Copy::CopyData(path_src, path_dest))
    {
        LogFile::SaveDate();
    }else
    {
        //QMessageBox::about(0, QDate::currentDate().toString("dd.MM.yyyy"), "Не удалось скопировать данные!");
        qDebug()<<"Error thread_copy";
    }
}

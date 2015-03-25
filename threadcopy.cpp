#include "threadcopy.h"

ThreadCopy::ThreadCopy()
{

}

void ThreadCopy::SetTray(QSystemTrayIcon* tray)
{
    this->tray = tray;
}

void ThreadCopy::run()
{
    QString path_src = this->property("path_src").toString();
    QString path_dest = this->property("path_dest").toString();
    if (Copy::CopyData(path_src, path_dest))
    {
        LogFile::SaveDate();
        tray->showMessage("Сообщение "+QDate::currentDate().toString("dd.MM.yyyy"), "Данные успешно скопировались");
    }else
    {
        //QMessageBox::about(0, QDate::currentDate().toString("dd.MM.yyyy"), "Не удалось скопировать данные!");
        qDebug()<<"Error thread_copy";
        tray->showMessage("Сообщение "+QDate::currentDate().toString("dd.MM.yyyy"), "Не удалось скопировать данные!\nПапка с текущей датой существует, либо не удалось её создать.", QSystemTrayIcon::Critical);
    }
}

#include "mainform.h"
#include "ui_mainform.h"

MainForm::MainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    thread_copy = new ThreadCopy();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimerCopy()));

    flag_copy = false;
    time_update = 0;
    path_src = path_dest = "";

    ReadIni(time_update, path_src, path_dest);

    if (time_update<0 || time_update>1 || path_src=="" || path_dest=="")
    {
        QMessageBox::about(0, "Не верные настройки", "Не верные настройки программы!");
    }else
    {
        ui->comboBox->setCurrentIndex(time_update);
        ui->lineEdit->setText(path_src);
        ui->lineEdit_2->setText(path_dest);
        timer->start();
    }

    tray = new QSystemTrayIcon(this);
    tray->setContextMenu(ui->menu);
    tray->setIcon(QIcon("://icon.png"));
    connect(tray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));
    tray->show();
}

MainForm::~MainForm()
{
    delete thread_copy;
    delete ui;
}

void MainForm::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::Trigger:
        case QSystemTrayIcon::DoubleClick:
            this->show();
            break;
        default:
            break;
    }
}

void MainForm::closeEvent(QCloseEvent* event)
{
    this->hide();
    event->ignore();
}

void MainForm::onTimerCopy()
{
    QDate last_date = LogFile::GetLastDate();
    qDebug()<<last_date.toString("dd.MM.yyyy");

    if (time_update==0)
    {
        if (last_date<QDate::currentDate())
            flag_copy = true;
    }
    if (time_update==1)
    {
        last_date = last_date.addMonths(1);
        if (last_date<QDate::currentDate())
            flag_copy = true;
    }
    qDebug()<<"Flag="<<flag_copy;
    if (flag_copy)
    {
        QString new_path_src = path_src;
        QString new_path_dest = path_dest
                +"/"+QString::number(QDate::currentDate().day())
                +"_"+QString::number(QDate::currentDate().month())
                +"_"+QString::number(QDate::currentDate().year());
        //qDebug()<<new_path_dest;
        new_path_src.replace("/", "\\");
        new_path_dest.replace("/", "\\");
        if (!thread_copy->isRunning())
        {
            thread_copy->setProperty("path_src", new_path_src);
            thread_copy->setProperty("path_dest", new_path_dest);
            thread_copy->start();
            flag_copy = false;
        }
    }
}

void MainForm::ReadIni(int& time_update, QString& path_src, QString& path_dest)
{
    QSettings setting("setting.ini", QSettings::IniFormat);
    time_update = setting.value("time_update").toInt();
    path_src = setting.value("path_src").toString();
    path_dest = setting.value("path_dest").toString();
}

void MainForm::WriteIni(int time_update, QString path_src, QString path_dest)
{
    QSettings setting("setting.ini", QSettings::IniFormat);
    setting.setValue("time_update", time_update);
    setting.setValue("path_src", path_src);
    setting.setValue("path_dest", path_dest);
}

void MainForm::on_pushButton_clicked()
{
    time_update = ui->comboBox->currentIndex();
    path_src = ui->lineEdit->text();
    path_dest = ui->lineEdit_2->text();
    WriteIni(time_update, path_src, path_dest);
}

void MainForm::on_pushButton_2_clicked()
{
    QString new_path_src = QFileDialog::getExistingDirectory(this, "Выбор директории", "", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    if (new_path_src!="" && new_path_src!=path_src)
    {
        path_src = new_path_src;
        ui->lineEdit->setText(path_src);
    }
}


void MainForm::on_pushButton_3_clicked()
{
    QString new_path_dest = QFileDialog::getExistingDirectory(this, "Выбор директории", "", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    if (new_path_dest!="" && new_path_dest!=path_dest)
    {
        path_dest = new_path_dest;
        ui->lineEdit_2->setText(path_dest);
    }
}

void MainForm::on_action_3_triggered()
{
     QApplication::exit();
}

void MainForm::on_pushButton_4_clicked()
{
    if (!thread_copy->isRunning())
    {
        QString new_path_src = path_src;
        QString new_path_dest = path_dest
                +"/"+QString::number(QDate::currentDate().day())
                +"_"+QString::number(QDate::currentDate().month())
                +"_"+QString::number(QDate::currentDate().year());
        new_path_src.replace("/", "\\");
        new_path_dest.replace("/", "\\");
        thread_copy->setProperty("path_src", new_path_src);
        thread_copy->setProperty("path_dest", new_path_dest);
        thread_copy->start();
    }
}

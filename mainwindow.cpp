#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <QMessageBox>
#include <QComboBox>
#include <QProcess>
#include <QFileDialog>
#include <QDesktopServices>
#include <iostream>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QUrl ava_url("http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/weight/list/");
    QNetworkRequest ava_request(ava_url);


    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QEventLoop loop;

    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     &loop,
                     SLOT(quit()));

    QNetworkReply *reply = manager->get(ava_request);
    loop.exec();

    QString response = (QString)reply->readAll();

 //   qDebug() << response;
    QJsonDocument temp = QJsonDocument::fromJson(response.toUtf8());

    QJsonObject jsonObj = temp.object();

    QJsonArray project_list = jsonObj["Weight Files"].toArray();


    for(int i=0; i < project_list.count(); i++){
        QJsonObject value = project_list[i].toObject();
        qDebug() << value["title"].toString();
        qDebug() << value["id"].toInt();


        ui->comboBox->addItem(value["title"].toString());

    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
}


void MainWindow::on_comboBox_activated(int index)
{

}

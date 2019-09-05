#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QMessageBox>
#include <QProcess>
#include <iostream>
#include <Windows.h>
#include <WinUser.h>
#include <conio.h>

#include <QFileDialog>
#include <QDesktopServices>
#include <iostream>
#include <QComboBox>


static int arr[30];
static QString str[30];


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   QUrl ava_url("http://ec2-13-209-5-1.ap-northeast-2.compute.amazonaws.com/file/image/list/");
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

          QJsonArray project_list = jsonObj["Image Files"].toArray();


          for(int i=0; i < project_list.count(); i++){
              QJsonObject value = project_list[i].toObject();
             // qDebug() << value["title"].toString();
            //  qDebug() << value["id"].toInt();
              arr[i] = value["id"].toInt();
              str[i] = value["title"].toString();

              ui->comboBox->addItem(value["title"].toString());
       }



}

MainWindow::~MainWindow()
{
    delete ui;
}









int MainWindow::on_comboBox_activated(int index)
{
    return index;
}

void MainWindow::on_pushButton_label_clicked()
{


//    QProcess process;
//    process.setWorkingDirectory("C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release");
//    process.start("yolo_mark.cmd");


   // process.waitForFinished(-1);

    int labelcmd;

    labelcmd = system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd" );
    system("yolo_mark.cmd");


  //  QMessageBox::information(this,"labeling", "labeling complete.");
}
void MainWindow::on_pushButton_learn_clicked()
{

    //파일1번
   // system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & copy /y yolo-obj.cfg C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64");
    //파일2번
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & move /y img C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\img");
    //파일3번
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & copy /y obj.data C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");
    //파일4번
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & copy /y obj.names C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");
    //파일5번
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & copy /y train.txt C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");
    //파일6번
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\cfg & move /y yolov3-tiny_obj.cfg C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64");





    int learncmd;
    learncmd = system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64 & darknet.exe detector train data/obj.data yolov3-tiny_obj.cfg yolov3-tiny.conv.15");


    if (learncmd > 0){
        QMessageBox::information(this,"error", "confirm file.");
      }
    else{
        QMessageBox::information(this,"learning", "learning complete.");
    }

}


void MainWindow::on_pushButton_transmit_clicked()
{
    //파일1번
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup & copy /y yolov3-tiny_obj_last.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");

    //파일2번
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64 & copy /y yolov3-tiny_obj.cfg C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");
    //파일3번
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\cfg & copy yolov3-tiny_obj.cfg C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");

    //tar zip                                                                                              파일이름여기
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\data & tar -cf test.tar train.txt yolov3-tiny_obj_last.weights obj.names obj.data yolov3-tiny_obj.cfg");

    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\data & copy /y test.tar C:\\Users\\ipslGoodPc\\Desktop\\source\\transmit "); //압축돼서 copy 된 tar파일을 transmit폴더에 넣어줌
/*
    int id = ui->comboBox->currentIndex(); //콤보박스 선택값
    QString arrtitle = str[id];

    */


  //  QString transmit =  "cd C:/Users/chaeyoungg/Desktop/untitled1/graduation_QT_project & uploadWeightFile.sh " + arrtitle; // QString으로 경로저장 경로바꿔줘야함 sh파일이 있어야함

    QString n = ui->lineEdit->text(); //Line edit의 테스트값 저장

    QString transmit =  "cd C:/Users/ipslGoodPc/Desktop/source & uploadWeightFile.sh " + n; //입력된 텍스트값 붙여서 저장
//    qDebug() << transmit;

    system(transmit.toUtf8()); //전송요청


    QMessageBox::information(this,"transmitting", "transmitting complete.");
}





void MainWindow::on_pushButton_download_clicked()
{
    int id = ui->comboBox->currentIndex(); //콤보박스 선택값
    int arrindex = arr[id];
    QString n = QString::number(arrindex);//QString 변환

                                                              //경로바뀌면 이 앞부터 변경
//    QProcess *Prozess = new QProcess();
//    QProcess::startDetached("cmd.exe", QStringList() << "downloadFile.sh" + n, "C:/Users/ipslGoodPc/Desktop/source/downloaded/");
//    Prozess->setWorkingDirectory(QDir::homePath()+ "/downloaded/");
//    Prozess->start("C:/Users/ipslGoodPc/Desktop/source/downloaded/downloadFile.sh");


    QString download =  "cd C:/Users/ipslGoodPc/Desktop/source/downloaded & downloadFile.sh " + n; // QString으로 경로저장 경로바꿔줘야함 sh파일이 있어야함
    system(download.toUtf8());

    //cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd
    system("cd C:/Users/ipslGoodPc/Desktop/source/downloaded & tar -xf test.tar"); //tar 파일 압축 풀기
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data\\img & del /s /q ."); //전에 있던 이미지 데이터 삭제
    system("cd C:/Users/ipslGoodPc/Desktop/source/downloaded & copy /y img C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data\\img "); //이미지 폴더에 복사
    system("cd C:/Users/ipslGoodPc/Desktop/source/downloaded & rd /s /q img"); //다운받아 남아있는 이미지 폴더 삭제
//rd /s /q img 빼고


    QMessageBox::information(this,"download", "downloading complete.");
}

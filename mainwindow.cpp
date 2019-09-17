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

//ShellExecute(NULL, "open", "cmd.exe", "ipconfig->test.txt",NULL, SW_HIDE);

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


   // QProcess *process = new QProcess(this);
//    process->setWorkingDirectory("C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release");
//   QString arguments = "cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd";

//    QString program = "ipconfig";
//    QString program = "cd";
//    QStringList arguments;
//    arguments << "C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd";
//    process->start(program, arguments);


   // process->waitForFinished(3000);

//    QProcess *m_process = new QProcess(this);

//    m_process->setWorkingDirectory("C:/Team_VeryVery/Yolo_mark-master/x64/Release");
//    QString arguments;

//    arguments = "cd C:/Team_VeryVery/Yolo_mark-master/x64/Release & yolo_mark.cmd";

//    m_process->start(arguments);
//    m_process->waitForFinished(3000);

//    QByteArray result = m_process->readAll();
//    qDebug() << result;


     QProcess *m_process = new QProcess(this);

//     m_process->startDetached("cd C:/Team_VeryVery/Yolo_mark-master/x64/Release & yolo_mark.cmd");

//     QStringList arguments;
//     arguments << "cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd";

//     qDebug() << arguments;
//     m_process->setWorkingDirectory("C:/Team_VeryVery/Yolo_mark-master/x64/Release");
//     m_process->startDetached("cmd");
//     m_process->startDetached("cd");

//     m_process->startDetached("call", QStringList() << "yolo_mark.cmd", "C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release");












//     QDir::setCurrent("C:/Team_VeryVery/Yolo_mark-master/x64/Release");
//     system("yolo_mark.cmd");


    int labelcmd;

    labelcmd = system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd" );

}

void MainWindow::on_pushButton_learn_clicked()
{

    //파일2번
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & copy /y img C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\img");
    //파일4번
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & copy /y obj.names C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");
    //파일 train.txt
    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data & copy /y train.txt C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data");
    //파일6번
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\cfg & copy /y yolov3-tiny_obj.cfg C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64");



    int learncmd;
 //   learncmd = system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64 & darknet.exe detector train data/obj.data yolov3-tiny_obj.cfg yolov3-tiny.conv.15");

      QDir::setCurrent("C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64");
      system("darknet.exe detector train data/obj.data yolov3-tiny_obj.cfg yolov3-tiny.conv.15");







    if (learncmd > 0){
        QMessageBox::information(this,"error", "confirm file.");
      }
    else{
        QMessageBox::information(this,"learning", "learning complete.");
    }

}


void MainWindow::on_pushButton_transmit_clicked()
{
    //1000 weight

//    QDir::setCurrent("C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup");
//    system("copy /y yolov3-tiny_obj_1000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup copy /y yolov3-tiny_obj_1000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");


    //3000 weight

//    QDir::setCurrent("C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup");
//    system("copy /y yolov3-tiny_obj_3000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");

    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup & copy /y yolov3-tiny_obj_3000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");

    //5000 weight

//    QDir::setCurrent("C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup");
//    system("copy /y yolov3-tiny_obj_5000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");

    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup & copy /y yolov3-tiny_obj_5000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");


    //파일3번

    QDir::setCurrent("C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup");
    system("copy /y yolov3-tiny_obj_5000.weights C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");

    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\cfg & copy /y yolov3-tiny_obj.cfg C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");

    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\data & copy /y obj.names C:\\Team_VeryVery\\\"darknet-master (1)\"\\darknet-master\\build\\darknet\\x64\\data\\test");





    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\backup & del /s /q ."); //전에 있던 weight 데이터 삭제
     system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\data\\img & del /s /q .");



    //tar zip                                                                                              파일이름여기
    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\data & tar -cf test.tar test");

    system("cd C:\\Team_VeryVery\\darknet-master (1)\\darknet-master\\build\\darknet\\x64\\data & copy /y test.tar C:\\Users\\ipslGoodPc\\Desktop\\source\\transmit "); //압축돼서 copy 된 tar파일을 transmit폴더에 넣어줌




    QString n = ui->lineEdit->text(); //Line edit의 테스트값 저장



    QString transmit =  "cd C:/Users/ipslGoodPc/Desktop/source/transmit & runUpload.vbs " + n; //입력된 텍스트값 붙여서 저장
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


//    QString download =  "cd C:/Users/ipslGoodPc/Desktop/source/downloaded & downloadFile.sh " + n; // QString으로 경로저장 경로바꿔줘야함 sh파일이 있어야함
//    system(download.toUtf8());



    QString download = "runDownload.vbs " + n;
    QDir::setCurrent("C:/Users/ipslGoodPc/Desktop/source/downloaded");
    system(download.toUtf8());



    //cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release & yolo_mark.cmd




 //   system("cd C:/Users/ipslGoodPc/Desktop/source/downloaded & tar -zxvf test.tar"); //tar 파일 압축 풀기

//    QDir::setCurrent("C:/Users/ipslGoodPc/Desktop/source/downloaded");
//    system("tar -xf test.tar");


    QProcess prcs;
    prcs.setWorkingDirectory("C:/Users/ipslGoodPc/Desktop/source/downloaded");
    prcs.start(QString("tar -xf test.tar"));


  //  QFile::copy("/path/file", "/path/copy-of-file");




    system("cd C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data\\img & del /s /q ."); //전에 있던 이미지 데이터 삭제
//    QDir::setCurrent("C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data\\img");
//    system("del /s /q .");




    system("cd C:/Users/ipslGoodPc/Desktop/source/downloaded & copy /y img C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data\\img "); //이미지 폴더에 복사
//    QDir::setCurrent("C:/Users/ipslGoodPc/Desktop/source/downloaded");
//    system("copy /y img C:\\Team_VeryVery\\Yolo_mark-master\\x64\\Release\\data\\img");




    system("cd C:/Users/ipslGoodPc/Desktop/source/downloaded & rd /s /q img"); //다운받아 남아있는 이미지 폴더 삭제
  //  QDir::setCurrent("C:/Users/ipslGoodPc/Desktop/source/downloaded");
   // system("rd /s /q img");





    QMessageBox::information(this,"download", "downloading complete.");
}

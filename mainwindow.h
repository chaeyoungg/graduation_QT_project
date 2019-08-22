#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include <QDebug>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    int on_comboBox_activated(int index);

    void on_pushButton_label_clicked();

    void on_pushButton_learn_clicked();

    void on_pushButton_transmit_clicked();

    void on_pushButton_download_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

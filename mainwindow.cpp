#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("object1");
    ui->comboBox->addItem("object2");
    ui->comboBox->addItem("object3");

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
    QMessageBox::information(this,"labeling", "labeling complete.");
}

void MainWindow::on_pushButton_learn_clicked()
{
    QMessageBox::information(this,"learning", "learning complete.");
}

void MainWindow::on_pushButton_transmit_clicked()
{
    QMessageBox::information(this,"transmitting", "transmitting complete.");
}

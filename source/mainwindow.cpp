#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->EditAccount->setStyleSheet("QLineEdit { font-size: 16px; } QLineEdit::placeholder { color: gray; font-size: 8px; }");
    ui->EditPassword->setStyleSheet("QLineEdit { font-size: 16px; } QLineEdit::placeholder { color: gray; font-size: 8px; }");
    ui->EditAccount->setPlaceholderText("学号/工号");

    ui->EditPassword->setEchoMode(QLineEdit::Password);
    //ui->EditPassword->setEchoChar('*'); // 设置掩码字符为 *



    ui->EditPassword->setPlaceholderText("密码");

    ui->loginButton->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"  // 设置圆角半径
        "    border: 2px solid #8f8f91;"  // 设置边框
        "    background-color: #2a82da;"  // 设置背景颜色
        "    color: white;"  // 设置文字颜色

        "}"
        "QPushButton:hover {"
        "    background-color: #1e6bb8;"  // 悬停时的背景颜色
        "}"
        "QPushButton:pressed {"
        "    background-color: #144a82;"  // 按下时的背景颜色
        "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    this->hide();
    if(openteacher)emit showteacher();
    else if(openadminister)emit showadminister();
    else emit showstu();

}

void MainWindow::receiveloginagain(){
    this->show();
}

void MainWindow::on_student_clicked()
{
    openstudent=1;
    openteacher=0;
    openadminister=0;
}


void MainWindow::on_teacher_clicked()
{
    openteacher=1;
    openstudent=0;
    openadminister=0;
}


void MainWindow::on_Administrators_clicked()
{
    openadminister=1;
    openstudent=0;
    openteacher=0;
}

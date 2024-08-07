#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QMovie>



//
void storeUserInfo(const QString &account) {
    QFile file("user_data.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening file for writing";
        return;
    }

    QTextStream out(&file);
    out << account << "\n";
    file.close();

    qDebug() << "User account stored successfully!";
}







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //背景动画
    QMovie * movie = new QMovie(this);
    movie->setFileName(":/image/background.gif");
    movie->start();
    ui->top->setMovie(movie);

    //去掉边框
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
    //背景透明
    setAttribute(Qt::WA_TranslucentBackground);


    //ui界面的各种调整
    ui->EditAccount->setStyleSheet("QLineEdit { font-size: 16px; } QLineEdit::placeholder { color: gray; font-size: 8px; }");
    ui->EditPassword->setStyleSheet("QLineEdit { font-size: 16px; } QLineEdit::placeholder { color: gray; font-size: 8px; }");

    ui->EditAccount->setPlaceholderText("学号/工号");
    ui->EditPassword->setPlaceholderText("密码");

    QRegularExpression regExp("[^\\s]*");  // 允许除空格外的所有字符

    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, ui->EditAccount);
    ui->EditAccount->setValidator(validator);
    QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(regExp, ui->EditPassword);
    ui->EditPassword->setValidator(validator);

    //默认为"*"
    ui->EditPassword->setEchoMode(QLineEdit::Password);
    ui->eye->setIcon(QIcon(":/image/closeeye.png"));

    connect(this, &MainWindow::showeye, this, &MainWindow::changeeye);
    connect(ui->eye, &QPushButton::clicked, this, &MainWindow::on_eye_clicked);//两个connect实现小眼睛的点击信号和改变功能的

    //connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);//登录按钮，放到了main函数





    ui->eye->setStyleSheet(
        "QPushButton {"
        "    border-radius: 15px;"  // 设置圆角半径
        //"    background-color: white;"  // 设置背景颜色
        "    color: white;"  // 设置文字颜色
        "}"
        "QPushButton:hover {"
        "    background-color: #bbffee;"  // 悬停时的背景颜色
        "}"
        "QPushButton:pressed {"
        "    background-color: #00dddd;"  // 按下时的背景颜色
        "    border: 2px solid #8f8f91;"  // 设置边框
        "}"
        );



}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_loginButton_clicked()
{

    QString s1=ui->EditAccount->text(),s2=ui->EditPassword->text();

    if(s1==nullptr || s2==nullptr){
        QMessageBox::warning(this, "Input Error", "The input field cannot be empty.");
        return;
    }

    QSqlQuery query(user_db);
    qDebug()<<"登录账号 = "<<s1<<"  登录密码 = "<<s2;

    storeUserInfo(s1);


    if(openstudent==true){

        s1="S"+s1;
    }
    else if(openteacher==true){
        s1="T"+s1;
    }
    else if(openadminister==true){

        s1="A"+s1;
    }



    query.exec(QString("select* from user where zhanghao = '%1' and mima = '%2'").arg(s1).arg(s2));
    if(query.next() == false){
        QMessageBox::warning(this, "ERROR", "The account or password is error.");//输入错误提示弹窗
        ui->EditAccount->clear();
        ui->EditPassword->clear();
        return;
    }

    query.finish();

    if(openteacher&&is_pass(2,s1))emit showteacher();
    else if(openadminister&&is_pass(3,s1))emit showadminister();
    else if(openstudent&&is_pass(1,s1))emit showstu();
    else{
        QMessageBox::warning(this, "nonono", "Please choose a identity.");//选角色
        return;
    }
    this->hide();

}//实现登录的页面跳转，释放下一个页面展示的信号


bool MainWindow::is_pass(int type,QString account){
    if(type==1){

        if(account[0]=='S'){
            return 1;
        }

    }
    else if(type==2){
        if(account[0]=='T'){
            return 1;
        }
    }
    else if(type==3){
        if(account[0]=='A'){
            return 1;
        }

    }
    return 0;
}






void MainWindow::receiveloginagain(){
    this->show();
}

void MainWindow::on_student_clicked()
{
    openstudent=1;
    openteacher=0;
    openadminister=0;
    ui->student->setChecked(true);
}//选择登录学生


void MainWindow::on_teacher_clicked()
{
    openteacher=1;
    openstudent=0;
    openadminister=0;
}//选择登录老师


void MainWindow::on_Administrators_clicked()
{
    openadminister=1;
    openstudent=0;
    openteacher=0;
}//选择登录管理员


void MainWindow::on_eye_clicked()
{
    emit showeye(ui->eye->isChecked());
}//槽函数，释放信号


//eye的check，实现改变小眼睛状态
void MainWindow::changeeye(bool checked){
    if(checked){
        ui->EditPassword->setEchoMode(QLineEdit::Normal);
        ui->eye->setIcon(QIcon(":/image/openeye.png"));
    }
    else if(!checked){
        ui->EditPassword->setEchoMode(QLineEdit::Password);
        ui->eye->setIcon(QIcon(":/image/closeeye.png"));
    }
}


//实现点enter触发loginButton
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        on_loginButton_clicked();
    }
    else {
        QMainWindow::keyPressEvent(event);
    }
}



void MainWindow::on_commandLinkButton_clicked()
{
    QMessageBox::information(this, "忘记密码", "请联系管理员重置密码.");
}


void MainWindow::on_zuixiaohua_clicked()
{
    this->showMinimized();//最小化
}

void MainWindow::on_tuichu_clicked()
{
    this->close();//退出
}



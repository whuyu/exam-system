#include "changepassword.h"
#include "ui_changepassword.h"

changePassword::changePassword(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::changePassword)
{
    ui->setupUi(this);

    //给每个输入框标注内容

    ui->account->setPlaceholderText("账号");
    ui->oldPasserword->setPlaceholderText("旧密码");
    ui->newPassword->setPlaceholderText("新密码");
    ui->newPassword2->setPlaceholderText("再次确认");

}

changePassword::~changePassword()
{
    delete ui;
}

void changePassword::receivelogin(){
    this->show();
}


void changePassword::on_Return_clicked()
{

    this->hide();
    emit showstu();
}


void changePassword::on_finish_clicked()
{
    QString s1=ui->account->text();
    QString s2=ui->oldPasserword->text();
    QString s3=ui->newPassword->text();
    QString s4=ui->newPassword2->text();
    if(s3!=s4){
        QMessageBox::warning(this, "no！", "Please keep the old and new passwords consistent.");
        return;
    }
    //接下来弄数据库啥啥的
    if(1){//数据库的判断巴拉巴拉)
        this->hide();
        emit showstu();

    }



}


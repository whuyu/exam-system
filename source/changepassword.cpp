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

<<<<<<< Updated upstream

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



=======
bool changePassword::ispass(const QString &username, const QString &Password,QSqlDatabase &db){
    QString s1=username;
    QString s2=Password;
    if(s1==nullptr || s2==nullptr){
        QMessageBox::warning(this, "Input Error", "The input field cannot be empty.");
        return false;
    }

    QSqlQuery query(db);
    qDebug()<<"登录账号 = "<<s1<<"  登录密码 = "<<s2;
    query.exec(QString("select* from user where zhanghao = '%1' and mima = '%2'").arg(s1).arg(s2));
    if(query.next() == false){
        QMessageBox::warning(this, "ERROR", "The account or password is error.");//输入错误提示弹窗
        return false;
    }

    query.finish();

    return true;
}





bool changePassword::changePw(const QString &username, const QString &newPassword,QSqlDatabase &db) {

    // 创建SQL查询对象
    QSqlQuery query(db);

    query.exec(QString("update user set mima = '%1' where zhanghao = '%2'").arg(newPassword).arg(username));

    query.finish();
    qDebug() << "update password:";
    return true;
>>>>>>> Stashed changes
}


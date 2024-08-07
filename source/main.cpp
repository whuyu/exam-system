#include "mainwindow.h"
#include"studentwindow.h"
#include"user.h"
#include"studentchafen.h"
#include"studentchafen.h"
#include"changepassword.h"
#include"studentpreexam.h"
#include"studentexam.h"
#include"teacherquestion.h"
#include"combinepaper.h"
#include"teachermanage.h"
#include"teacherscore.h"


#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    MainWindow w;
    studentwindow sw1;
    teacherwindow tea1;
    Administer ad1;
    studentchafen cha1;
    changePassword cP1;

    studentpreexam spe1;
    studentexam se1;
    teacherquestion tq;

    teacherscore ts1;
    combinePaper cbp;
    teachermanage tm;
    users u1;

    qDebug()<<account<<"1145";
    //w.setFixedSize(560,300);
    w.show();
    //tea1.show();

    w.setWindowTitle("登录");
    w.setWindowIcon(QIcon(":/image/pencil"));

    sw1.setWindowTitle("爱做题");
    sw1.setWindowIcon(QIcon(":/image/pencil"));

    tea1.setWindowTitle("爱考试");
    tea1.setWindowIcon(QIcon(":/image/pencil"));

    ad1.setWindowTitle("爱管理");
    ad1.setWindowIcon(QIcon(":/image/pencil"));

    cP1.setWindowTitle("修改密码");

    ad1.setFixedSize(900,450);

    //connect，实现槽机制的关键
    QObject::connect(&w,SIGNAL(showadminister()),&ad1,SLOT(receivelogin()));
    QObject::connect(&w,SIGNAL(showteacher()),&tea1,SLOT(receivelogin()));
    QObject::connect(&w,SIGNAL(showstu()),&sw1,SLOT(receivelogin()));
    QObject::connect(&sw1,SIGNAL(showscore()),&cha1,SLOT(receivelogin()));
    QObject::connect(&sw1,SIGNAL(showchangePassword()),&cP1,SLOT(receivelogin()));
    QObject::connect(&sw1,SIGNAL(showeaxm()),&spe1,SLOT(receivelogin()));
    QObject::connect(&spe1,SIGNAL(showexam()),&se1,SLOT(receivelogin()));
    QObject::connect(&tea1,SIGNAL(showcreatequestion()),&tq,SLOT(receivelogin()));
    QObject::connect(&tea1,SIGNAL(showpaper()),&cbp,SLOT(receivelogin()));
    QObject::connect(&tea1,SIGNAL(showmanage()),&tm,SLOT(receivelogin()));
    QObject::connect(&tea1,SIGNAL(showjudge()),&ts1,SLOT(receivelogin()));


    QObject::connect(&ts1,SIGNAL(showteacher()),&tea1,SLOT(receivelogin()));
    QObject::connect(&cbp,SIGNAL(showteacher()),&tea1,SLOT(receivelogin()));
    QObject::connect(&cbp,SIGNAL(showteacher()),&tea1,SLOT(receivelogin()));
    QObject::connect(&tm,SIGNAL(showteacher()),&tea1,SLOT(receivelogin()));
    QObject::connect(&cha1,SIGNAL(showstudent()),&sw1,SLOT(receiveReturn()));
    QObject::connect(&spe1,SIGNAL(showstu()),&sw1,SLOT(receiveReturn()));
    QObject::connect(&cP1,SIGNAL(showstu()),&sw1,SLOT(receiveReturn()));
    QObject::connect(&se1,SIGNAL(showpreexam()),&spe1,SLOT(receiveReturn()));
    QObject::connect(&ad1,SIGNAL(showmain()),&w,SLOT(receiveloginagain()));
    QObject::connect(&sw1,SIGNAL(showmain()),&w,SLOT(receiveloginagain()));
    QObject::connect(&tq,SIGNAL(showteacher()),&tea1,SLOT(receivelogin()));
    QObject::connect(&tea1,SIGNAL(showmain()),&w,SLOT(receiveloginagain()));

    qDebug()<<account<<"11452";

    ad1.derive_data_to_sql(user_db);//测试函数

    cP1.changePw("111","11",user_db);//测试函数

    qDebug()<<account<<"11451";

    tea1.derive_data_to_sql(user_db);
    //QString s=tea1.getPaperName(1,user_db);
    //qDebug()<<s;
    //qDebug()<<user_name;



    return a.exec();
}

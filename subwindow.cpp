#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(set<QString> set, People* p, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
    this->m_People_p = new People(p);
    this->m_People_p->printPeople();
    this->setFixedSize(1280, 720);
    this->initPeopleInfo();
    ui->widget_sub_userinfo->hide();
    this->m_set_hash_name = set;
    this->m_timer_t1 = new QTimer;

    this->allConnects();
    ui->lineEdit_sub_userid->setEnabled(false);

}



SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::initPeopleInfo()
{
    this->updatePeopleInfo();
}

bool SubWindow::savePeopleInfo()
{
    QString username = ui->lineEdit_sub_username->text();
    QString name = ui->lineEdit_sub_name->text();
    int age = ui->lineEdit_sub_age->text().toInt();
    QString sex_qstring = ui->lineEdit_sub_sex->text();
    double h = ui->lineEdit_sub_h->text().toDouble();
    double w = ui->lineEdit_sub_w->text().toDouble();
    int id = ui->lineEdit_sub_userid->text().toInt();
    bool sex = sex_qstring == "男" ? 1 : 0;
    if(username != this->m_People_p->getUsername() && this->m_set_hash_name.count(username))
        return false;
    QSettings* config = new QSettings(this->m_s_path, QSettings::IniFormat);
    this->m_People_p->updatePeople(age, h, w, sex, name, username, id);
    config->beginGroup(QString::number(this->m_People_p->getUserId()));
//    config->setValue("userid", QString::number(this->m_People_p->getUserId()));
    config->setValue("age", QString::number(this->m_People_p->getAge()));
//    QString pwdsec = p->getPassword();
//    QByteArray pwd64 = pwdsec.toLocal8Bit().toBase64();
//    QString pwd = QString::fromLocal8Bit(pwd64);
//    config->setValue("password", pwd);
    config->setValue("name", this->m_People_p->getName());
    config->setValue("username", this->m_People_p->getUsername());
    config->setValue("h", QString::number(this->m_People_p->getHeight(), 'f', 2));
    config->setValue("w", QString::number(this->m_People_p->getWeight(), 'f', 2));
    config->setValue("sex", this->m_People_p->getSexEn());
    config->endGroup();
    emit this->sendUpdateUserInfo();
    return true;
//    this->m_People_p->printPeople();

}

void SubWindow::updatePeopleInfo()
{
    ui->lineEdit_sub_age->setText(QString::number(this->m_People_p->getAge()));
    ui->lineEdit_sub_name->setText(this->m_People_p->getName());
    ui->lineEdit_sub_username->setText(this->m_People_p->getUsername());
    ui->lineEdit_sub_userid->setText(QString::number(this->m_People_p->getUserId()));
    ui->lineEdit_sub_h->setText(QString::number(this->m_People_p->getHeight(), 'f', 2));
    ui->lineEdit_sub_w->setText(QString::number(this->m_People_p->getWeight(), 'f', 2));
    ui->lineEdit_sub_sex->setText(this->m_People_p->getSex());
}

void SubWindow::allConnects()
{
    this->allTimerConnects();
    this->allButtonConnects();

}

void SubWindow::allButtonConnects()
{
    connect(this->m_timer_t1, &QTimer::timeout, [=](){
        ui->label_sub_userinfo_message->setText("");
        this->m_timer_t1->stop();
    });
}

void SubWindow::allTimerConnects()
{
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        qDebug() << "click backButton";
        emit this->sendClickBackButton();
    });
}

void SubWindow::on_pushButton_sub_userinfo_clicked()
{
//    this->hide();
    ui->widget_initiative->hide();
    ui->widget_initiative_2->hide();
    ui->widget_sub_userinfo->show();
    ui->widget_sub_userinfo->move(400, 100);
}

void SubWindow::on_pushButton_4_clicked()
{
    ui->widget_initiative->show();
    ui->widget_initiative_2->show();
    ui->widget_sub_userinfo->hide();
}

void SubWindow::on_pushButton_sub_saveinfo_clicked()
{
    if(this->savePeopleInfo())
    {
        this->updatePeopleInfo();
        ui->label_sub_userinfo_message->setText("保存成功 ! ! !");
        ui->label_sub_userinfo_message->setStyleSheet("color:green;");
        this->m_timer_t1->start(1000);
    }
    else
    {
        ui->label_sub_userinfo_message->setText("用户名存在 ! ! !");
        ui->label_sub_userinfo_message->setStyleSheet("color:red;");
        this->m_timer_t1->start(1000);
    }
}

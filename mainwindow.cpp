#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->statusBar()->setSizeGripEnabled(false);//隐藏状态栏上的拖动图标
    this->setWindowTitle("手部康复辅助系统");
    this->setFixedSize(1280, 720);
    this->setTransparent();
    this->readUserInfo();
    this->m_timer_t1 = new QTimer;
    this->m_timer_t2 = new QTimer;
//    this->m_sub_window = new SubWindow();
    this->setEffect();
    ui->widget_register->hide();
    ui->lineEdit_register_password->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->lineEdit_login_password->setEchoMode(QLineEdit::Password);
    ui->checkBox->setChecked(1);
    this->allConnects();
    ui->widget_login->move(400, 100);
    ui->widget_register->move(400, 100);
    ui->lineEdit_login_username->setPlaceholderText("用户名/手机/邮箱");
    ui->lineEdit_login_password->setPlaceholderText("密码");
    ui->lineEdit_register_name->setPlaceholderText("真实姓名");
    ui->lineEdit_register_username->setPlaceholderText("用户名");
    ui->lineEdit_register_password->setPlaceholderText("密码");
//    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
//    QGraphicsDropShadowEffect* effect1 = new QGraphicsDropShadowEffect;

//    effect->setOffset(0, 0);
//    effect->setColor(QColor(68, 68, 68));
//    effect->setBlurRadius(10);
    DataProcess* t = new DataProcess();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
//     this->m_p_position = event->globalPos() - (this->frameGeometry().topLeft());

    this->m_p_position = event->globalPos() - this->pos();

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{


    move(event->globalPos() - this->m_p_position);
    setCursor(Qt::ClosedHandCursor);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}

bool MainWindow::checkPassword(QString pd)
{
    if(!pd.size())
    {
        qDebug() << "密码不能为空";
        this->m_s_errorMessage_register = "密码不能为空 ! !" ;
        return false;
    }

    return true;
}

bool MainWindow::checkCorrect(QString username, QString password)
{
    if(!this->m_set_hashmap_for_username.count(username))
    {
        this->m_s_errorMessage_login = "用户名不存在";
        return false;
    }
    if(this->m_v_p[this->m_map_hashmap_username_to_id[username]]->getPassword() != password)
    {
        this->m_s_errorMessage_login = "密码错误";
        return false;
    }
    return true;
}

void MainWindow::allConnects()
{
    this->allButtonConnects();
    this->allTimerConnects();
    this->allLabelConnects();
    this->allRenderConnects();

}

void MainWindow::allLabelConnects()
{
    ui->label_login_register->installEventFilter(this);
    ui->label_register_login->installEventFilter(this);
}

void MainWindow::allButtonConnects()
{
//    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
//        this->hide();
//        this->m_sub_window->show();
//    });
    ui->pushButton_2->hide();
    connect(ui->pushButton_register, &QPushButton::clicked, [=](){
        int age = ui->spinBox->value();
        double w = ui->doubleSpinBox->value(); // 体重
        double h = ui->doubleSpinBox_2->value(); // 身高
        bool sex = ui->checkBox->isChecked(); // 选中 ? 男 : 女
        QString name = ui->lineEdit_register_name->text(); // 真实姓名
        QString username = ui->lineEdit_register_username->text(); // 用户名
        QString password = ui->lineEdit_register_password->text(); // 密码
        this->savePeople(age, h, w, sex, name, username, this->m_i_cnt, password);
        this->m_timer_t1->start(2000);
    });

    connect(ui->pushButton_login, &QPushButton::clicked, [=](){
        QString username = ui->lineEdit_login_username->text();
        QString password = ui->lineEdit_login_password->text();
        if(checkCorrect(username, password))
        {
            this->hide();
            this->m_sub_window = new SubWindow(this->m_set_hashmap_for_username, this->m_v_p[this->m_map_hashmap_username_to_id[username]]);

            this->subRenderConnects();
            this->m_sub_window->show();
            return;
        }
        else
        {
            this->setLoginMessage(this->m_s_errorMessage_login, 0);
            this->m_timer_t2->start(2000);
        }
    });
    connect(ui->lineEdit_login_password, SIGNAL(returnPressed()), ui->pushButton_login, SLOT(click()), Qt::UniqueConnection); // 绑定回车对应按钮按下
    connect(ui->lineEdit_register_password, SIGNAL(returnPressed()), ui->pushButton_register, SLOT(click()), Qt::UniqueConnection);
}

void MainWindow::allTimerConnects()
{
    connect(this->m_timer_t1, &QTimer::timeout, [=](){
        ui->label_register_message->setText("");
        this->m_timer_t1->stop();
    });
    connect(this->m_timer_t2, &QTimer::timeout, [=](){
        ui->label_login_message->setText("");
        this->m_timer_t2->stop();
    });
}

void MainWindow::allRenderConnects()
{

}

void MainWindow::subRenderConnects()
{
    connect(this->m_sub_window, &SubWindow::sendClickBackButton, [=](){
        qDebug() << "back";
        this->m_sub_window->hide();
        this->show();
    });

    connect(this->m_sub_window, &SubWindow::sendUpdateUserInfo, [=](){
        this->updateUserInfo(this->m_sub_window->m_People_p->getUserId());
        qDebug() << "kizk back up";
        qDebug() << this->m_v_p[this->m_sub_window->m_People_p->getUserId()]->getUsername();

    });
}

void MainWindow::setRegisterMessage(QString message, bool flg)
{
    ui->label_register_message->setText(message + "! !");
    if(flg)
        ui->label_register_message->setStyleSheet("color:green;");
    else
        ui->label_register_message->setStyleSheet("color:red;");
}

void MainWindow::setLoginMessage(QString message, bool flg)
{
    ui->label_login_message->setText(message + "! !");
    if(!flg)
        ui->label_login_message->setStyleSheet("color:red;");

}

void MainWindow::setTransparent()
{
    this->setWindowFlags(Qt::FramelessWindowHint); // 去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground); // 设置透明窗体
}

void MainWindow::setEffect()
{
    for(int i = 0; i < 10; i ++)
    {
        QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
        effect->setOffset(0, 0);
        effect->setColor(QColor(68, 68, 68));
        effect->setBlurRadius(10);
        this->m_v_effect.push_back(effect);
    }
    int cnt = 0;
    ui->widget_login->setGraphicsEffect(this->m_v_effect[cnt ++]);
    ui->widget_register->setGraphicsEffect(this->m_v_effect[cnt ++]);
    ui->label_16->setGraphicsEffect(this->m_v_effect[cnt ++]);
    ui->label_headphoto->setGraphicsEffect(this->m_v_effect[cnt ++]);
    ui->widget_register_effect->setGraphicsEffect(this->m_v_effect[cnt ++]);
}

void MainWindow::saveUserInfo(People *p)
{
    QSettings* config = new QSettings(this->m_s_path, QSettings::IniFormat);
    config->beginGroup(QString::number(p->getUserId()));
    config->setValue("userid", QString::number(p->getUserId()));
    config->setValue("age", QString::number(p->getAge()));
    QString pwdsec = p->getPassword();
    QByteArray pwd64 = pwdsec.toLocal8Bit().toBase64();
    QString pwd = QString::fromLocal8Bit(pwd64);
    config->setValue("password", pwd);
    config->setValue("name", p->getName());
    config->setValue("username", p->getUsername());
    config->setValue("h", QString::number(p->getHeight(), 'f', 2));
    config->setValue("w", QString::number(p->getWeight(), 'f', 2));
    config->setValue("sex", p->getSexEn());
    config->endGroup();
    qDebug() << "kizkkizkkizkkizkkizkkizk";
}

void MainWindow::updateUserInfo(int idx)
{
    QString oldusername = this->m_v_p[idx]->getUsername();
    qDebug() << "oldname :" << oldusername;
    QSettings* config = new QSettings(this->m_s_path, QSettings::IniFormat);
    int id = config->value(QString::number(idx) + "/userid", -this->m_i_Inf).toInt();
    QString name = config->value(QString::number(idx) + "/name").toString();
    QString username = config->value(QString::number(idx) + "/username").toString();
    bool sex = config->value(QString::number(idx) + "/sex").toString() == "m" ? 1 : 0;
    double h = config->value(QString::number(idx) + "/h").toDouble();
    double w = config->value(QString::number(idx) + "/w").toDouble();
    int age = config->value(QString::number(idx) + "/age").toInt();
    QString pwdsec = config->value(QString::number(idx) + "/password").toString();
    QByteArray pwdb64 = QByteArray::fromBase64(pwdsec.toLocal8Bit());
    QString pd = QString::fromLocal8Bit(pwdb64);
    People* p = new People(age, h, w, sex, name, username, id, pd);
    this->m_v_p[idx] = p;
    qDebug() << "newname :" << username;
    this->m_set_hashmap_for_username.erase(oldusername);
    this->m_map_hashmap_username_to_id.erase(oldusername);
    this->m_map_hashmap_username_to_id[username] = idx;
    this->m_set_hashmap_for_username.insert(username);
    qDebug() << "check is: " << (this->m_set_hashmap_for_username.count(oldusername) ? "yes" : "no");
}

void MainWindow::readUserInfo()
{
    this->m_i_cnt = 0;
    while(1)
    {
        QSettings* config = new QSettings(this->m_s_path, QSettings::IniFormat);
        int id = config->value(QString::number(this->m_i_cnt) + "/userid", -this->m_i_Inf).toInt();
        if(id == -this->m_i_Inf)
        {
            qDebug() << "kizk" <<  this->m_i_cnt;
            qDebug() << "已经初始化完毕";
            break;
        }
        QString name = config->value(QString::number(this->m_i_cnt) + "/name").toString();
        QString username = config->value(QString::number(this->m_i_cnt) + "/username").toString();
        bool sex = config->value(QString::number(this->m_i_cnt) + "/sex").toString() == "m" ? 1 : 0;
        double h = config->value(QString::number(this->m_i_cnt) + "/h").toDouble();
        double w = config->value(QString::number(this->m_i_cnt) + "/w").toDouble();
        int age = config->value(QString::number(this->m_i_cnt) + "/age").toInt();
        QString pwdsec = config->value(QString::number(this->m_i_cnt) + "/password").toString();
        QByteArray pwdb64 = QByteArray::fromBase64(pwdsec.toLocal8Bit());
        QString pd = QString::fromLocal8Bit(pwdb64);
        People* p = new People(age, h, w, sex, name, username, id, pd);
        this->m_v_p.push_back(p);
        this->m_map_hashmap_username_to_id[username] = this->m_i_cnt ++ ;
        this->m_set_hashmap_for_username.insert(username);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->label_login_register)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            if(e->button() == Qt::LeftButton || e->button() == Qt::RightButton)
            {
                // todo
                qDebug() << "click l";
                ui->widget_login->hide();
                ui->widget_register->show();
            }
            emit sendObject(ui->label_login_register);
        }
    }
    else if(watched == ui->label_register_login)
    {
        if(event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent *e = static_cast<QMouseEvent *>(event);
            if(e->button() == Qt::LeftButton || e->button() == Qt::RightButton)
            {
                // todo
                qDebug() << "clik r";
                ui->widget_register->hide();
                ui->widget_login->show();
            }
            emit sendObject(ui->label_register_login);
        }
    }
    return false;
}

void MainWindow::savePeople(int age, double h, double w, bool sex, QString name, QString username, int cnt, QString pd) // 保存人员信息
{
    ui->label_register_message->setStyleSheet("color:red;");
    if(this->m_set_hashmap_for_username.count(username))
    {
//        qDebug() << "用户名已经存在: ";
        this->m_s_errorMessage_register = "用户名已经存在";
        this->setRegisterMessage(this->m_s_errorMessage_register, 0);
        return;
    }
    if(username == "")
    {
//        qDebug() << "用户名不能为空";
        this->m_s_errorMessage_register ="用户名不能为空";
        this->setRegisterMessage(this->m_s_errorMessage_register, 0);
        return;
    }
    if(name == "")
    {
//        qDebug() << "真实姓名不能为空";

        this->m_s_errorMessage_register = "真实姓名不能为空";
        this->setRegisterMessage(this->m_s_errorMessage_register, 0);
        return;
    }
    if(!this->checkPassword(pd))
    {
        this->setRegisterMessage(this->m_s_errorMessage_register, 0);
        this->m_timer_t1->start(2000);
        return;
    }

    ui->label_register_message->setText(this->m_s_errorMessage_register);
    People* p = new People(age, h, w, sex, name, username, cnt, pd);
    this->m_map_hashmap_username_to_id[username] = this->m_i_cnt ++ ;
    this->m_set_hashmap_for_username.insert(username);
    this->m_v_p.push_back(p);
    this->setRegisterMessage("信息保存成功", 1);
    this->saveUserInfo(p);
    ui->widget_register->hide();
    ui->widget_login->show();
}




void MainWindow::on_pushButton_login_min_clicked()
{
    this->showMinimized();
}

void MainWindow::on_pushButton_login_quit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_login_min_2_clicked()
{
    this->showMinimized();
}

void MainWindow::on_pushButton_login_quit_2_clicked()
{
    this->close();
}

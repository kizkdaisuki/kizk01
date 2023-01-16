#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QDebug>
#include <QTimer>
#include <string>
#include "people.h"
#include <QString>
#include <set>
#include <QLineEdit>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <subwindow.h>
#include <QGraphicsDropShadowEffect>
#include <QCloseEvent>
#include <QPoint>
#include <QSettings>
#include <QByteArray>
#include "dataprocess.h"
#include "graphshow.h"
using std::vector;
using std::set;
using std::map;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer* m_timer_t1 = NULL;
    QTimer* m_timer_t2 = NULL;

    // 实现拖拽功能
    QPoint m_p_position;
    void mousePressEvent(QMouseEvent* event) ;
    void mouseMoveEvent(QMouseEvent* event) ;
    void mouseReleaseEvent(QMouseEvent* event) ;


    void savePeople();
    void savePeople(int age, double h, double w, bool sex, QString name, QString username, int cnt, QString password);
    bool checkPassword(QString pd);
    bool checkCorrect(QString username, QString password);
    void allConnects();
    void allLabelConnects();
    void allButtonConnects();
    void allTimerConnects();
    void allRenderConnects();
    void subRenderConnects();
    void setRegisterMessage(QString message, bool flg);
    void setLoginMessage(QString message, bool flg);
    void setTransparent();
    void setEffect();
    void saveUserInfo(People *p);
    void updateUserInfo(int idx);
    void readUserInfo();
signals:
    void sendObject(QObject *t);
private slots:
    bool eventFilter(QObject *watched, QEvent *event);
    // .ui中点击转到槽自动生成的函数(相当于手写connect)
    void on_pushButton_login_min_clicked();

    void on_pushButton_login_quit_clicked();

    void on_pushButton_login_min_2_clicked();

    void on_pushButton_login_quit_2_clicked();

private:
    Ui::MainWindow *ui;
    vector<People*> m_v_p;
    SubWindow* m_sub_window = NULL;

    map<QString, int> m_map_hashmap_username_to_id;
    QString m_s_errorMessage_login;
    QString m_s_errorMessage_register;
    vector<QGraphicsDropShadowEffect*> m_v_effect;
    set<QString> m_set_hashmap_for_username;
    QString m_s_path = "./user.ini";
    const int m_i_Inf = 0x3f3f3f3f;
    int m_i_cnt = 0;


};
#endif // MAINWINDOW_H

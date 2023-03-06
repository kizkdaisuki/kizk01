#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QByteArray>
#include <QSettings>
#include <iostream>
#include <set>
#include <QTimer>
#include "people.h"
using std::set;
namespace Ui {
class SubWindow;
}

class SubWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SubWindow(set<QString> set, People* p = nullptr, QWidget *parent = nullptr);
//    SubWindow(People* p);
    ~SubWindow();

    void initPeopleInfo();
    bool savePeopleInfo();
    void updatePeopleInfo();
    void allConnects();
    void allButtonConnects();
    void allTimerConnects();
    void initStyle();
signals:
    void sendClickBackButton();
    void sendUpdateUserInfo();

private slots:
    void on_pushButton_sub_userinfo_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_sub_saveinfo_clicked();
public:
    People* m_People_p = NULL;
private:
    Ui::SubWindow *ui;
    set<QString> m_set_hash_name;
    QString m_s_path = "./user.ini";
    const int m_i_Inf = 0x3f3f3f3f;
    QTimer* m_timer_t1 = NULL;

};

#endif // SUBWINDOW_H

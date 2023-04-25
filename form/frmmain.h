#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
#include "subwindow.h"
#include "data.h"
#include "graphshow.h"
#include "QLayout"
#include "QVBoxLayout"
class QAbstractButton;

namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(SubWindow* sub, QWidget *parent = 0);
    ~frmMain();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::frmMain *ui;

    QList<int> iconsMain;
    QList<QAbstractButton *> btnsMain;

    QList<int> iconsConfig;
    QList<QAbstractButton *> btnsConfig;
    QVBoxLayout* m_layout_main = NULL;

public:
    SubWindow* m_sub_window = NULL;
private:
    //根据QSS样式获取对应颜色值
    QString borderColor;
    QString normalBgColor;
    QString darkBgColor;
    QString normalTextColor;
    QString darkTextColor;
    void getQssColor(const QString &qss, const QString &flag, QString &color);
    void getQssColor(const QString &qss, QString &textColor,
                     QString &panelColor, QString &borderColor,
                     QString &normalColorStart, QString &normalColorEnd,
                     QString &darkColorStart, QString &darkColorEnd,
                     QString &highColor);


private slots:
    void initForm();
    void initStyle();
    void buttonClick();
    void initLeftMain();
    void initLeftConfig();
    void leftMainClick();
    void leftConfigClick();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
};

#endif // FRMMAIN_H

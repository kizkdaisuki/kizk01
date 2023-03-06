#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>

class AppInit : public QObject
{
    Q_OBJECT
public:
    static AppInit *Instance();
    explicit AppInit(QObject *parent = 0);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    static QScopedPointer<AppInit> self;

public slots:
    void start();
};

#endif // APPINIT_H

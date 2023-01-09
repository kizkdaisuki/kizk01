#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QString>
#include <QDebug>
#ifndef PEOPLE_H
#define PEOPLE_H


class People
{
public:
    People();
    People(int age, double h, double w, bool sex, QString name, QString username, int id, QString pd):m_i_age(age), m_d_height(h), m_d_weight(w), m_b_sex(sex), m_s_name(name)
    ,m_s_username(username), m_i_userid(id), m_s_password(pd){}
    People(const People* p);
    void printPeople();
    void updatePeople(int age, double h, double w, bool sex, QString name, QString username, int id);
    void test(){
        this->m_s_name = "dal";
    }
    QString getPassword();
    QString getSex();
    QString getName();
    QString getUsername();
    QString getSexEn();
    int getUserId();
    double getWeight();
    double getHeight();
    int getAge();

private:
    int m_i_age;
    double m_d_weight, m_d_height;
    QString m_s_name;
    bool m_b_sex;
    QString m_s_username;
    int m_i_userid;
    QString m_s_password;
};

#endif // PEOPLE_H

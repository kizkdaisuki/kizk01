#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "people.h"

People::People()
{

}

People::People(const People* p)
{
    this->m_d_height = p->m_d_height;
    this->m_d_weight =  p->m_d_weight;
    this->m_i_age =  p->m_i_age;
    this->m_b_sex = p->m_b_sex;
    this->m_s_name =  p->m_s_name;
    this->m_s_username =  p->m_s_username;
    this->m_s_password =  p->m_s_password;
    this->m_i_userid =  p->m_i_userid;
}

void People::printPeople()
{
    qDebug() << "姓名: " << this->m_s_name;
    qDebug() << "性别: " << (this->m_b_sex ? "男" : "女");
    qDebug() << "身高: " << this->m_d_height;
    qDebug() << "体重: " << this->m_d_weight;
    qDebug() << "年龄: " << this->m_i_age;
    qDebug() << "用户名: " << this->m_s_username;
    qDebug() << "密码: " << this->m_s_password;
}

void People::updatePeople(int age, double h, double w, bool sex, QString name, QString username, int id)
{
    this->m_i_age = age;
    this->m_d_height = h;
    this->m_d_weight = w;
    this->m_b_sex = sex;
    this->m_s_name = name;
    this->m_s_username = username;
    this->m_i_userid = id;
}

QString People::getPassword()
{
    return this->m_s_password;
}

QString People::getSex()
{
    return this->m_b_sex ? "男" : "女";
}


QString People::getName()
{
    return this->m_s_name;
}

QString People::getUsername()
{
    return this->m_s_username;
}

QString People::getSexEn() // m 男 w 女
{
    return this->m_b_sex ? "m" : "w";
}

int People::getAge()
{
    return this->m_i_age;
}

int People::getUserId()
{
    return this->m_i_userid;
}

double People::getWeight()
{
    return this->m_d_weight;
}

double People::getHeight()
{
    return this->m_d_height;
}

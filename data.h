#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DATA_H
#define DATA_H
#include <QString>
#include <vector>
#include <iostream>
using namespace std;

class Data
{
public:
    Data(vector<vector<double>> pos, vector<double> t);
    vector<vector<double>> getPosition(){return this->m_v_position;}
    vector<double> getTime(){return this->m_v_time;}
    void displayData();
private:
    QString m_s_dataName;
    vector<vector<double>> m_v_position;
    vector<double> m_v_time;
    vector<vector<double>> m_v_vel;
    vector<vector<double>> m_v_acc;
    double m_v_dt;

};

#endif // DATA_H

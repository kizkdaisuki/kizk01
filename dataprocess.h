#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef DATAPROCESS_H
#define DATAPROCESS_H
#include<stdio.h>
#include<stdlib.h>
#include "mat.h"
#include "matrix.h"
#include<QDebug>
#include<QFile>
#include <QMessageBox>
#include <iostream>
#include "data.h"
#include <vector>
using namespace std;


class DataProcess
{
public:
    DataProcess();

public:
    void test();
    void initFilePath(); // 初始化文件路径
    void saveData(QString filePath); // 保存数据
public:
    vector<Data*> m_v_data;
    vector<QString> m_v_filepath;
};

#endif // DATAPROCESS_H

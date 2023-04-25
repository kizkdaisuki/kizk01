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
#include "graphshow.h"
#include <time.h>
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
    GraphShow* m_graphshow_graph = NULL;
};

#endif // DATAPROCESS_H

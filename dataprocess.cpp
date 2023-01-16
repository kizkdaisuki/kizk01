#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "dataprocess.h"

DataProcess::DataProcess()
{
    this->test();
    this->initFilePath();
    for(auto& ite : this->m_v_filepath)
        this->saveData(ite);
    for(auto& ite : this->m_v_data)
        ite->displayData();

}

void DataProcess::test()
{

    // CShapr.mat/demos/pos/
    QString filePath = "G:/program_code/Qt/code/zust/kizk01/first/CShape.mat";
//    for(int i = 0; i < 2; i ++)
//        for(int j = 0; j < col; j ++)
//        {
//            std::cout << Data[i * j + j] << " \n"[j == col - 1];
//        }


}

void DataProcess::initFilePath()
{
    this->m_v_filepath.push_back("G:/program_code/Qt/code/zust/kizk01/first/CShape.mat");

}

void DataProcess::saveData(QString filePath)
{
    MATFile* pmatFile = matOpen(filePath.toUtf8().data(), "r");
    if(!pmatFile)
    {
        qDebug() << "get error";
        return;
    }
    mxArray *pMxArray = matGetVariable(pmatFile, "demos");
    if(!pMxArray)
    {
        qDebug() << "pm is error";
        return;
    }

    mxArray *PF = mxGetCell(pMxArray, 0);
    mxArray *pf_1 = mxGetField(PF, 0, "pos");
    // init pos
    if(!pf_1)
    {
        qDebug() << "pf is error";
        return;
    }
    double *data = (double*)mxGetData(pf_1);
    int n = mxGetM(pf_1);
    int m = mxGetN(pf_1);
    vector<vector<double>> pos;
    for(int i = 0; i < n; i ++)
    {
       vector<double> temp;
       for(int j = 0; j < m; j ++)
           temp.push_back(data[i * j + j]);
        pos.push_back(temp);
    }
//    std::cout << "pn: " << pos.size() << " pm: " << pos[0].size() << std::endl;
    // init t
    mxArray *pf_2 = mxGetField(PF, 0, "t");
    n = mxGetM(pf_2);
    m = mxGetN(pf_2);
    data = (double*)mxGetData(pf_2);
    vector<double> t;
    for(int i = 0; i < m; i ++)
        t.push_back(data[i]);
    matClose(pmatFile);
    Data* newData = new Data(pos, t);
    this->m_v_data.push_back(newData);
}




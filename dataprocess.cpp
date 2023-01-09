#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "dataprocess.h"

DataProcess::DataProcess()
{
    this->test();
}

void DataProcess::test()
{


    QString filePath = "G:/program_code/Qt/code/zust/kizk01/first/CShape.mat";
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
    int M = mxGetM(pMxArray);
    int N = mxGetN(pMxArray);
    qDebug() << M << " " << N;
    double *Data = (double*)mxGetData(pMxArray);
    mxArray *PF = mxGetCell(pMxArray, 0);
    mxArray *pf_1 = mxGetField(PF, 0, "pos");
    if(!pf_1)
    {
        qDebug() << "pf is error";
        return;
    }
    int row = mxGetM(pf_1);
    int col = mxGetN(pf_1);
    std::cout << row << " " << col << std::endl;

//    for(int i = 0; i < 2; i ++)
//        for(int j = 0; j < col; j ++)
//        {
//            std::cout << Data[i * j + j] << " \n"[j == col - 1];
//        }

    matClose(pmatFile);

}

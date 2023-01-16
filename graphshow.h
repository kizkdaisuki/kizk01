#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef GRAPHSHOW_H
#define GRAPHSHOW_H

#include <QWidget>
#include <QTimer>
#include <QChartView>
#include <QValueAxis>
#include <QLineSeries>
#include "data.h"
#include <vector>
QT_CHARTS_USE_NAMESPACE
using namespace std;
namespace Ui {
class GraphShow;
}

class GraphShow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphShow(vector<double> x , vector<double> y, vector<double> t, QWidget *parent = nullptr);
    ~GraphShow();
public:
    QTimer *m_timer_t1 = NULL;
    QChart *m_chart_chart = NULL;
    QValueAxis *m_axis_x = NULL; // 横坐标
    QValueAxis *m_axis_y = NULL; // 纵坐标
    QLineSeries *m_lineSeries_l= NULL;
    vector<double> m_d_x;
    vector<double> m_d_y;
    int m_AXIS_MAX_X, m_AXIS_MAX_Y; // 最大范围
    int m_i_pointCount = 0;
private:
    Ui::GraphShow *ui;
};

#endif // GRAPHSHOW_H

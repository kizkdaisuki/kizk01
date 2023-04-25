#include "graphshow.h"
#include "ui_graphshow.h"
#include <QChartView>
GraphShow::GraphShow(vector<double> x, vector<double> y, vector<double> t, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphShow)
{

    ui->setupUi(this);
    this->m_timer_t1 = new QTimer(this);
    this->m_axis_x = new QValueAxis();
    this->m_axis_y = new QValueAxis();
    this->m_axis_x->setMin(-100);
    this->m_axis_y->setMin(-100);
    this->m_axis_x->setMax(100);
    this->m_axis_y->setMax(100);

    this->m_lineSeries_l = new QLineSeries();                             // 创建曲线绘制对象
    this->m_lineSeries_l->setPointsVisible(true);                         // 设置数据点可见
    this->m_lineSeries_l->setName("数据曲线");                            // 图例名称

    this->m_chart_chart = new QChart();                                        // 创建图表对象
    this->m_chart_chart->addAxis(this->m_axis_y, Qt::AlignLeft);                      // 将X轴添加到图表上
    this->m_chart_chart->addAxis(this->m_axis_x, Qt::AlignBottom);                    // 将Y轴添加到图表上
    this->m_chart_chart->addSeries(this->m_lineSeries_l);                              // 将曲线对象添加到图表上
    this->m_chart_chart->setAnimationOptions(QChart::SeriesAnimations);        // 动画：能使曲线绘制显示的更平滑，过渡效果更好看

    this->m_lineSeries_l->attachAxis(this->m_axis_y);                             // 曲线对象关联上X轴，此步骤必须在this->m_chart_chart->addSeries之后
    this->m_lineSeries_l->attachAxis(this->m_axis_x);                             // 曲线对象关联上Y轴，此步骤必须在this->m_chart_chart->addSeries之
    ui->graphicsView->setChart(this->m_chart_chart);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);       // 设置渲染：抗锯齿，如果不设置那么曲线就显得不平滑
    this->m_timer_t1->start(20);
    this->m_d_x = x;
    this->m_d_y = y;

    for(auto& ite : this->m_d_y)
        cout << ite << " ";
    connect(this->m_timer_t1, &QTimer::timeout,[=](){
        cout << this->m_i_pointCount;
        this->m_lineSeries_l->append(QPointF(this->m_d_x[this->m_i_pointCount], this->m_d_y[this->m_i_pointCount ++]));
//        this->m_lineSeries_l->append(QPointF(this->m_i_pointCount, this->m_i_pointCount ++));
    });

}

GraphShow::~GraphShow()
{
    delete ui;
}

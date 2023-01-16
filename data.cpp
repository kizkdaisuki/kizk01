#include "data.h"

Data::Data(vector<vector<double>> pos, vector<double> t)
{
    this->m_v_position = pos;
    this->m_v_time = t;
    auto m_graphshow_graph = new GraphShow(this->m_v_position[0], this->m_v_position[1], this->m_v_time);
    m_graphshow_graph->show();
}

void Data::displayData()
{
   // show the pos
   for(auto& ite : this->m_v_position)
   {
       for(auto& val : ite)
           cout << val << " ";
       cout << endl;
   }
   cout << endl;
   // show the time
   for(auto& ite : this->m_v_time)
   {
       cout << ite << " ";
   }
   cout << endl;
}

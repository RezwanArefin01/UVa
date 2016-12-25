#include<iostream>
using namespace std;
int h,u,d,day;
double f,dis;
int main()
{
    while (cin>>h>>u>>d>>f && h>0)
    {
        f*=0.01;
        dis = 0.0;
        day = 0;
        while (true)
        {
            dis+=max(0.0,u*(1.0-day*f));
            day ++;
            if(dis>h)
            {
                cout<<"success on day "<<day<<endl;
                break;
            }
            dis-=d;
            if (dis<0)
            {
                 cout<<"failure on day "<<day<<endl;
                 break;
            }
        }
    }
    return 0;
}

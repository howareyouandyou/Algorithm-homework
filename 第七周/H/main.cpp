//H : 圆排列最小长度
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 11;
double r[maxn],x[maxn];//圆的半径，圆的横坐标
int n;
double min_len=0x3f3f3f3f;

double center(int t)//第t个圆圆心的横坐标
{
    double max_x=0;
    //逐一计算，因为圆t都有与之前任何一个圆相切的可能
    for(int i=1;i<=t-1;i++)
    {
        double s=x[i]+2*sqrt(r[i]*r[t]);//s=前一个圆的横坐标x[i]+两圆心的距离d
                                         //d=sqrt(pow(r[i]+r[t],2)-pow(r[i]-r[t],2))=2*sqrt(r[i]*r[t])
        if(s>max_x)
          max_x=s;
    }
    return max_x;
}

void compute()
{
    double low=0,high=0;
    for(int i=1;i<=n;i++)
    {
        if(x[i]-r[i]<low)
            low=x[i]-r[i];
        if(x[i]+r[i]>high)
            high=x[i]+r[i];
    }
    if(high-low<min_len)
    {
        min_len=high-low;
    }
}

void DFS(int cur)
{
    if(cur>n)//排列中的最后一个圆
    {
        compute();
    }
    else
    {
        for(int i=cur;i<=n;i++)
        {
            swap(r[cur],r[i]);//排列
            double max_x=center(cur);
            if(r[1]+max_x+r[cur]<min_len)
            {
                x[cur]=max_x;
                DFS(cur+1);
            }
            swap(r[cur],r[i]);
        }
    }
}


int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>r[i];
        }
        //sort(a,a+n);
        DFS(1);
        //cout<<min_len<<endl;
        printf("%.3f\n",min_len);

    }
    return 0;
}

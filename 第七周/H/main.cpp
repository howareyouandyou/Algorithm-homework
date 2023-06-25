//H : Բ������С����
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 11;
double r[maxn],x[maxn];//Բ�İ뾶��Բ�ĺ�����
int n;
double min_len=0x3f3f3f3f;

double center(int t)//��t��ԲԲ�ĵĺ�����
{
    double max_x=0;
    //��һ���㣬��ΪԲt������֮ǰ�κ�һ��Բ���еĿ���
    for(int i=1;i<=t-1;i++)
    {
        double s=x[i]+2*sqrt(r[i]*r[t]);//s=ǰһ��Բ�ĺ�����x[i]+��Բ�ĵľ���d
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
    if(cur>n)//�����е����һ��Բ
    {
        compute();
    }
    else
    {
        for(int i=cur;i<=n;i++)
        {
            swap(r[cur],r[i]);//����
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

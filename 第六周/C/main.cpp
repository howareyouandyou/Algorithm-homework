//C : 活动选择
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct act
{
    int s,t;//活动开始时间和结束时间
};

bool cmp(act p1,act p2)
{
    if(p1.t<p2.t)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    while(cin>>n)
    {
        act *p=new act[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].s>>p[i].t;
        }
        //结束早的优先
        sort(p,p+n,cmp);
        int lastT=-1;//目前活动结束的时间
        int sum=0;//活动的个数
        for(int i=0;i<n;i++)
        {
            if(p[i].s>=lastT)
            {
                lastT=p[i].t;
                sum++;
            }
        }
        cout<<sum<<endl;

    }

    return 0;
}

/**********************************************************************
	Problem: 1035
	User: 202100202053
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2184 kb
**********************************************************************/

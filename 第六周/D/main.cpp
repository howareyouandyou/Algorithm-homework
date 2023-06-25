//D : 最小延迟调度问题
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct task
{
    int t,d;//持续时间和截止时间
};

bool cmp(task p1,task p2)
{
    if(p1.d<p2.d)
    {
        return true;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        task* p=new task[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].t>>p[i].d;
        }
        sort(p,p+n,cmp);//将d从小到大排序
        int f=0;//延迟时间
        int fin=0;//当前任务完成的时间
        for(int i=0;i<n;i++)
        {
            fin+=p[i].t;
            f=max(f,fin-p[i].d);//找出最大的延迟时间

        }
        cout<<f<<endl;
    }

    return 0;
}

/**********************************************************************
	Problem: 1038
	User: 202100202053
	Language: C++
	Result: AC
	Time:2 ms
	Memory:2184 kb
**********************************************************************/

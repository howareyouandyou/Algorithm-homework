//D : ��С�ӳٵ�������
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct task
{
    int t,d;//����ʱ��ͽ�ֹʱ��
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
        sort(p,p+n,cmp);//��d��С��������
        int f=0;//�ӳ�ʱ��
        int fin=0;//��ǰ������ɵ�ʱ��
        for(int i=0;i<n;i++)
        {
            fin+=p[i].t;
            f=max(f,fin-p[i].d);//�ҳ������ӳ�ʱ��

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

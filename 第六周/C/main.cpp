//C : �ѡ��
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct act
{
    int s,t;//���ʼʱ��ͽ���ʱ��
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
        //�����������
        sort(p,p+n,cmp);
        int lastT=-1;//Ŀǰ�������ʱ��
        int sum=0;//��ĸ���
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

//H : ���豸�������
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct task
{
    long long l,r;//��ʼʱ��ͽ���ʱ��
};

struct robot
{
    long long l,r;
};

bool cmp1(task a,task b)
{
    return a.l<b.l;
}

bool cmp2(robot a,robot b)
{
    return a.r>b.r;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        task* p=new task [n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i].l>>p[i].r;
        }
        sort(p,p+n,cmp1);
        long long sum_time=0;
        int robot_cnt=1;
        robot r[101];
        r[0].l=p[0].l;
        r[0].r=p[0].r;
        for(int i=1;i<n;i++)
        {
            int flag=0;//�豸��û�н��̱����ȣ���������Ϊ1
            for(int j=0;j<robot_cnt;j++)
            {
                if(r[j].r<=p[i].l)//˵�����豸���Ե��ȸý���
                {
                    flag=1;
                    r[j].r=p[i].r;
                    break;
                }
            }

            //���������i�޷����κ�һ̨�豸��ǰ��������ƥ�䣨��ʱ�����г�ͻ����������һ̨�豸�����Ŵ�����
            if(!flag)
            {
                robot_cnt++;
                r[robot_cnt-1].l=p[i].l;
                r[robot_cnt-1].r=p[i].r;
            }

            sort(r,r+robot_cnt,cmp2);

        }

        for(int i=0;i<robot_cnt;i++)
        {
            sum_time+=r[i].r-r[i].l;
        }
        cout<<robot_cnt<<" "<<sum_time<<endl;
    }

    return 0;
}


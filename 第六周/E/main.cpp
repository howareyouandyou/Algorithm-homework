//E : ����I
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int*a=new int [n+1];
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];//�����豸�ȴ�ʱ��
        }
        sort(a,a+n+1);//���ȴ�ʱ���С��������
        int wa=0;//�ܵȴ�ʱ��
        int fin=0;//��ǰʱ��
        for(int i=1;i<=n;i++)
        {
            fin+=a[i-1]+a[i];//a[i-1]�Ǵ���һ���豸�߻ص��ݵ�ʱ��
            wa+=fin;
        }
        cout<<wa<<endl;
    }

    return 0;
}

/**********************************************************************
	Problem: 1121
	User: 202100202053
	Language: C++
	Result: AC
	Time:1 ms
	Memory:2184 kb
**********************************************************************/

//F : ����ʱ�����
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int*a=new int [n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];//����ÿ��������ʱ��
        }
        sort(a,a+n);//��ÿ��������ʱ����С��������
        int sum=0;//����ʱ��
        int fin=0;//���ʱ��
        for(int i=0;i<n;i++)
        {
            fin+=a[i];
            sum+=fin;
        }
        cout<<sum<<endl;
    }

    return 0;
}

/**********************************************************************
	Problem: 1148
	User: 202100202053
	Language: C++
	Result: AC
	Time:1 ms
	Memory:2184 kb
**********************************************************************/

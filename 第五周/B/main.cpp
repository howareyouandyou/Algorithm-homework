#include <iostream>
#include <algorithm>

using namespace std;

int maxnum;//����
int num;//����
int s[1300001]={0};
bool cmp(int x,int y)
{
    return x<y;
}
//void Sort(int s[],int)

void split(int s[],int low,int high)
{
    int mid=(low+high)/2;
    int ll=low;
    int hh=high;

    for(;low<mid&&s[low]!=s[mid];low++);//Ѱ������߿�ʼ���������±�
    for(;high>mid&&s[high]!=s[mid];high--);
    if(high-low+1>maxnum)//��ʱ��λ��Ϊ����
    {
        maxnum=high-low+1;
        num=s[mid];
    }
    if(low-ll>maxnum)//�����ߵ����ĸ�����Ȼ��������������ݹ�
    {
        split(s,ll,low-1);
    }
    if(hh-high>maxnum)
    {
        split(s,high+1,hh);
    }
}

int main()
{
    int n;
    cin>>n;
    //int*s=new int [n];
    maxnum=0;
    num=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];

    }

    sort(s,s+n,cmp);
    split(s,0,n-1);
    cout<<num<<"\n"<<maxnum<<endl;
    return 0;
}




/**********************************************************************
	Problem: 1109
	User: 202100202053
	Language: C++
	Result: AC
	Time:456 ms
	Memory:7264 kb
**********************************************************************/

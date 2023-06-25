//A : 最优装载
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        int*a=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[j];
        }
        sort(a,a+m);//将货物重量从小到大排序
        int sum=n;
        int cnt=0;//能装载的货物数量
        for(int j=0;j<m&&sum>=a[j];sum-=a[j++])
        {
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

/**********************************************************************
	Problem: 1039
	User: 202100202053
	Language: C++
	Result: AC
	Time:92 ms
	Memory:3720 kb
**********************************************************************/

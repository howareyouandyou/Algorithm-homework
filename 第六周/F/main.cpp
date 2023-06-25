//F : 过题时间计算
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
            cin>>a[i];//输入每道题解决的时长
        }
        sort(a,a+n);//将每道题解决的时长从小到大排序
        int sum=0;//过题时间
        int fin=0;//完成时刻
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

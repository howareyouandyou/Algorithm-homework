//E : 开机I
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
            cin>>a[i];//输入设备等待时间
        }
        sort(a,a+n+1);//将等待时间从小到大排序
        int wa=0;//总等待时间
        int fin=0;//当前时间
        for(int i=1;i<=n;i++)
        {
            fin+=a[i-1]+a[i];//a[i-1]是从上一个设备走回电梯的时间
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

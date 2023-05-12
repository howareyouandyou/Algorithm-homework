#include <iostream>

using namespace std;

int a[101][101];
int dp[101][101];

//int DPS(int i,int j)
//{
//    if(i>n)
//}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                cin>>a[j][k];
            }
        }

        for(int j=1;j<=n;j++)
        {
            dp[n][j]=a[n][j];//将最底层的值设定好
        }
        for(int i=n-1;i>=1;i--) //自顶向上递推
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];//两个子问题的最优解加上(i,j)的值
            }
        }
        cout<<dp[1][1]<<endl;//最后输出从(1,1)出发的最优解
    }
}

/**********************************************************************
	Problem: 1026
	User: 202100202053
	Language: C++
	Result: AC
	Time:21 ms
	Memory:2264 kb
**********************************************************************/

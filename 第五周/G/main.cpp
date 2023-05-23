#include <iostream>
#include <string.h>

using namespace std;

const int maxn=99;
long long dp[maxn][maxn]={0};//dp[i,j]到达坐标[i,j]的路径数

int main()
{
    int m,n;
    cin>>m>>n;
//    int**dp=new int*[m];
//    for(int i=0;i<m;i++)
//        dp[i]=new int[n];
    for(int i=0;i<m;i++)//到达第0列的网格路径数都为1
    {
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++)//到达第0行的网格路径数都为1
    {
        dp[0][i]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];//路径数为分别到达该格子左边和上面两个格子的路径数之和
        }
    }

//    for(int i=0;i<m;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            cout<<dp[i][j]<<"\t";
//        }
//        cout<<endl;
//    }
    cout<<dp[m-1][n-1]<<endl;
    return 0;
}

#include <iostream>
#include <string.h>

using namespace std;

const int maxn=99;
long long dp[maxn][maxn]={0};//dp[i,j]��������[i,j]��·����

int main()
{
    int m,n;
    cin>>m>>n;
//    int**dp=new int*[m];
//    for(int i=0;i<m;i++)
//        dp[i]=new int[n];
    for(int i=0;i<m;i++)//�����0�е�����·������Ϊ1
    {
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++)//�����0�е�����·������Ϊ1
    {
        dp[0][i]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];//·����Ϊ�ֱ𵽴�ø�����ߺ������������ӵ�·����֮��
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

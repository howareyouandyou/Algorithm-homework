#include <iostream>

using namespace std;


int dp[10001];



int main()
{
    int n;
    while(cin>>n)
    {
        int b;//背包容量
        cin>>b;
        int *w=new int[n+1];//重量
        int *v=new int[n+1];//价值
        for(int i=1;i<=n;i++)
        {
            cin>>w[i]>>v[i];
        }
//        //dp[k][y]:只考虑前k种物品装入容量y的背包的最优解
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=0;j<=b;j++)
//            {
//                dp[i][j]=dp[i-1][j];//前面的子问题初始化现问题的最优解
//                if(j>=w[i])
//                {
//                    dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);//子问题1：1~i，【一定！】没有i，故要加上v[i]；子问题2：1~i-1，一定没有i
//
//                }
//            }
//        }
//        cout<<dp[n][b]<<endl;
        //滚动数组优化
        for(int i=1;i<=n;i++)
        {
            for(int j=b;j>=w[i];j--)
            {
                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
            }
        }
        cout<<dp[b]<<endl;
    }
}

/**********************************************************************
	Problem: 1154
	User: 202100202053
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2224 kb
**********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn = 1e4 + 10;
int max(int x, int y){return x > y ? x : y;}
int n, a;
int dp[maxn][2];
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = dp[0][1] = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a);
            // TODO: 完成状态转移
            dp[i][0]=max(dp[i-2][0], dp[i-2][1])+a;//抢了第i个房间，则第i-1个房间不抢，抢第i-2个房间
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);//第i个房间不抢，则抢第i-1个房间
        }

        printf("%d\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}

/**********************************************************************
	Problem: 1023
	User: 202100202053
	Language: C++
	Result: AC
	Time:30 ms
	Memory:1280 kb
**********************************************************************/

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
            // TODO: ���״̬ת��
            dp[i][0]=max(dp[i-2][0], dp[i-2][1])+a;//���˵�i�����䣬���i-1�����䲻��������i-2������
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);//��i�����䲻����������i-1������
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

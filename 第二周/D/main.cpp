#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dp[220][11];

int main()
{
    int n, k;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= 200; i ++) {
        // TODO: 最小问题赋初值
        dp[i][1]=1;
        if(i==1){
            dp[1][i]=1;
        }
        else if(i>1)
        {
            dp[1][i]=0;
        }
        if(i==2){
            dp[2][2]=1;
        }
        else if(i>2)
        {
            dp[2][i]=0;
        }

    }


    while(scanf("%d%d", &n, &k) != EOF)
    {
        // TODO: 递推，dp[n][k] 为答案
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            }
        }
        printf("%d\n",dp[n][k]);

    }
    return 0;
}

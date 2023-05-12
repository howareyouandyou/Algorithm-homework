#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

const int MAXN=1e3+1;
int dp[MAXN][MAXN];

int main()
{
    string a,b;
    while(cin>>a)
    {
        cin>>b;
        int len_a=a.length();
        int len_b=b.length();
        for(int i=0;i<=len_a;i++)
            dp[i][0]=0;
        for(int j=0;j<=len_b;j++)
            dp[0][j]=0;
        //dp[i][j]指a的前i个元素和b的前j个元素的LCS
        for(int i=1;i<=len_a;i++)
        {
            for(int j=1;j<=len_b;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    //a[i-1]和b[j-1]配对可以使dp[i][j]加上一
                    //dp[i][j]=dp[i-1][j-1]+1;
                    //滚动数组实现
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                }
                else
                {
                    //dp[i][j]的解来自子问题dp[i][j-1],dp[i-1][j]
                    //dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    //滚动数组
                    dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);
                }
            }
        }
        cout<<dp[len_a%2][len_b]<<endl;
    }
}

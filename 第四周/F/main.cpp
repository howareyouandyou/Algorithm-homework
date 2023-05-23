#include <iostream>

using namespace std;

const int mod=1e9+7;
const int MAXN=1e4;
int dp[MAXN];
int a[MAXN];


int main()
{
    int n;
    while(cin>>n)
    {
        int b;
        cin>>b;
        a[1] = b;
        for(int i = 2; i <= n; i ++) {
            a[i] = 1LL * (a[i - 1] + 1) * (a[i - 1] + 1) % mod;
        }
        int ans=0;
        for(int k=1;k<=n;k++)  //dp[k]:以第k个元素为结尾的最长上升子序列的长度
        {                          //dp[k]=max(d[j])+1
            dp[k]=1; //至少有1的长度
            for(int j=1;j<k;j++)
            {
                if(a[j]<a[k])
                {
                    dp[k]=max(dp[k],dp[j]+1);
                }
            }
            ans=max(dp[k],ans);
        }
        cout<<ans<<endl;
    }
}

/**********************************************************************
	Problem: 1155
	User: 202100202053
	Language: C++
	Result: AC
	Time:4 ms
	Memory:2264 kb
**********************************************************************/

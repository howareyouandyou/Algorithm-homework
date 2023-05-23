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
        //dp[i][j]ָa��ǰi��Ԫ�غ�b��ǰj��Ԫ�ص�LCS
        for(int i=1;i<=len_a;i++)
        {
            for(int j=1;j<=len_b;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    //a[i-1]��b[j-1]��Կ���ʹdp[i][j]����һ
                    //dp[i][j]=dp[i-1][j-1]+1;
                    //��������ʵ��
                    dp[i%2][j]=dp[(i-1)%2][j-1]+1;
                }
                else
                {
                    //dp[i][j]�Ľ�����������dp[i][j-1],dp[i-1][j]
                    //dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    //��������
                    dp[i%2][j]=max(dp[i%2][j-1],dp[(i-1)%2][j]);
                }
            }
        }
        cout<<dp[len_a%2][len_b]<<endl;
    }
}

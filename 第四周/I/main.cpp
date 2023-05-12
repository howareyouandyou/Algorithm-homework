#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

const int MAXN=1e3+1;
int dp[MAXN][MAXN];//dp[i][j]表示第i位和第j位字符间匹配数

//vector<char>s;
string s;

void func()
{
    for(int p=1;p<s.size();p++)
    {
        for(int i=0;i<s.size()-p;i++)
        {
            int j=i+p;
            if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']')||(s[i]=='{'&&s[j]=='}'))
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
            for(int k=i;k<j;k++)
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
}

int main()
{
    while(cin>>s)
    {
        func();
        cout<<dp[0][s.size()-1]<<endl;
    }
    return 0;
}

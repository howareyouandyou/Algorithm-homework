#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

const int maxn=101;
int dp[maxn][maxn]={0};//字符串str[i]到str[j]需要添加的最少字符数

int main()
{

    string str;
    while(cin>>str)
    {

        for(int i=0;i<=str.length();i++)
        {
            dp[i][i]=1;
        }
        for(int i=1;i<str.length();i++)
        {
            for(int j=i-1;j>=0;j--)//从后往前
            {
                dp[j][i]=dp[j][i-1]+1;//i到j没有寻找到与str[i]匹配的括号
                for(int k=j;k<i;k++)
                {
                    //j~i中有下标为k的字符括号与下标i的相匹配
                    if((str[k]=='('&&str[i]==')')||(str[k]=='['&&str[i]==']')||(str[k]=='{'&&str[i]=='}'))
                    {
                        dp[j][i]=min(dp[j][i],dp[j][k-1]+dp[k+1][i-1]);//j~k-1需要添加的括号数+k+1~i-1需要添加的括号数，有多个k需循环
                    }
                }
            }
        }
        if(dp[0][str.length()-1])
            cout<<dp[0][str.length()-1]<<endl;
        else
            cout<<"SZTU_WOD YYDS!"<<endl;
    }


    return 0;
}

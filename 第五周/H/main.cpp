#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

const int maxn=101;
int dp[maxn][maxn]={0};//�ַ���str[i]��str[j]��Ҫ��ӵ������ַ���

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
            for(int j=i-1;j>=0;j--)//�Ӻ���ǰ
            {
                dp[j][i]=dp[j][i-1]+1;//i��jû��Ѱ�ҵ���str[i]ƥ�������
                for(int k=j;k<i;k++)
                {
                    //j~i�����±�Ϊk���ַ��������±�i����ƥ��
                    if((str[k]=='('&&str[i]==')')||(str[k]=='['&&str[i]==']')||(str[k]=='{'&&str[i]=='}'))
                    {
                        dp[j][i]=min(dp[j][i],dp[j][k-1]+dp[k+1][i-1]);//j~k-1��Ҫ��ӵ�������+k+1~i-1��Ҫ��ӵ����������ж��k��ѭ��
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

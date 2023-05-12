#include <iostream>

using namespace std;


int dp[301][301];



int main()
{
    int n;
    while(cin>>n)
    {
        int *p=new int[n+1];
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=0;
        }
        for(int i=0;i<=n;i++)
        {
            cin>>p[i];

        }
        for(int len=2;len<=n;len++)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                int j=i+len-1;  //�趨p[i~i+1~~j-1~j]��һ����
                dp[i][j]=dp[i+1][j]+1LL*p[i-1]*p[i]*p[j];//��ʼ������С��������
                for(int k=i+1;k<j;k++)  //���һ�ξ���˷�������λ��
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
                }
            }
        }
        cout<<dp[1][n]<<endl;//���[1~n]��������ٳ˷�����
    }
}

/**********************************************************************
	Problem: 1054
	User: 202100202053
	Language: C++
	Result: AC
	Time:151 ms
	Memory:2672 kb
**********************************************************************/

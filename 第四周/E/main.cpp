#include <iostream>

using namespace std;


int dp[10001];



int main()
{
    int n;
    while(cin>>n)
    {
        int b;//��������
        cin>>b;
        int *w=new int[n+1];//����
        int *v=new int[n+1];//��ֵ
        for(int i=1;i<=n;i++)
        {
            cin>>w[i]>>v[i];
        }
//        //dp[k][y]:ֻ����ǰk����Ʒװ������y�ı��������Ž�
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=0;j<=b;j++)
//            {
//                dp[i][j]=dp[i-1][j];//ǰ����������ʼ������������Ž�
//                if(j>=w[i])
//                {
//                    dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);//������1��1~i����һ������û��i����Ҫ����v[i]��������2��1~i-1��һ��û��i
//
//                }
//            }
//        }
//        cout<<dp[n][b]<<endl;
        //���������Ż�
        for(int i=1;i<=n;i++)
        {
            for(int j=b;j>=w[i];j--)
            {
                dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
            }
        }
        cout<<dp[b]<<endl;
    }
}

/**********************************************************************
	Problem: 1154
	User: 202100202053
	Language: C++
	Result: AC
	Time:6 ms
	Memory:2224 kb
**********************************************************************/

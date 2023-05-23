#include <iostream>
#include <string.h>

using namespace std;

const int maxn=505;
int dpmax[maxn][maxn];//dp[i,j]�ӵ�i�Ѻϲ�����j�ѵ����Ž�
int dpmin[maxn][maxn];
int a[maxn];
int n;
int sum[maxn];
const int MAXN=0x3f3f3f3f;


int main()
{
    //int n;
    while(cin>>n)
    {
//        memset(dpmin,MAXN,sizeof(dpmin));
//        memset(dpmax,0,sizeof(dpmax));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i+n]=a[i];
            dpmax[i][i]=0;//��ʼ��
            dpmax[i+n][i+n]=0;
            dpmin[i][i]=0;
            dpmin[i+n][i+n]=0;
        }
        sum[0]=0;
        for(int i=1;i<=n*2;i++)//����ǰ׺��
        {
            sum[i]=sum[i-1]+a[i];
        }

        for(int len=2;len<=n;len++)//���䳤�ȣ��ϲ���ʯ�Ӹ���
        {
            for(int i=1;i<=n*2-len+1;i++)//�ӵ�i��ʯ�ӿ�ʼ
            {
                int j=i+len-1;//����j��ʯ�ӽ���
                dpmax[i][j]=dpmax[i+1][j]+sum[j]-sum[i-1];
                dpmin[i][j]=dpmin[i+1][j]+sum[j]-sum[i-1];
                for(int k=i;k<j;k++)
                {
                    dpmax[i][j]=max(dpmax[i][j],dpmax[i][k]+dpmax[k+1][j]+sum[j]-sum[i-1]);
                    dpmin[i][j]=min(dpmin[i][j],dpmin[i][k]+dpmin[k+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
        int Min=MAXN;
        int Max=0;
        for(int i=1;i<=n;i++)
        {
            Min=min(Min,dpmin[i][i+n-1]);
            Max=max(Max,dpmax[i][i+n-1]);
        }
        cout<<Min<<"\n"<<Max<<endl;
    }
    return 0;
}



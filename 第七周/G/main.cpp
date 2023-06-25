//G : ��Ѱ���
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 21;
int t[maxn][maxn];//tij����į��������j������
bool vis[maxn];
int minTime=0x3f3f3f3f;
int n;


void DFS(int k,int cur)//k:��ǰʱ��ͣ�cur:��ǰ�����䵽����Ļ���
{
//    if(k>minTime)
//        return;
    if(cur==n)//���һ̨����������������
    {
        if(k<minTime)
        {
            minTime=k;
            return;
        }
    }
    for(int i=0;i<n;i++)
    {

        if(!vis[i])
        {
            vis[i]=true;//����i������
            if(k+t[cur][i]<minTime)
                DFS(k+t[cur][i],cur+1);

            //����
            vis[i]=false;
        }
    }
}

int main()
{
    //int n,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>t[i][j];
            vis[j]=false;
        }

    }
    DFS(0,0);
    cout<<minTime<<endl;

    return 0;
}


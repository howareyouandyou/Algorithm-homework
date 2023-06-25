//G : 最佳安排
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 21;
int t[maxn][maxn];//tij：第i台机器做第j个任务
bool vis[maxn];
int minTime=0x3f3f3f3f;
int n;


void DFS(int k,int cur)//k:当前时间和，cur:当前被分配到任务的机器
{
//    if(k>minTime)
//        return;
    if(cur==n)//最后一台机器被分配了任务
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
            vis[i]=true;//任务i被分配
            if(k+t[cur][i]<minTime)
                DFS(k+t[cur][i],cur+1);

            //回溯
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


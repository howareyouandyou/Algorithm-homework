//E : 着色问题 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

const int maxn = 11;
bool a[maxn][maxn];  //图的邻接矩阵
int color[maxn];//该点所着的颜色
int sum;//
int n,m,q;

bool check(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(a[i][j]&&color[i]==color[j])//i与j点相邻且颜色相同
            return false;
    }
    return true;
}

void DFS(int cur)//枚举的点，1~n
{
    if(cur>n)
    {
        sum++;
        return;

    }
    for(int i=1;i<=m;i++)
    {
        color[cur]=i;//着色
        if(check(cur))//如果与除点cur外存在可以与点cur着相同颜色的点，递归
        {
            DFS(cur+1);
        }
        color[cur]=0;
    }
}
int main()
{
    //int n,m,q;
    cin>>n>>m>>q;
    int u,v;
    //sum=0;
    for(int i=1;i<=q;i++)
    {
        cin>>u>>v;
        //a[u-1][v-1]=a[v-1][u-1]=1;//创建邻接矩阵
        a[u][v]=a[v][u]=1;
    }
    DFS(1);
    cout<<sum<<endl;
    return 0;
}


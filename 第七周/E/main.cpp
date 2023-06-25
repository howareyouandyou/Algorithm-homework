//E : ��ɫ���� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

using namespace std;

const int maxn = 11;
bool a[maxn][maxn];  //ͼ���ڽӾ���
int color[maxn];//�õ����ŵ���ɫ
int sum;//
int n,m,q;

bool check(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(a[i][j]&&color[i]==color[j])//i��j����������ɫ��ͬ
            return false;
    }
    return true;
}

void DFS(int cur)//ö�ٵĵ㣬1~n
{
    if(cur>n)
    {
        sum++;
        return;

    }
    for(int i=1;i<=m;i++)
    {
        color[cur]=i;//��ɫ
        if(check(cur))//��������cur����ڿ������cur����ͬ��ɫ�ĵ㣬�ݹ�
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
        //a[u-1][v-1]=a[v-1][u-1]=1;//�����ڽӾ���
        a[u][v]=a[v][u]=1;
    }
    DFS(1);
    cout<<sum<<endl;
    return 0;
}


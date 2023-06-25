//B : 生成可重排列
#include <iostream>
#include <algorithm>
#include <string.h>


using namespace std;

const int MAXN=10;
int n;
int record[MAXN];//存放每次排列的组合
bool vis[MAXN];
int a[MAXN];

void DFS(int cur)//cur指本次排列组中的第几个数
{
    if(cur==n)//到达递归终点，输出
    {
        for(int i=0;i<n;i++)
        {
            //cout<<record[i]<<" ";//输出一个排列
            printf(" %d"+!i,record[i]);
        }
        printf("\n");
        return;  //注意return
    }
    int cnt=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i])//检查到没有被放的元素
            continue;
        if(a[i]!=cnt)//避免重复
        {
            vis[i]=true;//标记这个元素
            record[cur]=a[i];//放入
            cnt=a[i];//标记cnt
            DFS(cur+1);//递归第cur+1个
            vis[i]=false;//回溯取消标记
        }


    }
    //return;
}

int main()
{
    cin>>n;
    //memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        vis[i]=false;
    }
    sort(a,a+n);
    DFS(0);

    return 0;
}



/**********************************************************************
	Problem: 1160
	User: 202100202053
	Language: C++
	Result: AC
	Time:28 ms
	Memory:2184 kb
**********************************************************************/

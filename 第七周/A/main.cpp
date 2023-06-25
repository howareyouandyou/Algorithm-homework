//A : 枚举全排列
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
    for(int i=0;i<n;i++)
    {
        if(vis[i])//检查到没有被放的元素
            continue;
        vis[i]=true;//标记这个元素
        record[cur]=a[i];//放入
        DFS(cur+1);//递归第cur+1个
        vis[i]=false;//回溯取消标记
//        if(vis[i]==false)
//        {
//
//            vis[i]=true;
//            record[cur]=a[i];
//            DFS(cur+1);
//            vis[i]=false;
//        }
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
       // memset(record,0,sizeof(record));
    }
    sort(a,a+n);
    DFS(0);

    return 0;
}



/**********************************************************************
	Problem: 1159
	User: 202100202053
	Language: C++
	Result: AC
	Time:40 ms
	Memory:2184 kb
**********************************************************************/

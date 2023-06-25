//C : 生成r子集
#include <iostream>
#include <algorithm>
#include <string.h>


using namespace std;

const int MAXN=10;
int n,r;
int a[MAXN];
bool chose[MAXN];//字典序

void DFS(int cur)//cur指本次排列组中的第几个数
{
    int flag=1;

    if(cur==-1)//到达递归终点，输出
    {
        int cnt=0;
        for(int i=0;i<n;i++)//输出子集
        {

            if(chose[i])
                cnt++;
        }
        //cout<<"Cnt:"<<cnt<<endl;
        if(cnt==r)
        {
            for(int i=0,flag=1;i<n;i++)//输出子集
            {
                //int cnt=0;
                if(!chose[i])continue;
                printf(" %d"+flag,a[i]);

                flag=0;
            }
            printf("\n");

        }

        return;  //注意return
    }
    //由n-1~0逆序以便按字典序枚举子集，例如{3，2，1}的子集{2，1}字典序为011
    chose[cur]=false;//不取a[cur]后确定第cur-1个
    DFS(cur-1);
    chose[cur]=true;//取a[cur]后确定第cur-1个
    DFS(cur-1);
    //return;
}

int main()
{
    cin>>n>>r;
    //memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<r;i++)
    {
        chose[i]=false;
    }
    //sort(a,a+n);
    DFS(n-1);//注意是n-1

    return 0;
}



/**********************************************************************
	Problem: 1161
	User: 202100202053
	Language: C++
	Result: AC
	Time:2 ms
	Memory:2184 kb
**********************************************************************/

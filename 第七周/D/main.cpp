//D : n棋子问题
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const int maxn = 14;
int n;
int ans;
bool rcdx[maxn], rcdlr[maxn << 1 | 1], rcdrl[maxn << 1 | 1];
void DFS(int cur)
{
    // TODO: 处理递归终点，并基于三条线标记进行回溯
    if(cur==n)//摆完n个棋子，即为一种
    {
        ans++;
    }

    //枚举cur这一行，搜索合法的列i
    for(int i=0;i<n;i++)
    {
        if(rcdx[i]==false&&rcdlr[i+cur]==false&&rcdrl[i-cur+n]==false)//必须要当棋子的同列同对角线上没有其他棋子时，才不会攻击
        {
            rcdx[i]=rcdlr[i+cur]=rcdrl[i-cur+n]=true;
            //ans++;
            DFS(cur+1);
            rcdx[i]=rcdlr[i+cur]=rcdrl[i-cur+n]=false;

        }
    }
}
int main()
{
    memset(rcdx, 0, sizeof(rcdx));      // 列
    memset(rcdlr, 0, sizeof(rcdlr));    // 右对角线标记
    memset(rcdrl, 0, sizeof(rcdrl));    // 左对角线标记
    while(scanf("%d", &n) != EOF)
    {
        ans = 0;
        DFS(0);
        printf("%d\n", ans);
    }
    return 0;
}

/**********************************************************************
	Problem: 1045
	User: 202100202053
	Language: C++
	Result: AC
	Time:380 ms
	Memory:1200 kb
**********************************************************************/

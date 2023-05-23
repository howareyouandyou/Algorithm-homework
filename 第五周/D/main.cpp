#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int maxn = 1e5 + 10;
int max(int x, int y){return x > y ? x : y;}
int n;
int a[maxn];

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }

        bool delete0=false;//是否删除0
        int next=-1;//记录每段后面0的后一个下标
        int len=0,maxlen=0;
        //int left=0;
        for(int i = 0; i < n; i ++)
        {
            if(a[i]==1)
            {
                len++;
            }
            else if(a[i]==0)
            {
                if(delete0)
                {
                    maxlen=max(maxlen,len);
                    len=i-next;

                    next=i+1;
                }
                else
                {
                    delete0=true;
                    next=i+1;
                }
            }
        }
        maxlen=max(maxlen,len);
        if(next==-1)
        {
            printf("%d\n",-1);
        }
        else{
            printf("%d\n",maxlen);
        }

    }
    return 0;
}

/**********************************************************************
	Problem: 1102
	User: 202100202053
	Language: C++
	Result: AC
	Time:15 ms
	Memory:1592 kb
**********************************************************************/

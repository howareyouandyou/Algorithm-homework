//G : 找零钱
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n, mo[10] = {100, 50, 20, 10, 5, 2, 1};
int sum;

int CalSum(int n, int record[])
{
    // TODO: 计算需要张数，并将各钱所需张数存入record
    int sum=0;//需要的总张数
    for(int i=0;i<10&&n>0;i++)
    {
        record[i]=n/mo[i];
        n-=mo[i]*record[i];//还余下的钱
        sum+=record[i];
    }
    return sum;
}

void PrintFormation(int record[])
{
    // TODO: 基于计算的各钱张数输出式子
    int s=0;
    for(int i=0;i<10;i++)
    {
        if(record[i]!=0)
        {
            if(record[i]==1)
            {
                printf("%d",mo[i]);
                s+=1;
            }
            else
            {
                printf("%d*%d",mo[i],record[i]);
                s+=record[i];
            }
            if(s!=sum)
                printf("+");
        }

    }

}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        int record[10]={0};//每次要将record重新初始化
        sum = CalSum(n,record);
        printf("%d ", sum);
        PrintFormation(record);
        printf("=%d\n", n);
    }
    return 0;
}

/**********************************************************************
	Problem: 1037
	User: 202100202053
	Language: C++
	Result: AC
	Time:16 ms
	Memory:1200 kb
**********************************************************************/

//D : n��������
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
    // TODO: ����ݹ��յ㣬�����������߱�ǽ��л���
    if(cur==n)//����n�����ӣ���Ϊһ��
    {
        ans++;
    }

    //ö��cur��һ�У������Ϸ�����i
    for(int i=0;i<n;i++)
    {
        if(rcdx[i]==false&&rcdlr[i+cur]==false&&rcdrl[i-cur+n]==false)//����Ҫ�����ӵ�ͬ��ͬ�Խ�����û����������ʱ���Ų��ṥ��
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
    memset(rcdx, 0, sizeof(rcdx));      // ��
    memset(rcdlr, 0, sizeof(rcdlr));    // �ҶԽ��߱��
    memset(rcdrl, 0, sizeof(rcdrl));    // ��Խ��߱��
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

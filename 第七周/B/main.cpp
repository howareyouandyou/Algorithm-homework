//B : ���ɿ�������
#include <iostream>
#include <algorithm>
#include <string.h>


using namespace std;

const int MAXN=10;
int n;
int record[MAXN];//���ÿ�����е����
bool vis[MAXN];
int a[MAXN];

void DFS(int cur)//curָ�����������еĵڼ�����
{
    if(cur==n)//����ݹ��յ㣬���
    {
        for(int i=0;i<n;i++)
        {
            //cout<<record[i]<<" ";//���һ������
            printf(" %d"+!i,record[i]);
        }
        printf("\n");
        return;  //ע��return
    }
    int cnt=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i])//��鵽û�б��ŵ�Ԫ��
            continue;
        if(a[i]!=cnt)//�����ظ�
        {
            vis[i]=true;//������Ԫ��
            record[cur]=a[i];//����
            cnt=a[i];//���cnt
            DFS(cur+1);//�ݹ��cur+1��
            vis[i]=false;//����ȡ�����
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

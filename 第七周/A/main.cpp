//A : ö��ȫ����
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
    for(int i=0;i<n;i++)
    {
        if(vis[i])//��鵽û�б��ŵ�Ԫ��
            continue;
        vis[i]=true;//������Ԫ��
        record[cur]=a[i];//����
        DFS(cur+1);//�ݹ��cur+1��
        vis[i]=false;//����ȡ�����
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

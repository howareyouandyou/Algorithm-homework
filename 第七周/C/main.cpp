//C : ����r�Ӽ�
#include <iostream>
#include <algorithm>
#include <string.h>


using namespace std;

const int MAXN=10;
int n,r;
int a[MAXN];
bool chose[MAXN];//�ֵ���

void DFS(int cur)//curָ�����������еĵڼ�����
{
    int flag=1;

    if(cur==-1)//����ݹ��յ㣬���
    {
        int cnt=0;
        for(int i=0;i<n;i++)//����Ӽ�
        {

            if(chose[i])
                cnt++;
        }
        //cout<<"Cnt:"<<cnt<<endl;
        if(cnt==r)
        {
            for(int i=0,flag=1;i<n;i++)//����Ӽ�
            {
                //int cnt=0;
                if(!chose[i])continue;
                printf(" %d"+flag,a[i]);

                flag=0;
            }
            printf("\n");

        }

        return;  //ע��return
    }
    //��n-1~0�����Ա㰴�ֵ���ö���Ӽ�������{3��2��1}���Ӽ�{2��1}�ֵ���Ϊ011
    chose[cur]=false;//��ȡa[cur]��ȷ����cur-1��
    DFS(cur-1);
    chose[cur]=true;//ȡa[cur]��ȷ����cur-1��
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
    DFS(n-1);//ע����n-1

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

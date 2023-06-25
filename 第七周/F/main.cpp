//F : ѡ��I
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 21;
int a[maxn],b[maxn];
bool vis[maxn];
int sum=0;//���ĺͣ��жϸ����Ƿ�Ϊ����
int cnt=0;
int n,k;

bool prime(int n)//�ж��Ƿ�Ϊ����
{

    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void DFS(int e,int cur)
{
    if(cur==k)
    {
        if(prime(sum))//���������
        {
            cnt++;
            return;
        }
    }
    for(int i=e;i<n;i++)
    {

        if(!vis[i])
        {
            sum+=a[i];
            vis[i]=true;
            DFS(i+1,cur+1);
            //����
            sum-=a[i];
            vis[i]=false;
        }
    }
}

int main()
{
    //int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        vis[i]=false;
    }
    //sort(a,a+n);
    DFS(0,0);
    cout<<cnt<<endl;

    return 0;
}

//
//#include <iostream>
//#include <math.h>
//#include <algorithm>
//
//using namespace std;
//
//const int maxn = 21;
//int a[maxn],b[maxn];
//bool vis[maxn];
////���ĺͣ��жϸ����Ƿ�Ϊ����
//int cnt=0;
//int n,k;
//
//bool prime()//�ж��Ƿ�Ϊ����
//{
//    int sum=0;
//    for(int i=0;i<k;i++)
//    {
//        sum+=b[i];
//    }
//    for(int i=2;i<=sqrt(sum);i++)
//    {
//        if(sum%i==0)
//            return false;
//    }
//    return true;
//}
//
//void DFS(int e,int cur)
//{
//    if(cur==k)
//    {
//        if(prime())//���������
//        {
//            cnt++;
//            return;
//        }
//    }
//    for(int i=e;i<n;i++)
//    {
//
//        if(!vis[i])
//        {
//            b[cur]=a[i];
//            vis[i]=true;
//            DFS(i+1,cur+1);
//            //����
//            vis[i]=false;
//        }
//    }
//}
//
//int main()
//{
//    //int n,k;
//    cin>>n>>k;
//    for(int i=0;i<n;i++)
//    {
//        cin>>a[i];
//        vis[i]=false;
//    }
//    //sort(a,a+n);
//    DFS(0,0);
//    cout<<cnt<<endl;
//
//    return 0;
//}


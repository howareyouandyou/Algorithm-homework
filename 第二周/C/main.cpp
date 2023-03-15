#include <iostream>

using namespace std;

int vis[1001];

int ban(int n)
{

    int sum=1;
    if(vis[n]!=-1)
    {
        return vis[n];
    }
    for(int i=1;i<=n/2;i++)
    {
        sum+=ban(i);
    }
    vis[n]=sum;
    return sum;
}

int main()
{
    int n;
    cin>>n;
    vis[1]=1;
    for(int i=2;i<=n;i++)
    {
        vis[i]=-1;
    }
    cout<<ban(n)<<endl;
    return 0;
}

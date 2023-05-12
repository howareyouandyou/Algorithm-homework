#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
struct cft
{
    int x,y,z;
};

cft g[1001];

int dp[1001];

bool check(int i,int j)//j可以放在i上
{
    if((g[i].x>g[j].x&&g[i].y>g[j].y)||(g[i].x>g[j].y&&g[i].y>g[j].x))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dfs(int i)
{

    int &ans=dp[i];
    if(ans!=-1)
    {
        return ans;
    }
    dp[i]=g[i].z;//初始化
    for(int j=1;j<=3*n;j++)
    {
        if(check(i,j))//如果j可以放在i上
        {
            ans=max(ans,dfs(j)+g[i].z);
        }
    }
    return ans;
}


int main()
{
    //int n;
    while(cin>>n)
    {
        int j=1;
        for(int i=1;i<=n;i++)
        {
            //cin>>g[i].x>>g[i].y>>g[i].z;
            int x,y,z;
            cin>>x>>y>>z;
            //以x为高
            g[j].x=y;g[j].y=z;g[j].z=x;j++;
            //以y为高
            g[j].x=z;g[j].y=x;g[j].z=y;j++;
            //以z为高
            g[j].x=x;g[j].y=y;g[j].z=z;j++;

        }
        memset(dp,-1,sizeof(dp));
        int ans=-1;
        for(int i=1;i<j;i++)
        {
            ans=max(ans,dfs(i));
        }
        cout<<ans<<endl;
    }
}



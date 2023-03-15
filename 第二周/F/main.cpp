#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
//Ç°×ººÍ
int main()
{
    int n,m;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    //long long*a=new long long[n];
    long long*sum=new long long[n];

    for(int i=0;i<n;i++)
    {
        //cin>>sum[i];
        scanf("%lld",&sum[i]);

    }

    for(int i=0;i<n;i++)
    {
        sum[i]+=sum[i-1];
    }

    for(int i=0;i<m;i++)
    {
        int L,R;
        //cin>>L>>R;
        scanf("%d%d",&L,&R);
        printf("%lld\n",sum[R-1]-sum[L-2]);

    }
    return 0;
}

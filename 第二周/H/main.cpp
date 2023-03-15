#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
//前缀和

int arr[2000]={0};
int main()
{
    int n,m;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
    {
        int an;
        scanf("%d",&an);
        arr[1000+an]+=1;

    }

    for(int i=0;i<2000;i++)
    {
        arr[i]+=arr[i-1];   //求前缀和
    }


    for(int i=0;i<m;i++)
    {
        int k;
        scanf("%d",&k);
        cout<<n-arr[1000+k]<<endl;

    }
    return 0;
}



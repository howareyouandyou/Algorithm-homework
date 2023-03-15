#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

long long SearchBin(long long a[],int n,long long key)
{
    int low=1;
    int high=n;
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(key<=a[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return low;
}

int main()
{
    int n,m;
    //cin>>n>>m;
    scanf("%d%d",&n,&m);
    long long*a=new long long[n+1];
    for(int i=1;i<=n;i++)
    {
        //cin>>a[i];
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        long long q;
        //cin>>q;
        //cout<<SearchBin(a,n,q)<<endl;
        scanf("%lld",&q);
        printf("%lld\n",SearchBin(a,n,q));
    }
    return 0;
}

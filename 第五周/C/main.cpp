#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXNUM=2e5+9;
int a[MAXNUM];
int n,k;

bool solve(int mid)
{
    int b=0,c=0;
    for(int i=0;i<n;i++)
    {
        c=(a[i]-1+mid)/mid-1;
        b+=c;
        if(b>k)
        {
            return false;
        }
    }
    return true;
}

int main()
{

    cin>>n>>k;
    //int*a=new int [n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }

    int low=0,high=1e9+10,mid;
    while(low+1<high)  //二分
    {
        mid=(low+high)/2;

        if(solve(mid))
        {
            high=mid;//取前半段
        }
        else
        {
            low=mid;
        }
    }
    cout<<high<<endl;

    return 0;
}






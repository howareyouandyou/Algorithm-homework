#include <iostream>

using namespace std;

void Merge(int**a,int n)
{
    int k=n/2;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            a[i][j+k]=a[i][j]+k;//右上等于左上加k
            a[i+k][j+k]=a[i][j];//右下等于左上
            a[i+k][j]=a[i][j+k];//左下等于右上
        }
    }
}

void schedule(int**a,int n)
{
    if(n==1)
    {
        a[0][0]=1;
        return;
    }
    else
    {
        schedule(a,n/2);
        Merge(a,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int**a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    schedule(a,n);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

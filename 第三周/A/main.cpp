#include <iostream>


using namespace std;

const int mod=1e9+7;

int quickSort(int *a,long long low,long long high,long long k)
{
    while(1)  //直到找到值返回
    {
        long long i=low,j=high;
        int temp=a[low];
        while(i!=j)
        {
            while(i<j&&a[j]>=temp)
            {
                j--;
            }
            while(i<j&&a[i]<=temp)
            {
                i++;
            }
            if(i<j)
            {
                swap(a[i],a[j]);
            }

        }
        swap(a[low],a[i]);  //将temp（a[low]）放回自己的位置，即第i个位置

        if(k-1==i)  //基准数a[i]即为第k小的数
        {
            return a[i];
        }
        else if(k-1<i)
        {
            high=i-1; //i过大，将右边界移动到i-1的位置
        }
        else
        {
            low=i+1;
        }
    }
    return -1;

}

int main()
{
    long long n,m,k;

    cin>>n>>m>>k;
    //scanf("%lld",&n);
    //long long *a=new long long a[n];
    //long long a[100000000];
    int *a=new int[n];
    a[0] = m;
    for(long long i = 1; i < n; i ++)
        a[i] = 1LL * a[i - 1] * m % mod;

    cout<<quickSort(a,0,n-1,k)<<endl;
    return 0;
}




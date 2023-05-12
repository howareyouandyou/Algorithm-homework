#include <iostream>


using namespace std;

const int mod=1e9+7;

int quickSort(int *a,long long low,long long high,long long k)
{
    while(1)  //ֱ���ҵ�ֵ����
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
        swap(a[low],a[i]);  //��temp��a[low]���Ż��Լ���λ�ã�����i��λ��

        if(k-1==i)  //��׼��a[i]��Ϊ��kС����
        {
            return a[i];
        }
        else if(k-1<i)
        {
            high=i-1; //i���󣬽��ұ߽��ƶ���i-1��λ��
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




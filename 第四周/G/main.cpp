#include <iostream>

using namespace std;

const int mod=1e9+7;
const int MAXN=1e6+1;
int dp[MAXN];
int a[MAXN],arr[MAXN];


int BinarySearch(int arr[],int n,int x)
{ //二分查找返回答案序列arr不小于x的第一个数
    int low=1;
    int high=n;
    int mid=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}


int main()
{
    int n;
    while(cin>>n)
    {
        int b;
        cin>>b;

        a[1] = b;
        arr[1]=a[1];
        for(int i = 2; i <= n; i ++) {
            a[i] = 1LL * (a[i - 1] + 1) * (a[i - 1] + 1) % mod;
            arr[i]=0xffffffff;
        }
        int ans=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>arr[ans])//直接把a[i]接到后面
            {

                arr[++ans]=a[i];
            }
            else
            {
                int p=BinarySearch(arr,ans,a[i]);
                arr[p]=a[i];  //在arr中找到不小于a[i]的第一个数，替换掉原来的
            }
        }


        cout<<ans<<endl;
    }
}

/**********************************************************************
	Problem: 1156
	User: 202100202053
	Language: C++
	Result: RE
**********************************************************************/

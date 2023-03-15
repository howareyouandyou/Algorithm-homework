#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n)!=EOF){

        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int *brr=new int[n];
        for(int i=0;i<n;i++){
            cin>>brr[i];
        }
        int max1=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max1){
                max1=arr[i];
            }
        }
        int min1=1000;
        for(int i=0;i<n;i++){
            if(brr[i]<min1){
                min1=brr[i];
            }
        }
        if(min1>=max1){
            int k=min1-max1+1;
            //cout<<max1<<min1<<endl;
            cout<<k<<endl;

        }else{
            cout<<0<<endl;
        }

    }

    return 0;
}



/**********************************************************************
	Problem: 1005
	User: 202100202053
	Language: C++
	Result: AC
	Time:1 ms
	Memory:2176 kb
**********************************************************************/

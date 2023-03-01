#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n)!=EOF){

        int sur[200]={0};        //cin>>n;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            sur[a%200]++;
        }
        int k=0;
        for(int i=0;i<200;i++){

            if(sur[i]>=2){
                k+=(sur[i]*(sur[i]-1))/2;
            }
        }
        //int k=0;

        cout<<k<<endl;
    }

    return 0;
}



/**********************************************************************
	Problem: 1004
	User: 202100202053
	Language: C++
	Result: AC
	Time:49 ms
	Memory:2176 kb
**********************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int r,x,y;
    while(scanf("%d%d%d",&r,&x,&y)!=EOF){
        double k=sqrt(x*x+y*y);
        if(r>k){
            cout<<2<<endl;
        }else{
            k/=r;
            if(k==int(k)){
                cout<<int(k)<<endl;
            }else{
                cout<<int(k)+1<<endl;
            }



        }



    }
    return 0;
}



/**********************************************************************
	Problem: 1003
	User: 202100202053
	Language: C++
	Result: AC
	Time:1 ms
	Memory:2176 kb
**********************************************************************/

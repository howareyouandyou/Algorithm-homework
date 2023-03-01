#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    int k=0;
    while(n>=2){
        n/=2;
        k++;

    }
    cout<<k;
    return 0;
}



/**********************************************************************
	Problem: 1002
	User: 202100202053
	Language: C++
	Result: AC
	Time:0 ms
	Memory:2176 kb
**********************************************************************/

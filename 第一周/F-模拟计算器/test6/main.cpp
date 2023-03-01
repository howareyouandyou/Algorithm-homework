#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long *arr=new long long[n];  //Êý×Ö
    char *brr=new char[n-1];   //ÔËËã·û

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>brr[i];
    }

    long long p=arr[0];
    long long q=arr[1];
    char t=brr[0];
    for(int i=2;i<n;i++){
        char ct=brr[i-1];
        long long a=arr[i];
        if(ct=='*'){
            q*=a;
        }
        else{
            if(t=='+'){
                p+=q;
            }
            else if(t=='-'){
                p-=q;
            }
            else{
                p*=q;
            }
            q=a;
            t=ct;

        }
    }
    if(t=='-'){
        cout<<p-q<<endl;
    }
    else if(t=='+'){
        cout<<p+q<<endl;
    }
    else
    {
        cout<<p*q<<endl;
    }

    return 0;
}



/**********************************************************************
	Problem: 1048
	User: 202100202053
	Language: C++
	Result: AC
	Time:1 ms
	Memory:2176 kb
**********************************************************************/

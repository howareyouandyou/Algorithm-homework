#include <iostream>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int*a=new int[n];
    queue<int> q;

    for(int i=0;i<n;i++){

        cin>>a[i];
        if(q.empty()){
            q.push(a[i]);
        }
        else{
            if(a[i]>q.back()){
                q.push(a[i]);
                if(q.size()>5){
                    //int p=q.front();
                    q.pop();
                }
            }

        }

    }


    int len=q.size();
    int *b=new int[len];
    int k=0;

    for(int i=0;i<n;i++){
        if(a[i]==q.front()){

            b[k]=i+1;
            k++;
            q.pop();
        }
    }

    for(int i=0;i<len;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}



/**********************************************************************
	Problem: 1049
	User: 202100202053
	Language: C++
	Result: AC
	Time:0 ms
	Memory:2176 kb
**********************************************************************/

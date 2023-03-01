#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    string n;

    while(cin>>n){


        int j=n.size()-1;
        int k=0;
        while(n[j]=='0'){
            k++;  //后面0的个数
            j--;
            if(j==0){
                break;
            }

        }
        //int same=0;
        n.erase(n.size()-k,k);

        string m=n;
        for(int i=0;i<n.size();i++){
            m[i]=n[n.size()-1-i];
        }
        //cout<<n.size()<<" "<<m<<endl;
        if(m==n){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }










    }

    return 0;
}



/**********************************************************************
	Problem: 1006
	User: 202100202053
	Language: C++
	Result: AC
	Time:1 ms
	Memory:2180 kb
**********************************************************************/

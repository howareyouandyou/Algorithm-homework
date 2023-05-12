#include <iostream>



using namespace std;



int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b,p;
        cin>>a>>b>>p;
        int ret=1;
        for(;b;b>>=1,a=1LL*a*a%p) //b>>=1ÈÃbµÄ¹æÄ£¼õ°ë
        {
            if(b&1)
            {
                ret=1LL*ret*a%p;
            }
        }
        cout<<ret<<endl;
    }

    return 0;
}

/**********************************************************************
	Problem: 1020
	User: 202100202053
	Language: C++
	Result: AC
	Time:115 ms
	Memory:2184 kb
**********************************************************************/

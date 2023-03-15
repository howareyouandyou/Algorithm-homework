#include <iostream>
#include <math.h>



using namespace std;

int main()
{
    int n;
    cin>>n;
    int*a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ii=0,jj=0;
    int Min=9999999;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            //Min=fabs(a[ii]+a[jj]);
            int temp=fabs(a[i]+a[j]);
            if(temp<Min)
            {
                ii=i;
                jj=j;
                Min=temp;
            }
        }
    }
    cout<<ii+1<<" "<<jj+1<<endl;
    return 0;
}

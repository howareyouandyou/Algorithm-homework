//B : 分数背包
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct bao
{
    int a,b;//单价和重量
};

bool Sort(bao p1,bao p2)
{
    if(p1.a<p2.a)
    {
        return true;
    }
    else if(p1.a==p2.a)
    {
        if(p1.b<p2.b)
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        bao* p=new bao[m];

        for(int j=0;j<m;j++)
        {
            cin>>p[j].a>>p[j].b;
        }
        sort(p,p+m,Sort);
        double sum=0;//背包中物品的重量
        double n1=n;//剩余的钱
        int k=0;
        for(k=0;k<m&&n1>=p[k].a*p[k].b;k++)
        {
            n1-=p[k].a*p[k].b;
            sum+=p[k].b;
        }
        sum+=n1*1.0/p[k].a;//剩下的钱不够将这件物品全部购买下来，只能取部分购买

        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}

/**********************************************************************
	Problem: 1032
	User: 202100202053
	Language: C++
	Result: AC
	Time:20 ms
	Memory:2448 kb
**********************************************************************/

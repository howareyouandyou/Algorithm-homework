#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int mod = 1e9 + 7;
struct Node
{
    int mat[2][2];
    Node(){}
    Node(int a_, int b_, int c_, int d_)
    {
        mat[0][0] = a_;
        mat[0][1] = b_;
        mat[1][0] = c_;
        mat[1][1] = d_;
    }
    Node operator*(const Node &y)
    {
        // TODO: ����˷���ע��ȡģ
        Node z(0,0,0,0);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    z.mat[i][j]+=(1LL*mat[i][k]*y.mat[k][j])%mod;
                }
                z.mat[i][j]=z.mat[i][j]%mod;
            }
        }
        return z;
    }
};
Node Pow(Node a, int n)
{
    // TODO: ����Ŀ�����
    Node ret(1,0,0,1);  //����Ҫʹret��ʼֵΪE��
    for(;n;n>>=1,a=a*a)  //������
        if(n&1)
        {
            ret=ret*a;
        }
    return ret;


}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        // TODO: ��ʼ�������Ƶ�쳲��������еľ���
        Node x(1,1,1,0);
        Node ans = Pow(x, n);
        // TODO: ��������ж�Ӧ��쳲�������n��
        //cout<<<<endl;
        printf("%lld\n",ans.mat[0][1]);
    }
    return 0;
}


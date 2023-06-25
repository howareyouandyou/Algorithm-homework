#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 1e4 + 10;
const double inf = 1e20;
const double eps = 1e-7;


// 标准型：min Σcx, s.t. ax=b, x>=0
double a[maxn][maxm], b[maxn], c[maxm], z;
int n, m,k,mm;

double C[maxn], L[maxm], R[maxm], D[maxm];
void Pivot(int k, int l)
{
    // TODO: 向量置换，参考课本公式更新 b, a, z, c 的值
    b[k] /= a[k][l];
    for (int i = 1; i <= m; ++i)
    {
        if (i != l) a[i][l] /= a[k][l];
    }
    a[k][l] = 1 / a[k][l];
    for (int i = 1; i <= mm; ++i)
    {
        if (fabs(a[i][l]) > eps && i != k)
        {
            b[i] -= b[k] * a[i][l];
            for (int j = 1; j <= m; ++j)
            {
                if (j != l)
                    a[i][j] -= a[k][j] * a[i][l];
            }
            a[i][l] *= -a[k][l];
        }
    }
    z += c[l] * b[k];
    for (int i = 1; i <= m; ++i)
    {
        if (i != l)
            c[i] -= c[l] * a[k][i];
    }

    c[l] *= -a[k][l];

}
double Solve()
{
    while(true)
    {
        int k = 0, l = 0;
        // TODO: 参考课本判断λ和α
        // 如果存在最优解且当前不是最优解，则计算置换的向量序号，进行向量置换（调用Pivot）
        double minc=inf;
        for(l=1;l<=m;l++)
        {
            if(c[l]>eps)
            {
                break;
            }
        }
        if(l==m+1)
            return z;
        for(int i=1;i<=mm;i++)
        {
            if(a[i][l]>eps&&b[i]/a[i][l]<minc)
            {
                minc=b[i]/a[i][l],k=i;
            }
        }
        Pivot(k,l);
    }
}




int main()
{
    //int s, t, c;
    int l,r;
    while(scanf("%d", &n) != EOF)
    {
        m=n*3;
        scanf("%d", &k);
        for(int i = 1; i <= m; i ++)
            scanf("%lf", &c[i]);
        for(int i=n*2+1;i>=1;i--)
        {
            b[i]=k;
            for(int j=1;j<=n;++j)
            {
                if(i+j-1>m)
                    break;
                else a[i][i+j-1]=1;
            }
        }
        mm=n*2+1;
        for(int i=1;i<=m;++i)
        {
            mm++;
            b[mm]=1;
            a[mm][i]=1;
        }
        //printf("%d\n", (int)(-spx.Solve() + 0.5));
        printf("%.d\n",(int)(Solve()+0.5));
    }
    return 0;
}

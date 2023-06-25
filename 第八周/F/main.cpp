#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 1e4 + 10;
const double inf = 1e20;
const double eps = 1e-8;

// 标准型：min Σcx, s.t. ax=b, x>=0
double a[maxn][maxm], b[maxm], c[maxn], z;
int n, m;

void Pivot(int k, int l)
{
    // TODO: 向量置换，参考课本公式更新 b, a, z, c 的值
    b[l] /= a[l][k];//b[l]'
    for (int j = 0; j < n; j++)
    {
        if (j != k)
            a[l][j] /= a[l][k];//a[lj]'
    }
    a[l][k] = 1 / a[l][k];
    for (int i = 0; i < m; i++)
    {
        if (i == l)
            continue;
        b[i] -= a[i][k] * b[l];//b[i]'
        for (int j = 0; j < n; j++)
        {
            if (j != k)
                a[i][j] -= a[i][k] * a[l][j];//a[ij]'
        }
        a[i][k] = -a[i][k] * a[l][k];
    }
    z += c[k] * b[l];
    for (int j = 0; j < n; j++)
    {
        if (j != k)
            c[j] -= c[k] * a[l][j];
    }
    c[k] *= -a[l][k];
}
double Solve()
{
    while (true)
    {
        int k = -1, l = -1;

        // TODO: 参考课本判断λ和α
        // 如果存在最优解且当前不是最优解，则计算置换的向量序号，进行向量置换（调用Pivot）
        double minc = inf;
        for (int i = 0; i < n; i++)
        {
            if (c[i] < minc)
            {
                minc = c[i];
                k = i;
            }
        }
        if (minc > -eps)
            return z;
        double minba = inf;
        for (int i = 0; i < m; i++)
        {
            if (a[i][k] > eps && minba > b[i] / a[i][k])
            {
                minba = b[i] / a[i][k];//选出最小的l
                l = i;
            }
        }
        //if (l == -1)
        //    return inf;
        if (minba == inf)
            return inf;
        Pivot(k, l);

    }

}


int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {

        memset(c, 0, sizeof(c));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &c[i]);
            c[i] = -c[i];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                scanf("%lf", &a[i][j]);
            scanf("%lf", &b[i]);
            a[i][n + i] = 1;
        }

        n = n+m;
        m = m;
        z = 0;
        printf("Nasa can spend %d taka.\n", (int)ceil(-Solve() * m));//相上取整
    }
    return 0;
}



/**********************************************************************
	Problem: 1062
	User: 202100202053
	Language: C++
	Result: AC
	Time:58 ms
	Memory:80272 kb
**********************************************************************/

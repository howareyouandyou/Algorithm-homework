#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<math.h>

using namespace std;
const int maxn = 1e3 + 10;
const double inf = 0x7fffffff;
const double eps = 1e-8;


vector<double> b, c;
vector<vector<double> >a;
double z;
int n, m, k;


void Pivot(int k, int l)
{
    b[l] /= a[l][k];
    for (int j = 0; j < n; j++)
        if (j != k) a[l][j] /= a[l][k];
    for (int i = 0; i < m; i++)
    {
        if (i != l && fabs(a[i][k]) > eps)
        {
            b[i] -= a[i][k] * b[l];
            for (int j = 0; j < n; j++)
                if (j != k) a[i][j] -= a[i][k] * a[l][j];
            a[i][k] /= -a[l][k];
        }
    }
    z += c[k] * b[l];
    for (int j = 0; j < n; j++)
        if (j != k) c[j] -= c[k] * a[l][j];
    c[k] /= -a[l][k];
    a[l][k] = 1 / a[l][k];
}
double Solve()
{
    while (true)
    {
        int k = 0, l = 0;
        double minc = inf;
        for (int i = 0; i < n; i++)
            if (c[i] < minc)
                minc = c[k = i];
        if (minc > -eps) return z;
        double minba = inf;
        for (int i = 0; i < m; i++)
            if (a[i][k] > eps && minba - b[i] / a[i][k] > eps)
                minba = b[i] / a[i][k], l = i;
        if (minba == inf) return inf;
        Pivot(k, l);
    }
}


int main()
{
    while (scanf("%d%d%d", &n, &m, &k) != EOF)
    {
        a.resize(n * 2 - m + 1);
        b.resize(n * 2 - m + 1);
        c.resize(n);
        for (auto& x : a) x.resize(n + 1), fill(x.begin(), x.end(), 0);
        std::fill(b.begin(), b.end(), 0);
        std::fill(c.begin(), c.end(), 0);
        z = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &c[i]);
            c[i] = -c[i];
        }

        for (int i = 0; i <= n - m; i++)
        {
            for (int j = 0; j < m; j++)
                a[i][i + j] = 1;
            b[i] = k;
        }
        for (int i = 0; i < n; i++)
            b[n - m + 1 + i] = 1, a[n - m + 1 + i][i] = 1;


        m = n * 2 - m + 1;
        printf("%d\n", (int)(-Solve() + 0.5));
    }
    return 0;
}

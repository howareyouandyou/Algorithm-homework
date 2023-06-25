#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int n,m;
double a[10010][1010];
double eps=1e-7;

void Pivot(int k,int l){
    // TODO: 向量置换，参考课本公式更新 b, a, z, c 的值
    double t = a[k][l];
    a[k][l] = 1.0;
    for (int i = 0; i <= n; i++)
    {
        a[k][i] /= t;
    }
    for (int i = 0; i <= m; i++)
    {
        if (i == k || abs(a[i][l]) < eps) continue;
        double t1 = a[i][l];
        a[i][l] = 0.0;
        for (int j = 0; j <= n; j++)
        {
            a[i][j] -= t1 * a[k][j];
        }
    }
}

void Solve(){
    while (true)
    {
        int k = 0, l = 0;
        // TODO: 参考课本判断λ和α
        // 如果存在最优解且当前不是最优解，则计算置换的向量序号，进行向量置换（调用Pivot）
        double minc = 1e15;
        for (int i = 1; i <= n; i++)
        {
            if (a[0][i] > eps)
            {
                l = i;
                break;
            }
        }
        if (!l)
            return;
        for (int i = 1; i <= m; i++)
        {
            if (a[i][l] > eps && a[i][0] / a[i][l] < minc)
            {
                minc = a[i][0] / a[i][l], k = i;
            }
        }
        if (!k)
        {
            //printf("Unbounded\n");
            return;
        }

        Pivot(k, l);
    }
}

int main(){
    int s, t;
    memset(a, 0, sizeof(a));
    while (scanf("%d%d", &n, &m) != EOF)
    {

        for (int i = 1; i <= n; i++)
            scanf("%lf", &a[0][i]);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%lf", &s, &t, &a[i][0]);
            for (int j = s; j <= t; j++)
                a[i][j] = 1.0;
        }
        Solve();
        //printf("%d\n", (int)(-spx.Solve() + 0.5));
        printf("%.0lf\n",-a[0][0]);

    }
    return 0;


}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<vector>
//#include<math.h>
//using namespace std;
//const int maxn = 1e3 + 10;
//const int maxm = 1e4 + 10;
//const double inf = 1e20;
//const double eps = 1e-7;
//struct Simplex
//{
//    // 标准型：min Σcx, s.t. ax=b, x>=0
//    double a[maxn][maxm], b[maxn], c[maxm], z;
//    int n, m;
//    void Init(int n_, int m_)
//    {
//        n = n_, m = m_;
//        memset(c, 0, sizeof(c));
//        memset(a, 0, sizeof(a));
//        z = 0;
//    }
//    void Pivot(int k, int l)//执行基变换(用Pk换掉Pl）
//    {
//        // TODO: 向量置换，参考课本公式更新 b, a, z, c 的值
//        b[l]/=a[l][k];//b[l]'
//        for(int j=0;j<n;j++)
//        {
//            if(j!=k) a[l][j]/=a[l][k];//a[lj]'
//        }
//        a[l][k]=1/a[l][k];
//        for(int i=0;i<m;i++)
//        {
//            if(i==l) continue;
//            b[i]-=a[i][k]*b[l];//b[i]'
//            for(int j=0;j<n;j++)
//            {
//                if(j!=k) a[i][j]-=a[i][k]*a[l][j];//a[ij]'
//            }
//            a[i][k]=-a[i][k]*a[l][k];
//        }
//        z+=c[k]*b[l];
//        for(int j=0;j<n;j++)
//        {
//            if(j!=k) c[j]-=c[k]*a[l][j];
//        }
//        c[k]*=-a[l][k];
//    }
//    double Solve()
//    {
//
//        while(true)
//        {
//            int k = -1, l = -1;
//
//            // TODO: 参考课本判断λ和α
//            // 如果存在最优解且当前不是最优解，则计算置换的向量序号，进行向量置换（调用Pivot）
//            double minc=inf;
//            for(int i=0;i<n;i++)
//            {
//                //printf("%lf\n",c[i]);
////                if(c[i]>-eps)//有变量非负
////                {
////                    break;
////                }
//                if(c[i]<minc)
//                {
//                    minc=c[i];
//                    k=i;
//                }
//            }
//
////            k=i;
////            if(k==n)//直到所有变量都非负
////                return z;
//            if(minc>-eps) return z;
//            double minba=inf;
//            for(int i=0;i<m;i++)
//            {
//                if(a[i][k]>eps&&minba>b[i]/a[i][k])
//                {
//                    minba=b[i]/a[i][k];//选出最小的l
//                    l=i;
//                }
//            }
//            if(l==-1)
//                return inf;
////            if(minba==inf)
////                return inf;
//            Pivot(k,l);
//
//        }
//
//    }
//};
//void BuildSimple(Simplex &spx, int n, double C[], int m, double L[], double R[], double D[])
//{
//    // TODO: 基于输入数据，构建标准型，存入 spx 的 a, b, c （含义对应课本）
//    for(int i=0;i<n;i++)
//    {
//        spx.b[i]=C[i];
//        //printf("%lf\n",C[i]);
//    }
//    for(int i=0;i<m;i++)
//    {
//        spx.c[i]=-D[i];
//        for(int j=L[i]-1;j<=R[i]-1;j++)//这里要减1
//        {
//            spx.a[j][i]=1;
//        }
//    }
//
//}
//
//int n, m;
//Simplex spx;
//double C[maxn], L[maxm], R[maxm], D[maxm];
//int main()
//{
//    int s, t, c;
//    while(scanf("%d%d", &n, &m) != EOF)
//    {
//        spx.Init(m, n);
//        for(int i = 0; i < n; i ++)
//            scanf("%lf", &C[i]);
//        for(int i = 0; i < m; i ++)
//            scanf("%lf%lf%lf", &L[i], &R[i], &D[i]);
//        BuildSimple(spx, n, C, m, L, R, D);
//        printf("%d\n", (int)(-spx.Solve()+0.5));
//    }
//    return 0;
////    n=2,m= 3;spx.Init(n,m);
////    spx.c[0]=-12,spx.c[0]=-15;
////    spx.a[0][0]=0.25,spx.a[0][1]=0.5;
////    spx.a[1][0]=0.5,spx.a[1][1]=0.5;
////    spx.a[2][0]=0.25,spx.a[2][1]=0;
////    spx.b[0]= 120,spx.b[1] = 150, spx.b[2] =50;
////    int ans =-(int)(spx.Solve() - eps);
////    printf("%d\n", ans);
////    return 0;
//}

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
int n, m;

double C[maxn], L[maxm], R[maxm], D[maxm];
void Pivot(int k, int l)
{
    // TODO: 向量置换，参考课本公式更新 b, a, z, c 的值
    double t=1.0/a[k][l];
    a[k][l]=1.0;
    for(int i=0;i<=m;i++)
    {
        a[k][i]*=t;
    }
    for(int i=0;i<=n;i++)
    {
        if(i==k||abs(a[i][l])<eps) continue;
        double t1=a[i][l];
        a[i][l]=0.0;
        for(int j=0;j<=m;j++)
        {
            a[i][j]-=t1*a[k][j];
        }
    }
}
double Solve()
{
    while(true)
    {
        int k = 0, l = 0;
        // TODO: 参考课本判断λ和α
        // 如果存在最优解且当前不是最优解，则计算置换的向量序号，进行向量置换（调用Pivot）
        double minc=inf;
        for(int i=1;i<=m;i++)
        {
            if(a[0][i]>eps)
            {
                l=i;
                break;
            }
        }
        if(!l)
            return a[0][0];
        for(int i=1;i<=n;i++)
        {
            if(a[i][l]>eps&&a[i][0]/a[i][l]<minc)
            {
                minc=a[i][0]/a[i][l],k=i;
            }
        }
        if(!k)
        {
           //printf("Unbounded\n");
           return inf;
        }

        Pivot(k,l);
    }
}




int main()
{
    //int s, t, c;
    int l,r;
    while(scanf("%d%d", &n, &m) != EOF)
    {

        for(int i = 1; i <= n; i ++)
            scanf("%lf", &a[i][0]);
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d%d%lf", &l, &r, &a[0][i]);
            for(int j=l;j<=r;j++)
                a[j][i]=1.0;
        }

        //printf("%d\n", (int)(-spx.Solve() + 0.5));
        printf("%.d\n",(int)(-Solve()+0.5));
    }
    return 0;
}








#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int INFINITE = 1e10;

int a, b;

class Point
{
public:
    int x, y;
    int number;
    Point() {}
    void setpoint(int xx, int yy, int nn)
    {
        x = xx;
        y = yy;
        number = nn;
    }

};

bool cmp(const Point& p1, const Point& p2)  //将点以坐标为标准排序，横坐标优先
{
    if (p1.x != p2.x)
    {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

bool cmpy(const Point& p1, const Point& p2)
{
    return p1.y < p2.y;
}

inline double dis(const Point& p1, const Point& p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

double aa(int left, int right, Point* p)
{
    return left + right;
}

double closest_pair(int left, int right, Point* p)  //返回左区域中的点与右区域中的点的最短距离
{

    if (left == right)
        return INFINITE;
    if (left + 1 == right)
    {
        a = left;
        b = right;
        return dis(p[left], p[right]);
    }
    int m = (left + right) / 2;

    double d1 = closest_pair(left, m, p);
    double d2 = closest_pair(m + 1, right, p);
    double d = min(d1, d2);//d=两个子问题的最优解

    int k = 0;
    //Point s[9999];  //用于存放到中线距离小于d范围内的点，！！s的大小要比point的小，否则会溢出
    Point* s = new Point[right];

    for (int i = left; i <= right; i++)
    {
        if (fabs(p[m].x - p[i].x) <= d)
        {
            s[k++] = p[i];
        }
    }
    sort(s, s + k, cmpy);//按纵坐标从小到大排序

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k && (s[j].y - s[i].y <= d); j++)
        {
            double dd = dis(s[i], s[j]);
            if (d > dd)
            {
                d = dd;
                a = i;
                b = j;
            }
        }
    }
    return d;
}

int main()
{
    int n;
    cin >> n;
    Point* p = new Point[n];
    //Point point[100000];
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i].setpoint(x, y, i);

    }
    sort(p, p + n, cmp);

    double min_d = closest_pair(0, n - 1, p);
    //double min_d = divide(0, n - 1, p);
    //double min_d = Closest_Pair(0, n - 1, p);
    //cout << min_d << endl;
    //cout << a << " " <<b<< endl;
    cout << p[a].number << " " << p[b].number << endl;

    return 0;
}

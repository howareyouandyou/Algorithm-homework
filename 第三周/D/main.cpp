#include <iostream>
#include <vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

// 整数位乘
struct BigBinary
{
    vector<int> x;     // 由低位到高位保存二进制位
    bool neg;               // 标记数的正负
    void Init(){x.clear(); neg = false;}
    unsigned size(){return x.size();}
    void check0()
    {
        while(!x.empty() && x.back() == 0) x.pop_back();
        if(x.size() == 0) neg = false;
    }
    BigBinary(){Init();}
    void Print()
    {
        if(neg && !x.empty()) printf("-");
        for(int i = x.size() - 1; i >= 0; i --)
            printf("%d", x[i]);
        if(x.empty()) printf("0");
        printf("\n");
    }

};

bool Sort(BigBinary &a,BigBinary &b)  //同号数比较大小
{
    if(a.x.size()>b.x.size())
        return true;
    else if(a.x.size()<b.x.size())
        return false;
    else
        for(int i=a.x.size()-1;i>=0;i--)
        {
            if(a.x[i]==b.x[i])
                continue;
            if(a.x[i]>b.x[i])
                return true;
            else
                return false;
        }

}
BigBinary Add(BigBinary &a, BigBinary &b);
BigBinary Minus(BigBinary &a, BigBinary &b);

BigBinary Add(BigBinary &a, BigBinary &b)
{
    // TODO: 返回 a + b 的结果，小心两数异号情况
    //int m=max(a->x->size(),b->x->size());
    int c=0; //进位信号
    BigBinary k;
/**<

 */
    if(a.size() < b.size()) return Add(b, a);
    if(a.neg^b.neg==0)
    {
//        for(int i=0;i<a.size();i++)
//        {
//            int sum=0;
//            if(i<b.size())
//            {
//                sum=a.x[i]+b.x[i]+c;
//            }
//            else
//            {
//                sum=(a.x.size()>b.x.size()?a.x[i]:b.x[i])+c;
//            }
//
//            k.x.push_back(sum%2);
//            c=sum/2;
//
//        }
        if(a.size() < b.size()) return Add(b, a);
        k.x = a.x;
        for(int i = 0; i < b.size(); i ++) k.x[i] += b.x[i];
        int cur = 0;
        for(int i = 0; i < k.size(); i ++)
        {
            k.x[i] += cur;
            cur = k.x[i] >> 1;
            k.x[i] &= 1;
        }
        for(; cur; cur >>= 1) k.x.push_back(cur & 1);
        k.neg = a.neg;
        k.check0();
        return k;
    }
    else
    {
        if(!Sort(a,b)) //a为负数，b为正数
        {
            a.neg^=1;//让a符号位与1异或取反
            k=Minus(b,a);
            a.neg^=1;
        }
        else  //a为正数，b为负数
        {
            b.neg^=1;
            k=Minus(a,b);
            b.neg^=1;
        }
        return k;
    }

    //return k;

}
BigBinary Minus(BigBinary &a, BigBinary &b)
{

    // TODO: 返回 a - b 的结果，注意正负号
    BigBinary k;
    if(a.neg^b.neg==0)  //同号直接减
    {
        if(Sort(a,b))  //如果a更大
        {
//            k.neg=false;
//            for(int i=0;i<b.x.size();i++)
//            {
//                b.x[i]=~b.x[i]; //取反
//            }
//            int c=1;  //补码+1，后面循环中的作用是作为进位信号
//            for(int i=0;i<b.x.size();i++)
//            {
//                int sum=0;
//                sum=b.x[i]+c;
//
//                k.x.push_back(sum%2);
//                c=sum/2;
//
//            }
//            k=Add(a,b);
            int i;
            for(i = 0; i < b.size(); i ++)
                k.x.push_back(a.x[i] - b.x[i]);
            for(; i < a.size(); i ++)
                k.x.push_back(a.x[i]);
            for(i = 0; i < k.size(); i ++)
            {
                while(k.x[i] < 0)
                {
                    k.x[i] += 2;
                    k.x[i + 1] --;
                }
            }
            k.neg = a.neg; k.check0();
            return k;
        }
        else
        {
//            k=Minus(b,a);
//            k.neg=true;
            a.neg ^= 1;
            b.neg ^= 1;
            k= Minus(b, a);
            a.neg ^= 1;
            b.neg ^= 1;
            return k;
        }



    }
    else  //ab异号
    {
        b.neg^=1;
        k=Add(a,b);
        b.neg^=1;
//        if(a.neg) //a为负数，b为正数
//        {
//            a.neg^=1;//让a符号位与1异或取反
//            k=Add(b,a);
//            a.neg^=1;
//        }
//        else  //a为正数，b为负数
//        {
//            b.neg^=1;
//            k=Add(a,b);
//            b.neg^=1;
//        }
//        k.neg=a.neg;
        return k;
    }

    //return k;
}
BigBinary Mul(BigBinary &a, BigBinary &b)
{
    // TODO: 模拟竖式计算两数相乘
    BigBinary k;
    for(int i = 0; i < a.size(); i ++)
    {
        for(int j = 0; j < b.size(); j ++)
        {
            while(k.x.size() < i + j + 1)
                k.x.push_back(0);
            k.x[i + j] += a.x[i] & b.x[j];
        }
    }
    int cur = 0;
    for(int i = 0; i < k.size(); i ++)
    {
        k.x[i] += cur;
        cur = k.x[i] >> 1;
        k.x[i] &= 1;
    }
    for(; cur; cur >>= 1) k.x.push_back(cur & 1);
    k.neg = a.neg ^ b.neg; k.check0();
    return k;

}
void MulN2(BigBinary &a, int n_2)
{
    // TODO: 为 a 添加 n_2 个二进制0，即乘以 2^(n_2)
    int isize = a.x.size();
    a.x.resize(isize + n_2);
    for(int i = a.x.size() - 1, j = isize - 1; j >= 0; i --, j--)
        a.x[i] = a.x[j];
    for(int i = n_2 - 1; i >= 0; i --)
        a.x[i] = 0;
}
BigBinary FasterMul(BigBinary &a, BigBinary &b)
{
    // TODO: 分治优化位乘
    // 设 a = A * 2^(n/2) + B， b = C * 2^(n/2) + D
    // a*b = AC*2^n + [(A - B)(D - C) + AC + BD] * 2^(n/2) + BD
    // 注意：a 和 b 位数不一定相同，需要额外处理边界。
    if(a.size() < 2 || b.size() < 2)
        return Mul(a, b);
    if(a.size() < 100 && b.size() < 100)
        return Mul(a, b);
    if(a.size() < b.size())
        return FasterMul(b, a);

    BigBinary A, B, C, D;
    int n_2 = a.size() >> 1;
    for(int i = 0; i < n_2; i ++)
        B.x.push_back(a.x[i]);
    B.check0();
    for(int i = n_2; i < a.size(); i ++)
        A.x.push_back(a.x[i]);
    A.check0();
    BigBinary ret;
    if(b.size() < n_2)
    {
        BigBinary tmp_A_b = FasterMul(A, b);
        MulN2(tmp_A_b, n_2);
        BigBinary tmp_B_b = FasterMul(B, b);
        ret = Add(tmp_A_b, tmp_B_b);
    }
    else
    {
        for(int i = 0; i < n_2; i ++)
            D.x.push_back(b.x[i]);
        D.check0();
        for(int i = n_2; i < b.size(); i ++)
            C.x.push_back(b.x[i]);
        C.check0();
        BigBinary tmp_A_C = FasterMul(A, C);
        BigBinary tmp_B_D = FasterMul(B, D);
        //优化AD+BC，表示为(A+B)*(C+D)-(AC+BD)
        BigBinary a_A_B = Add(A, B);
        BigBinary a_D_C = Add(D, C);
        BigBinary tmp_ABDC = FasterMul(a_A_B, a_D_C);
        BigBinary ad_ACBD = Add(tmp_A_C, tmp_B_D);
        BigBinary tmp_AD_BC = Minus(tmp_ABDC, ad_ACBD);
        MulN2(tmp_A_C, n_2 * 2);
        MulN2(tmp_AD_BC, n_2);
        BigBinary tmpACADBC = Add(tmp_A_C, tmp_AD_BC);
        ret = Add(tmpACADBC, tmp_B_D);
    }
    ret.neg = a.neg ^ b.neg;
    return ret;


}
const int maxn = 1e5 + 10;
char buf[maxn];
BigBinary a, b;
int main()
{
    while(scanf("%s", buf) != EOF)
    {
        a.Init();
        b.Init();
        for(int i = strlen(buf) - 1; i >= 0; i --)
            a.x.push_back(buf[i] == '1');
        scanf("%s", buf);
        for(int i = strlen(buf) - 1; i >= 0; i --)
            b.x.push_back(buf[i] == '1');
        FasterMul(a, b).Print();
    }
    return 0;
}


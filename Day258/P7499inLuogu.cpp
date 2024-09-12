/*****************************************************************
 * 题目：「HMOI R1」概率
 * 描述：从两个集合中随机抽取两个整数，问求和为某个数的次数。
 * 思路：构造区间，然后求和。
 * 对象：SampleSum模拟采样求和。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                             // 定义长整型
#define rep(i, s, k) for (ll i = s; i <= k; i++) // 定义快速循环

template <typename T>
struct Interval
{
    T Begin, End;

    Interval(T b, T e) : Begin(b), End(e) {}

    Interval(const Interval<T> &other) : Begin(other.Begin),
                                         End(other.End) {}
};

template <typename Type>
class SampleSum
{
private:
    Interval<Type> A, B;

public:
    /* 初始化，输入两个区间。 */
    SampleSum(Interval<Type> a, Interval<Type> b) : A(a), B(b) {}

    /* 计数，求和。 */
    Type Count(Type Sum)
    {
        Type cnt = 0;
        cnt = min(Sum - A.Begin, B.End) -
              max(Sum - A.End, B.Begin) + 1;
        if (cnt < 0)
        {
            cnt = 0;
        }
        return cnt;
    }
};

int main()
{
    ll query_num;
    cin >> query_num;
    rep(i, 1, query_num)
    {
        ll a_begin, a_end;
        ll b_begin, b_end;
        cin >> a_begin >> a_end;
        cin >> b_begin >> b_end;

        Interval<ll> a(a_begin, a_end), b(b_begin, b_end);
        SampleSum<ll> ss(a, b);

        ll Sum;
        cin >> Sum;

        cout << ss.Count(Sum) << endl;
    }
    return 0;
}

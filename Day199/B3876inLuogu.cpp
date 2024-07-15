/*********************************************************
 * 题目：[信息与未来 2015] 中间值
 * 描述：输出序列中间的一个/两个数。
 * 思路：不知道能不能auto返回。
 * 函数：Middle返回序列的中间值。
 * 注意：数据的范围限制。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class NumChain
{
private:
    ll Number;
    NumChain *Next;

public:
    NumChain(ll n)
    {
        Number = n;
        Next = NULL;
    }

    void add_next(NumChain *next)
    {
        Next = next;
    }

    ll sum()
    {
        ll Sum = Number;
        NumChain *it = Next;
        while (it)
        {
            Sum += it->Number;
            it = it->Next;
        }
        return Sum;
    }
};

auto Middle(ll Num)
{
    if (Num % 2 == 0)
    {
        NumChain first(Num >> 1);
        NumChain second((Num >> 1) + 1);

        first.add_next(&second);

        return first;
    }

    return NumChain((Num + 1) >> 1);
}

int main()
{
    ll num;
    cin >> num;

    NumChain mid = Middle(num);

    cout << mid.sum() << endl;
    return 0;
}

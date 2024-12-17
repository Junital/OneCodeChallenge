/*****************************************************************
 * 题目：[COCI2016-2017#1] Tarifa
 * 描述：流量将保留到下个月，问最后还有多少流量。
 * 思路：数组求和。
 * 空间：VectorExtensions模拟数组拓展。
 * 注意：注意数据别溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace VectorExtensions
{
    /* 定义数组求和 */
    template <typename Type>
    Type ArrSum(vector<Type> &Arr)
    {
        Type Sum = 0;
        for (auto element : Arr)
        {
            Sum += element;
        }
        return Sum;
    }

    /* 某个索引后的最小值。 */
    template <typename Type>
    Type SubArrMin(vector<Type> &Arr, int Index)
    {
        int Size = Arr.size();
        assert(Index < Size);

        auto start = Arr.begin() + Index;
        return *(min_element(start, Arr.end()));
    }
}

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int main()
{
    int single_supply;
    int month_num;

    cin >> single_supply >> month_num;

    vector<int> usage(month_num);
    rep(i, 0, month_num - 1)
    {
        cin >> usage[i];
    }

    cout << single_supply * (month_num + 1) -
                VectorExtensions::ArrSum(usage)
         << endl;
    return 0;
}
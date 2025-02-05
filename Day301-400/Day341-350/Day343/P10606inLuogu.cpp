/*****************************************************************
 * 题目：物理实验 (easy)
 * 描述：给出每个结点转弯所花费的成本，且必须要经过一些路径，问最小的成本。
 * 思路：求最大结点后的最小值。
 * 空间：VectorExtensions模拟数组拓展。
 * 注意：注意数组复制复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

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

int main()
{
    int size, query_num;
    cin >> size >> query_num;

    vector<int> Arr(size);
    rep(i, 0, size - 1)
    {
        cin >> Arr[i];
    }

    int start_idx = 0;
    rep(i, 1, query_num)
    {
        int start, end;
        cin >> start >> end;
        start_idx = max(start_idx, start);
    }

    cout << VectorExtensions::SubArrMin(Arr, start_idx - 1) << endl;
    return 0;
}
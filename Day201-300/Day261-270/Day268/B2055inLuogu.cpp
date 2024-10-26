/*****************************************************************
 * 题目：均值
 * 描述：求浮点数数组的均值。
 * 思路：求和取平均。
 * 函数：Mean取平均。
 * 注意：注意输出样式。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename T>
T Mean(vector<T> Arr)
{
    T sum = 0;
    int arrsize = Arr.size();

    for (auto element : Arr)
    {
        sum += element;
    }

    return sum / arrsize;
}

int main()
{
    int size;
    cin >> size;

    vector<double> arr(size);
    rep(i, 0, size - 1)
    {
        cin >> arr[i];
    }

    cout << fixed << setprecision(4) << Mean(arr) << endl;
    return 0;
}
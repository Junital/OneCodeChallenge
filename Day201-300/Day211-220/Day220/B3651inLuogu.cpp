/*****************************************************************
 * 题目：[语言月赛202208] 数组调整
 * 描述：将数组中某一个数乘上-1，再求和。
 * 思路：数组求和。
 * 函数：ArrSum模拟数组求和。
 * 注意：注意数据的范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 定义数组求和 */
template <typename Type>
Type ArrSum(vector<Type> Arr)
{
    Type Sum = 0;
    for (auto element : Arr)
    {
        Sum += element;
    }
    return Sum;
}

int main()
{
    ll ArrSize, Idx;
    cin >> ArrSize >> Idx;

    vector<ll> arr(ArrSize);
    rep(i, 0, ArrSize - 1)
    {
        cin >> arr[i];
    }

    arr[Idx - 1] *= -1;
    cout << ArrSum(arr) << endl;
    return 0;
}

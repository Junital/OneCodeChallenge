/*********************************************************
 * 题目：「EZEC-5」修改数组
 * 描述：用最少的翻转次数获得最多连续的1。
 * 思路：直接输出1的个数即可。
 * 函数：vector_count计算数组中元素的数量。
 * 注意：注意输出格式。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 统计数组中某个元素的数量。 */
template <typename Type>
ll vector_count(vector<Type> Arr, Type Target)
{
    ll count = 0;
    for (auto a : Arr)
    {
        if (a == Target)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int arrsize;
        cin >> arrsize;
        vector<int> arr(arrsize);

        rep(i, 0, arrsize - 1)
        {
            cin >> arr[i];
        }

        cout << vector_count(arr, 1) << endl;
        rep(i, 1, arrsize)
        {
            cout << "1 ";
        }
        cout << endl;
    }
    return 0;
}
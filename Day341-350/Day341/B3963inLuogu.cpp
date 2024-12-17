/*****************************************************************
 * 题目：[语言月赛 202404] 吃苹果
 * 描述：将数组中最大值和最小值求和。
 * 思路：min_element max_element
 * 对象：无。
 * 注意：注意数据溢出。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                              // 定义长整型
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int main()
{
    int size;
    cin >> size;
    vector<ll> Arr(size);

    rep(i, 0, size - 1)
    {
        cin >> Arr[i];
    }

    cout << *(max_element(Arr.begin(), Arr.end())) +
                *(min_element(Arr.begin(), Arr.end()))
         << endl;
    return 0;
}
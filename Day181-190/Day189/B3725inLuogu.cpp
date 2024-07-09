/***********************************************
 * 题目：[语言月赛202303] M Function G
 * 描述：自定义一个函数，计算其值。
 * 思路：数学运算。
 * 函数：MFunction模拟函数。
 * 注意：注意数据范围，数组复制会占用时间。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

/* 函数，输入左值、右值和数组。 */
ll MFunction(int Left, int Right, vector<int> &Arr)
{
    if (abs(Right - Left) > 5)
    {
        int mid = (Left + Right) >> 1;
        return MFunction(Left, mid, Arr) %
                   max(MFunction(mid + 1, Right, Arr), (ll)7) +
               (Arr[mid - 1] - 1);
    }
    else
    {
        int max_it = 0;
        rep(i, Left - 1, Right - 1)
        {
            max_it = max(max_it, Arr[i]);
        }
        return max_it;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    rep(i, 0, n - 1)
    {
        cin >> arr[i];
    }

    cout << MFunction(1, n, arr) << endl;
    return 0;
}

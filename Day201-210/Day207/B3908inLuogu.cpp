/***********************************************
 * 题目：[语言月赛 202312] 异或构造题？
 * 描述：多个数求异或。
 * 思路：^计算。
 * 函数：multi_xor模拟多数异或。
 * 注意：注意数据范围。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

ll multi_xor(vector<ll> Nums)
{
    int Num_size = Nums.size();
    ll ans = Nums[0];

    rep(i, 1, Num_size - 1)
    {
        ans = ans ^ Nums[i];
    }

    return ans;
}

int main()
{
    int size;
    cin >> size;

    vector<ll> nums(size);
    rep(i, 0, size - 1)
    {
        cin >> nums[i];
    }

    cout << multi_xor(nums) << " " << 0 << endl;
    return 0;
}

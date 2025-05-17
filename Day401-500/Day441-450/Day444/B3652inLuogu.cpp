/*****************************************************************
 * 题目：[语言月赛202208] 渡荆门送别
 * 描述：每个元素和最大、最小元素的差距。
 * 思路：先求最大最小值，然后遍历一遍求解。
 * 空间：Tools模拟工具包。
 * 注意：注意数据范围和时间复杂度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
};

using namespace Tools;

int main()
{
    int n;
    cin >> n;

    vector<int64_t> arr(n);
    rep(i, 0, n - 1)
    {
        cin >> arr[i];
    }

    int64_t arr_max = *max_element(arr.begin(), arr.end());
    int64_t arr_min = *min_element(arr.begin(), arr.end());

    rep(i, 0, n - 1)
    {
        cout << arr_max - arr[i] << " ";
    }
    cout << endl;

    rep(i, 0, n - 1)
    {
        cout << arr[i] - arr_min << " ";
    }
    cout << endl;
    return 0;
}
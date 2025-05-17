/*****************************************************************
 * 题目：[洛谷 202406GESP 模拟 一级] 小洛的幸运数字
 * 描述：统计所有个位数不是3，且不是3的倍数，形成数组。
 * 思路：遍历判断即可。
 * 空间：Tools模拟工具包。
 * 注意：不会溢出，挺好。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

int main()
{
    int size;
    cin >> size;

    vector<int> qualified;
    rep(i, 1, size)
    {
        int num;
        cin >> num;

        if (num % 10 != 3 && num % 3 != 0)
        {
            qualified.push_back(num);
        }
    }

    cout << accumulate(qualified.begin(),
                       qualified.end(), 0)
         << " " << qualified.size() << endl;
    return 0;
}
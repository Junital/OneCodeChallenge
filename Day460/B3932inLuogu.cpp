/*****************************************************************
 * 题目：[语言月赛 202402] 酒
 * 描述：问三个人谁喝酒最多。
 * 思路：浮点数计算，封装函数。
 * 空间：Tools模拟工具包。
 * 注意：浮点数精度。
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
    double a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    const map<int, function<double(double, double)>> ops = {
        {0, [=](double small_bucket, double large_bucket) { // 使用 [=] 捕获外部变量
             return a * small_bucket + b * large_bucket;
         }},
        {1, [=](double small_bucket, double large_bucket)
         {
             return large_bucket * c;
         }},
        {2, [=](double small_bucket, double large_bucket)
         {
             return d * large_bucket + e;
         }}};
    const int size = 3;

    vector<double> ans(size, 0.0);

    double small_bucket, large_bucket;
    cin >> small_bucket >> large_bucket;

    rep(i, 0, size - 1)
    {
        if (auto it = ops.find(i); it != ops.end())
        {
            ans[i] = it->second(small_bucket, large_bucket);
        }
    }

    int min_idx = max_element(ans.begin(), ans.end()) - ans.begin();
    cout << min_idx + 1 << " " << fixed << setprecision(2) << ans[min_idx] << endl;
    return 0;
}
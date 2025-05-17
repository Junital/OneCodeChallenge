/*****************************************************************
 * 题目：[CCC 2024 J3] Bronze Count
 * 描述：问铜牌的分数，和获得铜牌的人数。
 * 思路：n_max_element和count？
 * 函数：nth_largest_in_map模拟map容器寻找第n大的数。
 * 注意：时间复杂度只能是nlogn之内。
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

// 函数用于从 map 容器中找到第 N 大的数
template <typename K, typename V>
pair<K, V> nth_largest_in_map(const map<K, V> &s, int N)
{
    if (N > static_cast<int>(s.size()) || N <= 0)
    {
        throw std::out_of_range("N is out of the range of the map.");
    }

    auto it = s.rbegin();
    // 将反向迭代器向前移动 N - 1 步
    std::advance(it, N - 1);
    return *it;
}

int main()
{
    int size;
    cin >> size;

    map<int, int> scores;
    rep(i, 0, size - 1)
    {
        int s;
        cin >> s;
        scores[s]++;
    }

    auto bronze = nth_largest_in_map(scores, 3);
    cout << bronze.first << " " << bronze.second << endl;
    return 0;
}
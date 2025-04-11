/*****************************************************************
 * 题目：[CCC 2024 J1] Conveyor Belt Sushi
 * 描述：不同的盘子的价格不同，问最后总价多少。
 * 思路：map映射相乘。
 * 函数：map_multiply模拟映射相乘。
 * 注意：保持可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>
#include <type_traits>

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

// 模板函数，用于计算两个 map 的乘积
template <typename K, typename V>
V map_multiply(const std::map<K, V> &map1, const std::map<K, V> &map2)
{
    /* 判断类型。 */
    if (!(is_same<V, int>::value || is_same<V, long long>::value ||
          is_same<V, double>::value || is_same<V, int64_t>::value))
    {
        throw invalid_argument("Value type must allow calculation.");
    }

    V result = 0;
    for (const auto &pair : map2)
    {
        auto it = map1.find(pair.first);
        if (it != map1.end())
        {
            result += it->second * pair.second;
        }
        else
        {
            throw invalid_argument("The key values of Map1 should contain all the key values of Map2.");
        }
    }
    return result;
}

int main()
{
    const map<char, int> price = {{'R', 3}, {'G', 4}, {'B', 5}};
    map<char, int> number = {};

    cin >> number['R'] >> number['G'] >> number['B'];
    cout << map_multiply(price, number) << endl;
    return 0;
}
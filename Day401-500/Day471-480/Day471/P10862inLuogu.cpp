/*****************************************************************
 * 题目：[HBCPC2024] Spicy or Grilled?
 * 描述：不同的人想吃不同的汉堡，问要花多少钱。
 * 思路：模拟一个统计者。
 * 结构体：CostStatis模拟花费统计。
 * 注意：不要浪费空间。
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

template <typename T>
struct CostStatis
{
    vector<T> Num;
    vector<T> UnitPrice; // 单价
    size_t Size;

    CostStatis(size_t size) : Size(size), Num(size), UnitPrice(size) {}

    /* 获得总价。 */
    T get_sum()
    {
        T sum = 0;
        for (size_t i = 0; i < Size; i++)
        {
            sum += Num[i] * UnitPrice[i];
        }

        return sum;
    }
};

int main()
{
    const int size = 2;

    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int total_num;
        cin >> total_num;

        CostStatis<int> CoSt(size);
        cin >> CoSt.Num[1];
        CoSt.Num[0] = total_num - CoSt.Num[1];
        // cout << CoSt.Num[0] << " ";

        rep(j, 0, size - 1)
        {
            cin >> CoSt.UnitPrice[j];
        }

        cout << CoSt.get_sum() << endl;
    }
    return 0;
}
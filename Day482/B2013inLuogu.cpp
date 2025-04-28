/*****************************************************************
 * 题目：温度表达转化
 * 描述：将华氏温度转化为摄氏度。
 * 思路：按照公式进行计算。
 * 空间：Temperature模拟温度包。
 * 注意：输出格式和精度。
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

namespace Temperature
{
    template <typename T>
    T FahtoCel(T fahrenheit)
    {
        return 5.0 * (fahrenheit - 32.0) / 9.0;
    }

    template <typename T>
    T CeltoFah(T celsius)
    {
        return celsius / 5.0 * 9.0 + 32.0;
    }
};

using namespace Temperature;

int main()
{
    double fah;
    cin >> fah;
    cout << fixed << setprecision(5) << FahtoCel(fah) << endl;
    return 0;
}
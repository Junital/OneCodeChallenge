/*****************************************************************
 * 题目：幂的末尾
 * 描述：求幂次的后三位。
 * 思路：快速幂 + 取模。
 * 对象：QuickModPow模拟取模快速幂。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class QuickModPow
{
private:
    int Mod; // 取模

public:
    /* 初始化，输入模数。 */
    QuickModPow(int mod) : Mod(mod) {}

    /* 快速幂。 */
    int pow(int a, int b)
    {
        long long res = 1;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % Mod;
            a = a * a % Mod;
            b >>= 1;
        }
        return res;
    }
};

int main()
{
    const int mod = 1000;
    QuickModPow qmp(mod);

    int a, b;
    cin >> a >> b;
    cout << setfill('0') << setw(3) << qmp.pow(a, b) << endl;
    return 0;
}

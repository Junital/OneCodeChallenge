/*********************************************************
 * 题目：糖果
 * 描述：输入总数和模数，求出需要加多少（>0），能使总数被模数整除。
 * 思路：根据是否能整除进行判断。
 * 函数：ResidualMod模拟残余模数。
 * 注意：注意数据范围。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

int ResidualMod(int Num, int Mod)
{
    if (Num % Mod)
    {
        return Mod - (Num % Mod);
    }

    return Mod;
}

int main()
{
    int num, mod;
    cin >> num >> mod;

    cout << ResidualMod(num, mod) << endl;
    return 0;
}

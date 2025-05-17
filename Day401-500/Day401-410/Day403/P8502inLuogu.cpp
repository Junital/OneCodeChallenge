/*****************************************************************
 * 题目：『MGOI』Simple Round I | A. 魔法数字
 * 描述：找到最大的偶数，2次幂不会超过某个数。
 * 思路：log函数。
 * 对象：无。
 * 注意：注意函数返回类型和各种情况。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Num;
    cin >> Num;

    int ans = floor(log2(Num - 1));
    cout << ans - ans % 2 << endl;
    return 0;
}
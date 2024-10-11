/*****************************************************************
 * 题目：「PMOI-3」公平正义
 * 描述：切蛋糕，问如何切能保证每个人都能分到1/n。
 * 思路：ceil(n / 2)
 * 对象：Cake模拟蛋糕。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Cake
{
private:
    const int cut_bonus = 2;

public:
    /* 输入几个人吃，输出需要几刀。 */
    int cut(int num)
    {
        if (num == 1) // 特殊判断，num = 1就不需要切。
        {
            return 0;
        }
        return (num + 1) / cut_bonus;
    }
};

int main()
{
    Cake c;
    int query_num;
    cin >> query_num;

    rep(i, 1, query_num)
    {
        int num;
        cin >> num;
        cout << c.cut(num) << endl;
    }
    return 0;
}
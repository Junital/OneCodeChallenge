/*****************************************************************
 * 题目：[语言月赛202301] 九九乘方表
 * 描述：制作乘方表的前n行。
 * 思路：双重循环 + 结果复用。
 * 对象：PowTable模拟乘方表。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class PowTable
{
private:
public:
    /* 输入行数，构建乘方表。 */
    void maketable(int row_num)
    {
        rep(i, 1, row_num)
        {
            ll res = i;
            rep(j, 1, i)
            {
                cout << i << " ^ " << j << " = " << res << " ";
                res *= i;
            }
            cout << endl;
        }
    }
};

int main()
{
    PowTable pt;
    int row_num;
    cin >> row_num;

    pt.maketable(row_num);
    return 0;
}
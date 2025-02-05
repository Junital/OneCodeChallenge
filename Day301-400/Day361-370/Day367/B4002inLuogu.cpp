/*****************************************************************
 * 题目：[GESP202406 二级] 平方之和
 * 描述：问一个数是否能由两个平方相加组成。
 * 思路：初始化，把所有平方放进去。
 * 对象：SquareSum模拟平方之和。
 * 注意：注意通用性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class SquareSum
{
private:
    const int MAXBASE = 1000;
    set<int> sums;

    /* 初始化，封装所有平方。 */
    void init()
    {
        rep(i, 1, MAXBASE)
        {
            rep(j, 1, MAXBASE)
            {
                sums.insert(i * i + j * j);
            }
        }
    }

public:
    /* 初始化 */
    SquareSum() { init(); }

    /* 请求，输入一个数字，判断是否是平方和。 */
    bool query(int Num)
    {
        return (sums.count(Num) > 0);
    }
};

int main()
{
    SquareSum ss;
    int size;
    cin >> size;

    rep(i, 1, size)
    {
        int num;
        cin >> num;
        if (ss.query(num))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
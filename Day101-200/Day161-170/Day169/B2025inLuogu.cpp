/**********************************************************
 * 题目：输出字符菱形
 * 描述：输出一个对角线长为5的菱形。
 * 思路：遍历输出。
 * 对象：DiamondPrint模拟输出菱形
 * 注意：封装好，增加拓展性。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class DiamondPrint
{
private:
    /* 计算第n行的数量 */
    int calNum(int Len, int Idx)
    {
        return min(Idx - 0, Len + 1 - Idx) * 2 - 1;
    }

    /* 计算空格数量 */
    int calSpace(int Len, int Idx)
    {
        return (Len - calNum(Len, Idx)) / 2;
    }

public:
    /* 输入字符和对角线长度，进行打印。 */
    void print(int Len, char ch)
    {
        rep(i, 1, Len)
        {
            int space_num = calSpace(Len, i);
            int ch_num = calNum(Len, i);
            rep(j, 1, space_num)
            {
                cout << " ";
            }
            rep(j, 1, ch_num)
            {
                cout << ch;
            }
            rep(j, 1, space_num)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    DiamondPrint dp;

    dp.print(5, '*');
    // dp.print(10, '/');
    return 0;
}

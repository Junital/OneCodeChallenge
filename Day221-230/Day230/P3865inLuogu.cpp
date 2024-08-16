/*****************************************************************
 * 题目：[GESP202309 二级] 小杨的 X 字矩阵
 * 描述：输出一个X字型。
 * 思路：简单输出。
 * 对象：X模拟x字形。
 * 注意：注意判断条件。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class X
{
private:
    char blank;
    char fill;

public:
    /* 初始化输入填充和空白。 */
    X(char f = '+', char b = '-') : blank(b), fill(f) {}

    /* 输出。 */
    void print(int Num)
    {
        rep(i, 1, Num)
        {
            rep(j, 1, Num)
            {
                if (i == j || i + j == Num + 1)
                {
                    cout << fill;
                }
                else
                {
                    cout << blank;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    X x;
    int num;
    cin >> num;
    x.print(num);
    return 0;
}

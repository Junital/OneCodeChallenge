/*****************************************************************
 * 题目：[COCI2012-2013#3] SAHOVNICA
 * 描述：绘制一个克罗地亚棋盘。
 * 思路：取模的方式计算。
 * 对象：CroatianBoard模拟克罗地亚棋盘。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CroatianBoard
{
private:
public:
    /* 绘制。 */
    void draw(pair<int, int> LatticeNum,
              pair<int, int> LatticeSize)
    {
        rep(i, 0, LatticeNum.first * LatticeSize.first - 1)
        {
            rep(j, 0, LatticeNum.second * LatticeSize.second - 1)
            {
                if ((i / LatticeSize.first) % 2 == (j / LatticeSize.second) % 2)
                {
                    cout << "X";
                }
                else
                {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    pair<int, int> ln, ls;
    cin >> ln.first >> ln.second;
    cin >> ls.first >> ls.second;

    CroatianBoard cb;
    cb.draw(ln, ls);
    return 0;
}

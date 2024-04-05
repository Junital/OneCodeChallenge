/***********************************************
 * 题目：【深基5.例7】工艺品制作
 * 描述：对一个玻璃立方体进行切割，
        每次确定一个立方体的切割范围，求最后剩下的体积。
 * 思路：最成熟的算法是模拟。
 * 对象：CutGlassCube模拟切割玻璃立方体。
 * 注意：无。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CutGlassCube
{
private:
    int Length, Width, Height;
    vector<vector<vector<bool>>> Cube; // 立方体，true为存在，false为不存在

public:
    /* 初始化，输入立方体的长宽高。 */
    CutGlassCube(int length, int width, int height)
        : Length(length), Width(width), Height(height)
    {
        Cube.resize(Length + 1);
        rep(i, 1, Length)
        {
            Cube[i].resize(Width + 1);
            rep(j, 1, Width)
            {
                Cube[i][j].resize(Height + 1, true);
            }
        }
    }

    /* 切割。 */
    void Cut(int startLength, int startWidth, int startHeight,
             int endLength, int endWidth, int endHeight)
    {
        rep(i, startLength, endLength)
        {
            rep(j, startWidth, endWidth)
            {
                rep(k, startHeight, endHeight)
                {
                    Cube[i][j][k] = false;
                }
            }
        }
    }

    /* 求出余下的小方块数量。 */
    int Count()
    {
        int count = 0;
        rep(i, 1, Length)
        {
            rep(j, 1, Width)
            {
                rep(k, 1, Height)
                {
                    if (Cube[i][j][k])
                    {
                        count += 1;
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    int l, w, h;
    cin >> l >> w >> h;

    CutGlassCube cgc(l, w, h);

    int q;
    cin >> q;

    rep(i, 1, q)
    {
        int sl, sw, sh;
        int el, ew, eh;

        cin >> sl >> sw >> sh >> el >> ew >> eh;

        cgc.Cut(sl, sw, sh, el, ew, eh);
    }

    cout << cgc.Count() << endl;
    return 0;
}
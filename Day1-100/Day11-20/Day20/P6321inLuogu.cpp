/************************************************************
 * 题目：[USACO06OCT] Another Cow Number Game G
 * 要求：给定放大镜的横向纵向拉伸长度，要求给出放大之后的图像。
 * 作者：Junital
 * 思路：就是一个输出游戏
 * 对象：MagnifyGlass放大镜
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速循环

/* 这是一个放大镜，可以放大图像 */
class MagnifyGlass
{
private:
    int rowMag;               // 纵向的拉伸幅度
    int colMag;               // 横向的拉伸幅度
    int MapRow;               // 原始影像的行
    int MapCol;               // 原始影像的列
    vector<string> OriginMap; // 初始的影像

public:
    /* 初始化，输入纵向、横向的拉伸幅度 */
    MagnifyGlass(int rm, int cm) : rowMag(rm), colMag(cm) {}

    /* 用于输入原始影像，参数为影像的行和列 */
    void InputMap(int row, int col)
    {
        /* 初始影像清空，对行列进行赋值 */
        OriginMap.clear();
        MapRow = row;
        MapCol = col;

        /* 输入每一行 */
        rep(i, 1, MapRow)
        {
            string str;
            cin >> str;

            assert(str.size() == MapCol); // 检验一下列数对不对的上

            OriginMap.push_back(str);
        }
    }

    /* 用于输出放大后的影像 */
    void PrintMagni()
    {
        rep(i, 0, MapRow - 1)
        {
            rep(ii, 1, rowMag) // 每一行重复rowMag次
            {
                rep(j, 0, MapCol - 1)
                {
                    rep(jj, 1, colMag) // 每一列重复colMag次
                    {
                        cout << OriginMap[i][j];
                    }
                }
                cout << endl;
            }
        }
    }
};

int main()
{
    int row, col;       // 原始影像的行和列
    int rowMag, colMag; // 放大的伸缩比例

    cin >> row >> col >> rowMag >> colMag;
    MagnifyGlass mg(rowMag, colMag);

    /* 输入原始图像，输出放大后的图像 */
    mg.InputMap(row, col);
    mg.PrintMagni();
}
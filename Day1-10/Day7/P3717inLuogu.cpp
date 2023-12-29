/************************************************************
 * 题目：[AHOI2017初中组] cover
 * 要求：在一个地图上，有一些能探测一定半径范围的检测器，最终需要输出所有能被探测的点的个数。
 * 作者：Junital
 * 思路：拿一个数组模拟一下，没有时间复杂度的问题。
 * 函数：DetectFromXY模拟探测器探测，MapTraverse计算被探测点的个数
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define DETECTED 1
#define UNDETECTED 0
#define rep(i, s, k) for (int i = s; i <= k; i++) // 循环简单表示

int GridMap[105][105] = {UNDETECTED}; // 用数组来代表网格图，UNDETECTED就是点没被检测，DETECTED就是检测到了。

int n; // 网格图的边长（是一个正方形）
int r; // 每个探测器的探测半径

/* 根据坐标，将周围半径的点都设为已探测 */
void DetectFromXY(int x, int y)
{
    rep(i, -r, r)
    {
        rep(j, -r, r) // 遍历整个正方形（当然不是所有点都满足在半径范围内）
        {
            if (x + i >= 1 && x + i <= n && y + j >= 1 && y + j <= n) // 判断对应的点在不在网格图内
            {
                if ((long long)i * i + j * j <= (long long)r * r) // 判断点在不在半径范围内（有可能会溢出，就用longlong转型）
                {
                    GridMap[x + i][y + j] = DETECTED;
                }
            }
        }
    }
}

/* 遍历整个网格图，统计能被检测的点 */
int MapTraverse()
{
    int sum = 0; // 用于统计被检测的点

    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            if (GridMap[i][j] == DETECTED)
            {
                sum++;
            }
        }
    }

    return sum;
}

int main()
{
    int detectorCnt; // 探测器的个数
    cin >> n >> detectorCnt >> r;

    for (int i = 1; i <= detectorCnt; i++)
    {
        int x, y; // 探测器的坐标
        cin >> x >> y;
        DetectFromXY(x, y); // 模拟探测
    }

    cout << MapTraverse() << endl; // 遍历并统计被探测到的点

    return 0;
}

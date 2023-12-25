/************************************************************
 * 题目： [USACO09OCT] The Robot Plow G
 * 要求：犁地，每次犁一个矩形的区域，看最后总共犁了多少面积。
 * 作者：Junital
 * 思路：拿一个数组模拟一下，好像没有时间复杂度的限制。
 * 函数：PlowField模拟犁地，CountField统计面积
 ***********************************************************/

#include <bits/stdc++.h>

#define UNPLOWED 0
#define PLOWED 1

using namespace std;

int Field[245][245] = {UNPLOWED}; // 模拟要犁的地，UNPLOWED就是没犁过，PLOWED就是犁过了
int X, Y;                         // 耕地的宽度和长度

/* 输入参数（左上角x坐标，左上角y坐标，右下角x坐标，右下角y坐标 */
void PlowField(int lux, int luy, int rdx, int rdy)
{
    for (int i = lux; i <= rdx; i++)
    {
        for (int j = luy; j <= rdy; j++)
        {
            Field[i][j] = PLOWED;
        }
    }
}

/* 返回被犁过的面积 */
int CountField()
{
    int sum = 0; // 统计被犁过的面积
    for (int i = 1; i <= Y; i++)
    {
        for (int j = 1; j <= X; j++)
        {
            // cout << Field[i][j];
            if (Field[i][j] == PLOWED)
            {
                sum++; // 如果被犁过，就加一
            }
        }
        // cout << endl;
    }
    return sum;
}

int main()
{
    int PlowTimes; // 犁地的次数
    cin >> X >> Y >> PlowTimes;

    for (int i = 1; i <= PlowTimes; i++)
    {
        int lux, luy; // 左上角x，y坐标
        int rdx, rdy; // 右下角x，y坐标
        cin >> luy >> lux >> rdy >> rdx;
        PlowField(lux, luy, rdx, rdy); // 开始犁地
    }

    cout << CountField() << endl; // 数一下犁地的面积

    return 0;
}

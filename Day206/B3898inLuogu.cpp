/***********************************************
 * 题目：[NICA #3] 彩灯装饰
 * 描述：输出金字塔，加入特殊判断。
 * 思路：正常输出。
 * 函数：print_pyraimd模拟输出金字塔。
 * 注意：加入一些接口。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 打印金字塔（输入字符、层数）。 */
void print_pyraimd(char C, int LevelNum, bool square = false, char square_ch = '!')
{
    int total_num = 2 * LevelNum - 1;
    rep(i, 1, LevelNum)
    {
        int square_num = 1;
        int current_num = i * 2 - 1;

        rep(j, 1, (total_num - current_num) / 2)
        {
            cout << " ";
        }
        rep(j, 1, current_num)
        {
            if (j == square_num * square_num)
            {
                square_num++;
                if (square)
                {
                    cout << square_ch;
                }
            }
            else
            {
                cout << C;
            }
        }
        rep(j, 1, (total_num - current_num) / 2)
        {
            cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int levelnum;
    cin >> levelnum;

    print_pyraimd('#', levelnum, true);
    return 0;
}
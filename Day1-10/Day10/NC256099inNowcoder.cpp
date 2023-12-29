/************************************************************
 * 题目：光速签到
 * 要求：输入n个数字，组成一个尽可能大的并且是10的倍数的数字，如果不行就输出0。
 * 作者：Junital
 * 思路：贪心，每次取最大的数字，查看是否能被10整除。
 * 函数：ArrangeNumber用来排列数字卡片。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 简便循环

/* 输入一个数字，返回这个数字的十进制位数 */
int GetNumberSize(int num)
{
    int size = 0; // 数字的十进制位数
    if (num == 0) // 如果数字为0，位数为1
    {
        return 1;
    }
    while (num)
    {
        size++;    // 数字的长度加一
        num /= 10; // 每次缩小一位
    }
    return size;
}

/* 输入数字卡片的个数，排布最大的数字，查看是否满足是10的倍数 */
void ArrangeNumber(int n)
{
    priority_queue<int, vector<int>, less<int>> Numbers; // 用于存储数字卡片
    rep(i, 1, n)
    {
        int x;
        cin >> x;
        Numbers.push(x); // 存入数字卡片
    }

    int LargeNumber = 0; // 存储最大的数
    rep(i, 1, n)
    {
        LargeNumber = LargeNumber * 10 + Numbers.top(); // 将目前最大的数字加入
        Numbers.pop();                                  // 清除目前最大的数字
    }

    if (LargeNumber % 10 == 0) // 判断这个数满不满足是10的倍数
    {
        /* 判断前导零的情况 */
        rep(i, 1, n - GetNumberSize(LargeNumber))
        {
            cout << 0;
        }
        cout << LargeNumber << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    int n; // 数字卡片的个数
    cin >> n;

    ArrangeNumber(n);
    return 0;
}

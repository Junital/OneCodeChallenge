/************************************************************
 * 题目：【深基4.例2】找最小值
 * 要求：输入n个数字，找出这些数字中的最小值。
 * 作者：Junital
 * 思路：简单的O(1)比较算法。
 * 函数：Min输出n个数字的最小值。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define INF 1001                                  // 每个数字小于等于1000，所以1001就相当于无穷大了
#define rep(i, s, k) for (int i = s; i <= k; i++) // 循环的快速定义

/* 输入整数n，表示有n个非负整数需要比较 */
int Min(int n)
{
    int res = INF; // 最后的结果，先赋值为INF表示未出现最小值

    rep(i, 1, n)
    {
        int x;
        cin >> x;
        res = min(x, res); // 里面调用min函数，不断更新答案
    }

    if (res == INF) // 如果结果还是无穷大，一定有问题
    {
        return -1;
    }

    return res;
}

int main()
{
    int n; // 正整数的个数
    cin >> n;
    cout << Min(n) << endl; // 调用Min函数，输出最小的值
}

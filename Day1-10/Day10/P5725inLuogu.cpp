/************************************************************
 * 题目：【深基4.习8】求三角形
 * 要求：输入边长，打印输出一个正方形和三角形，每个元素占两位，每次元素内部加一，如下所示：
    01020304
    05060708
    09101112
    13141516

          01
        0203
      040506
    07080910
 * 作者：Junital
 * 思路：样例驱动代码即可。
 * 函数：MagicPrint输出正方形和三角形
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++)

/* 输入边长，打印正方形和三角形 */
void MagicPrint(int n)
{
    int element = 1; // 正方形和三角形内部的元素

    /* 开始打印正方形 */
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            printf("%02d", element); // 占两位，前面补上0
            element++;               // 元素加一
        }
        printf("\n");
    }

    printf("\n");

    /* 开始打印三角形 */
    element = 1; // 元素归为0
    rep(i, 1, n)
    {
        rep(j, 1, n - i) // 前面n - i个元素打印空格
        {
            printf("  ");
        }
        rep(j, n - i + 1, n) // 三角形的每次要从第n - i + 1个开始打印元素
        {
            printf("%02d", element); // 占两位，前面补上0
            element++;               // 元素加一
        }
        printf("\n");
    }
}

int main()
{
    // printf("%02d", 1); 可以这样输出

    int n; // 表示正方形和直角三角形的边长
    scanf("%d", &n);

    MagicPrint(n); // 进行打印
    return 0;
}
/************************************************************
 * 题目：【深基5.习6】蛇形方阵
 * 要求：输入边长，打印输出一个蛇形方阵，每个元素占3位，如下所示：
      1  2  3  4
     12 13 14  5
     11 16 15  6
     10  9  8  7
 * 作者：Junital
 * 思路：先用一个数组存储元素，然后再打印出来
 * 函数：SnakeMatrixPrint打印蛇形矩阵，GetDir返回下一个方向，Judge判断坐标是否合适
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 简便循环
#define DIRNUM 4                                  // 方向数为4
#define INITIALDIR 0                              // 初始方向为0
#define INITIALELEMENT 1                          // 初始元素值为1
#define DIRROWIDX 0                               // 方向数组中行元素存储编号为0
#define DIRCOLIDX 1                               // 方向数组中列元素存储编号为1

int snakematrix[100][100] = {0}; // 存储蛇形矩阵，n行n列，存储应该的元素。

/* 输入目前的方向编号，返回下一个方向编号 */
int GetDir(int dir)
{
    return (dir + 1) % DIRNUM; // 由于蛇形矩阵移动方向是循环的，因此用取模来循环
}

/* 输入矩阵的边长、行数以及列数，返回布尔值表示 */
bool Judge(int n, int rown, int coln)
{
    if (rown <= n && rown >= 1 && coln <= n && coln >= 1 // 不能越界
        && snakematrix[rown][coln] == 0)                 // 已经访问过也不行
    {
        return true;
    }
    return false;
}

/* 输入矩阵的边长，通过先存储元素，然后再一一打印 */
void SnakeMatrixPrint(int n)
{
    const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 存储方向编号对应的坐标移动

    int i = 1, j = 1;             // 定义一下初始的位置
    int dir = INITIALDIR;         // 初始方向（向右）
    int element = INITIALELEMENT; // 存储初始元素大小

    while (1)
    {
        bool end_flag = false;       // 中止位，一旦为true就终止
        snakematrix[i][j] = element; // 存储蛇形矩阵元素
        element++;                   // 元素加一

        int try_times = 0;                                                              // 尝试四次
        while (!Judge(n, i + direction[dir][DIRROWIDX], j + direction[dir][DIRCOLIDX])) // 尝试坐标变换，看一下是否有问题
        {
            if (try_times == DIRNUM)
            {
                end_flag = true;
                break;
            }
            dir = GetDir(dir); // 换下一个方向
            try_times++;       // 记得要加一下尝试次数
        }

        if (end_flag)
        {
            break;
        }

        i += direction[dir][DIRROWIDX], j += direction[dir][DIRCOLIDX]; // 切换下一个坐标
    }

    /* 终于开始打印啦 */
    rep(x, 1, n)
    {
        rep(y, 1, n)
        {
            printf("%3d", snakematrix[x][y]); // 占三个字符，输入元素
        }
        printf("\n");
    }
}

int main()
{
    int n; // 矩阵的边长
    scanf("%d", &n);
    SnakeMatrixPrint(n); // 开始打印蛇形矩阵
    return 0;
}
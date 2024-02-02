/***********************************************
 * 题目：【深基3.例2】数的性质
 * 描述：有人喜欢偶数并且4<x<=12，有人喜欢至少满足一个性质的，有人喜欢恰好满足一个性质的，有人喜欢不符合这个性质的。
 * 思路：分别判断。
    |都满足|只满足一个|都不满足|
    |-----|--------|------|
    |1、2 |  2、3  |  4   |
 * 函数：JudgeNumberCharact判断数的性质。
 * 注意：覆盖所有条件。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

#define LIKE 1
#define UNLIKE 0

/* 输入一个数字，输出有哪些人喜欢。 */
void JudgeNumberCharact(int Num)
{
    int XiaoA = UNLIKE, Uim = UNLIKE, BWY = UNLIKE, ZSister = UNLIKE;

    if (Num % 2 == 0 && Num > 4 && Num <= 12)
    {
        XiaoA = LIKE, Uim = LIKE;
    }
    else if (Num % 2 == 0 || (Num > 4 && Num <= 12))
    {
        Uim = LIKE, BWY = LIKE;
    }
    else
    {
        ZSister = LIKE;
    }

    cout << XiaoA << " " << Uim << " " << BWY << " " << ZSister << endl;
}

int main()
{
    int Num;

    cin >> Num;
    JudgeNumberCharact(Num);

    return 0;
}
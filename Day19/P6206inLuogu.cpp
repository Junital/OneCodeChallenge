/************************************************************
 * 题目：[USACO06OCT] Another Cow Number Game G
 * 要求：输入一个数，每次数发生一次变换（奇数就*3+1；偶数就/2），计算最后变换到1的次数。
 * 作者：Junital
 * 思路：模拟（不知道时间能不能过）
 * 函数：OddGame用来模拟变换。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/* 输入一个数字，返回变换的次数 */
int OddGame(int Num)
{
    int Times = 0; // 记录变换的次数
    while (Num != 1)
    {
        if (Num % 2 == 1) // 如果为奇数 *3+1
        {
            Num = Num * 3 + 1;
        }
        else // 如果为偶数 /2
        {
            Num = Num / 2;
        }
        Times++; // 计数
    }
    return Times;
}

int main()
{
    int Num;
    cin >> Num;
    cout << OddGame(Num) << endl;
    return 0;
}

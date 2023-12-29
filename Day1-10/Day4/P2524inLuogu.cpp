/************************************************************
 * 题目：Uim的情人节礼物·其之弐
 * 要求：给一个顺序，输出这是字典序中的第几个。
 * 作者：Junital
 * 函数：MultiX输出累乘，StrCalDict计算字典序，GetMin给出当前序列最小的数字
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

int N;               // 序列中包含的数字个数
int nums[105] = {0}; // 记录每个数字是否被使用，0为未使用，1为使用

/* 输出为一个数的阶乘，比如2!=2*1=2 */
int multiX(int x)
{
    int sum = 1;
    do
    {
        sum *= x;        // 每次累乘
    } while ((--x) > 1); // 判断是否减到1了

    return sum;
}

/* 根据nums数组，找出最小的那个数字 */
int GetMin()
{
    for (int i = 1; i <= N; i++)
    {
        if (nums[i]) // 如果被使用，就跳到下一个
        {
            continue;
        }
        else
        {
            return i;
        }
    }
    return -1;
}

/* 输入两个数字（x必须比y小），给出两者在nums数组之间的距离 */
int GetDis(int x, int y)
{
    int sum = 0; // 统计距离
    for (int i = x; i < y; i++)
    {
        if (!nums[i])
        {
            sum++; // 如果数字未被使用，就加一
        }
    }
    return sum;
}

/* 输入为一个字符串，计算出这个字符串对应序列的字典序 */
void StrCalDict(string str)
{
    int before_num; // 用于统计在比这个序列字典序小的序列数

    for (int i = 0; i < N; i++)
    {
        int current_num = str[i] - '0'; // 目前的数字

        /* 根据当前数字计算比这个序列字典序小的序列数，加在before_num中 */
        int current_min = GetMin();
        if (current_num != current_min)
        {
            /*如果目前的数字不满足是最小的，那么就加上目前相差的距离，
            也就是目前比该数字小的个数*目前该位确定后能产生的组合个数 */
            before_num += GetDis(current_min, current_num) * multiX(N - i - 1);
        }

        nums[current_num] = 1; // 每次结束记得标注该位被使用了
        // cout << i << " " << before_num << endl;
    }

    cout << before_num + 1 << endl; // 当前的序列编号就是比它字典序小的序列数 + 1
}

int main()
{
    cin >> N;
    string str; // 存储序列的字符串
    cin >> str;

    StrCalDict(str);

    return 0;
}

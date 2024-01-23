/************************************************************
 * 题目：梦中的统计
 * 描述：给一个最大的数和最小的数，求这个区间内所有数字出现的个数。
 * 思路：分治，对每一个数字进行处理。
 * 函数：IntervalNumStast用于区间统计，SingleNumStast用于单数字统计。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 快速循环
#define ll long long                              // 定义long long
#define DIGITNUM 10                               // 定义数码的数字数量为10

/* 计算数字的长度，如123长度为3 */
int CalNumSize(int Num)
{
    ll base = DIGITNUM; // 不断扩大，试探待测数据 设为long long，因为会溢出
    int size = 1;       // 最后的结果
    while (Num >= base) // 这里应该>=，粗心了
    {
        base *= DIGITNUM;
        size++;
    }
    return size;
}

/* 单数字统计，输入一个数字，输出每个数字出现的次数vector<int>(10) */
vector<ll> SingleNumStast(int Num)
{
    /* 思路：获取数字的每一位，进行统计。*/
    int NumSize = CalNumSize(Num); // 计算位数

    const int base = DIGITNUM;
    vector<ll> NumStast(DIGITNUM, 0);

    rep(i, 1, NumSize)
    {
        int num = Num % base;
        Num /= base;
        NumStast[num]++;
    }

    return NumStast;
}

/* 统计一个区间内的数字。 */
void IntervalNumStast(int SmallNum, int LargeNum)
{
    vector<ll> NumStast(DIGITNUM, 0); // 统计数组

    rep(i, SmallNum, LargeNum)
    {
        vector<ll> SingNumStast = SingleNumStast(i);
        rep(j, 0, DIGITNUM - 1)
        {
            NumStast[j] += SingNumStast[j];
        }
    }

    rep(i, 0, DIGITNUM - 1)
    {
        cout << NumStast[i] << " ";
    }
    cout << endl;
}

int main()
{
    int smallNum;
    int largeNum;
    cin >> smallNum >> largeNum;

    IntervalNumStast(smallNum, largeNum);

    return 0;
}
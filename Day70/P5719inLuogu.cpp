/***********************************************
 * 题目：【深基4.例3】分类平均
 * 描述：输入一个最大上限和被整除数，给出范围内所有能整除数的平均值
   和不能整除数的平均值。
 * 思路：统计并计算。
 * 对象：DivideforAverage进行划分统计并计算平均值。
 * 注意：理论上应该不会溢出。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class DivideforAverage
{
private:
    int MaxLimit; // 最大上限
    int DivNum;   // 被除数

    /* 开始划分，并计算平均值。 */
    void DivideandAverage()
    {
        int CanDivSum = 0;    // 能整除的和
        int CannotDivSum = 0; // 不能整除的和
        int CanDivCnt = 0;    // 能整除的个数

        rep(i, 1, MaxLimit)
        {
            if (i % DivNum == 0)
            {
                CanDivSum += i;
                CanDivCnt++;
            }
            else
            {
                CannotDivSum += i;
            }
        }

        CanDivAver = CanDivSum * 1.0 / CanDivCnt;
        CannotDivAver = CannotDivSum * 1.0 / (MaxLimit - CanDivCnt);
    }

public:
    double CanDivAver;    // 能整除的平均值
    double CannotDivAver; // 不能整除的平均值

    /* 初始化，输入最大上限和被整除数。 */
    DivideforAverage(int maxlimit, int divnum) : MaxLimit(maxlimit), DivNum(divnum)
    {
        DivideandAverage();
    }
};

int main()
{
    int maxlimit, divnum;

    cin >> maxlimit >> divnum;

    DivideforAverage da(maxlimit, divnum);

    cout << fixed << setprecision(1) << da.CanDivAver << " " << da.CannotDivAver << endl;
}

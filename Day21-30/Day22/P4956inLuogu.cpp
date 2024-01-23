/************************************************************
 * 题目：[COCI2017-2018#6] Davor
 * 要求：输入一个数，其为52*(x,x+k,x+2k,...,x+6k)，求出最大的x值以及的k值（x不能大于100）。
 * 作者：Junital
 * 思路：见同目录的P4956Solve文件
 * 对象：SaveMoney用于帮助Davor省钱。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

class SaveMoney
{
private:
    static const int DaysPerYear = 364;    // 一年需要攒364天
    static const int AvgIncrease = 3;      // 平均每天增长3倍的IncreaseMoney
    static const int LimitBaseMoney = 100; // 基础钱金额不能超过100
    static const int BasicIncreMoney = 1;  // 每次累加的钱至少为1
    int BaseMoney;                         // 基础攒的钱金额
    int IncreaseMoney;                     // 每次累加攒的钱金额
    int Target;                            // 目标金额
    int AvgMonePerDay;

public:
    /* 初始化，输入目标金额 */
    SaveMoney(int t) : Target(t)
    {
        assert(Target % DaysPerYear == 0);
        AvgMonePerDay = Target / DaysPerYear; // 计算每天平均要攒的钱

        /* 计算基础金额和累加金额，并输出 */
        calIncreaseMoney();
        calBaseMoney();

        cout << BaseMoney << endl;
        cout << IncreaseMoney << endl;
    }

    void calIncreaseMoney()
    {
        /* 检查一下如果每天只增长最低限额，是否基础的钱不会超出最高限制
           如果超过的话，适当降低；如果没有超过，就按照最低限额来。*/
        if (AvgMonePerDay - BasicIncreMoney * AvgIncrease > LimitBaseMoney)
        {
            IncreaseMoney = ceil(1.0 * (AvgMonePerDay - LimitBaseMoney) / AvgIncrease);
        }
        else
        {
            IncreaseMoney = BasicIncreMoney;
        }
    }

    void calBaseMoney()
    {
        BaseMoney = AvgMonePerDay - AvgIncrease * IncreaseMoney; // 知道每天增长的金额，就知道基础金额了
    }
};

int main()
{
    int target;
    cin >> target;
    SaveMoney sm(target);
    return 0;
}
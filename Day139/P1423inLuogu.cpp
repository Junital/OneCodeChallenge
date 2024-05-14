/***************************************************************
 * 题目：小玉在游泳
 * 描述：衰减加法，问何时达到阈值。
 * 思路：模拟。
 * 对象：Attenuation模拟衰减。
 * 注意：保证精度。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Attenuation
{
private:
    const double start = 2.0; // 一开始的增量
    const double rate = 0.98; // 衰减率

public:
    /* 输入一个阈值，求到这个阈值的时候需要几步。 */
    int toThreshold(double Threshold)
    {
        double current = 0;       // 目前的情况。
        int steps = 0;            // 目前的步数
        double increment = start; // 增量

        while (current < Threshold)
        {
            current += increment;
            increment *= rate;
            steps++;
        }

        return steps;
    }
};

int main()
{
    Attenuation Atte;

    double threshold;
    cin >> threshold;

    cout << Atte.toThreshold(threshold) << endl;
    return 0;
}
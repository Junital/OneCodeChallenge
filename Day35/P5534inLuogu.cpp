/***********************************************
 * 题目：【XR-3】等差数列
 * 描述：根据等差数列的前两项，求出前几个数的和。
 * 思路：数学性质求和。
 * 对象：ArithmeticProgression模拟等差数列。
 * 注意：注意溢出问题。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型

class ArithmeticProgression
{
private:
    int leap;
    int start;

public:
    /* 初始化输入等差数列的第一项和第二项 */
    ArithmeticProgression(int first, int second)
    {
        start = first;
        leap = second - first;
    }

    /* 输入个数，返回前n个项之和。 */
    ll getSum(int n)
    {
        ll item = start; // 暂时存放每一项（可能会溢出）
        ll sum = 0;      // 记录求和

        for (int i = 1; i <= n; i++)
        {
            sum += item;
            item += leap;
        }

        return sum;
    }
};

int main()
{
    int First, Second, N;
    cin >> First >> Second >> N;

    ArithmeticProgression ap(First, Second);
    cout << ap.getSum(N) << endl;

    return 0;
}

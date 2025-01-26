/*****************************************************************
 * 题目：[入门赛 #18] 禁止在 int 乘 int 时不开 long long
 * 描述：判断两个数相乘是否会溢出。
 * 思路：numeric_limits来判断。
 * 空间：JudgementAids模拟辅助判断库。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace JudgementAids
{
    template <typename T>
    bool will_multiply_overflow(T a, T b)
    {
        if (a == 0 || b == 0)
        {
            return false; // 任何数乘以0都不会溢出
        }

        if (a > 0 && b > 0)
        {
            return a > numeric_limits<T>::max() / b;
        }
        else if (a < 0 && b < 0)
        {
            return a < numeric_limits<T>::max() / b;
        }
        else
        {
            if (a > 0)
            {
                // b < 0
                return a > numeric_limits<T>::min() / b;
            }
            else
            {
                // b > 0
                return a < numeric_limits<T>::min() / b;
            }
        }
    }
};

int main()
{
    int start1, end1;
    int start2, end2;
    cin >> start1 >> end1;
    cin >> start2 >> end2;

    if (JudgementAids::will_multiply_overflow(start1, start2) ||
        JudgementAids::will_multiply_overflow(start1, end2) ||
        JudgementAids::will_multiply_overflow(end1, start2) ||
        JudgementAids::will_multiply_overflow(end1, end2))
    {
        cout << "long long int" << endl;
    }
    else
    {
        cout << "int" << endl;
    }
    return 0;
}

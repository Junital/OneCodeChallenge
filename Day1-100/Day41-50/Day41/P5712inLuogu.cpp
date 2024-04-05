/***********************************************
 * 题目：【深基3.例4】Apples
 * 描述：根据吃苹果的数量输出不同的描述。
 * 思路：复数、单数。
 * 函数：EatApples用于输出对应吃苹果的描述。
 * 注意：覆盖所有条件。
 *********************************************/

#include <bits/stdc++.h>

using namespace std;

void EatApples(int Num)
{
    if (Num <= 1)
    {
        cout << "Today, I ate " << Num << " apple." << endl;
    }
    else
    {
        cout << "Today, I ate " << Num << " apples." << endl;
    }
}

int main()
{
    int Num;
    cin >> Num;
    EatApples(Num);

    return 0;
}
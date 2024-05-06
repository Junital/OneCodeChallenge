/***************************************************************
 * 题目：【深基2.习6】Apples Prologue / 苹果和虫子
 * 描述：问还有几个苹果没吃。
 * 思路：算术题。
 * 对象：EatApples模拟吃苹果。
 * 注意：注意数据范围，避免除0。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

class EatApples
{
private:
public:
    int eat(int AppleNum, int Eattime, int PastTime)
    {
        int totaltime = AppleNum * Eattime;

        if (PastTime >= totaltime)
        {
            return 0;
        }
        else
        {
            return (totaltime - PastTime) / Eattime;
        }
    }
};

int main()
{
    int AppleNum, Eattime, PastTime;
    EatApples ea;

    cin >> AppleNum >> Eattime >> PastTime;
    cout << ea.eat(AppleNum, Eattime, PastTime);

    return 0;
}

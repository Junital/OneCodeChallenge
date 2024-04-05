/************************************************************
 * 题目：[COCI2007-2008#4] VAUVAU
 * 要求：有两条看门狗，一条狗暴躁a分钟，冷静b分钟；另一条狗暴躁c分钟，冷静d分钟。现在对于一个时刻，返回暴躁狗的个数。
 * 作者：Junital
 * 思路：模拟两条狗，分别查询是否暴躁，然后整合一下。
 * 函数：QueryDog用于查询两只狗的状态。
 * 对象：Dog模拟狗。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ANGRY 1 // 暴躁状态
#define PEACE 0 // 安静状态

/* 狗，能得到处于暴躁还是安静 */
class Dog
{
private:
    int AngryTime; // 暴躁时间
    int PeaceTime; // 安静时间

public:
    /* 初始化要求输入暴躁时间和安静时间 */
    Dog(int at, int pt)
    {
        this->AngryTime = at;
        this->PeaceTime = pt;
    }

    /* 获得某个时刻的状态，暴躁为1，安静为0 */
    int getCurStat(int T)
    {
        int sT = T % (AngryTime + PeaceTime);

        /* 先暴躁再安静，并且如果取模等于0，代表还在平静期 */
        if (sT > AngryTime || sT == 0)
        {
            return PEACE;
        }
        else
        {
            return ANGRY;
        }
    }
};

void QueryDog(Dog Dog1, Dog Dog2, int T)
{
    int State1 = Dog1.getCurStat(T);
    int State2 = Dog2.getCurStat(T);

    if (State1 == ANGRY && State2 == ANGRY)
    {
        cout << "both" << endl;
    }
    else if (State1 == ANGRY || State2 == ANGRY)
    {
        cout << "one" << endl;
    }
    else
    {
        cout << "none" << endl;
    }

    return;
}

int main()
{
    int at1, pt1;
    int at2, pt2;
    cin >> at1 >> pt1 >> at2 >> pt2;

    Dog d1 = Dog(at1, pt1);
    Dog d2 = Dog(at2, pt2);

    int t1, t2, t3;
    cin >> t1;
    QueryDog(d1, d2, t1);
    cin >> t2;
    QueryDog(d1, d2, t2);
    cin >> t3;
    QueryDog(d1, d2, t3);

    return 0;
}

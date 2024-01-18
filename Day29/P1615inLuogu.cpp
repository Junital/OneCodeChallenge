/*************************************
 * 题目：西游记公司
 * 描述：输入两个时间和单位时间的生产率，计算时间段内生产的单位数。
 * 思路：计算时间差。
 * 对象：Time模拟时间。
 *************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long // 定义长整型
#define SPM 60       // 每分钟60秒
#define SPH 3600     // 每分钟3600秒

class Time
{
private:
    int h; // 小时
    int m; // 分钟
    int s; // 秒

    /* 获取绝对时间 */
    ll getAbsTime()
    {
        ll AbsTime = s + m * SPM + h * SPH;
        return AbsTime;
    }

public:
    /* 初始化，输入小时、分钟和秒 */
    Time(int h, int m, int s) : h(h), m(m), s(s) {}

    /* 初始化，要求输入格式为小时：分钟：秒 */
    Time()
    {
        scanf("%d:%d:%d", &h, &m, &s);
    }

    /* 重载运算符减号 */
    ll operator-(Time other)
    {
        ll abs1 = this->getAbsTime();
        ll abs2 = other.getAbsTime();
        return abs1 - abs2;
    }
};

/* 通过两个时刻和生产速度，输出生产的成果。 */
ll calItvlProductivity(Time t1, Time t2, int rate)
{
    ll interval = t2 - t1;
    return interval * rate;
}

int main()
{
    Time t1 = Time();
    Time t2 = Time();
    int rate;
    scanf("%d", &rate);

    printf("%lld\n", calItvlProductivity(t1, t2, rate));

    return 0;
}

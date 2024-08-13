/*****************************************************************
 * 题目：「QFOI R2」水落溪流浅浅
 * 描述：将24小时制转化为30小时制。
 * 思路：相当于一个补位。
 * 对象：ThirtyHours模拟三十小时制。
 * 注意：注意输出格式。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Time
{
private:
    int hour;
    int minute;

public:
    /* 初始化，输入小时和分钟。 */
    Time(int h, int min) : hour(h), minute(min) {}

    /* 输出。 */
    void print()
    {
        cout.setf(ios::right);
        cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << endl;
    }

    int diff(Time &other)
    {
        return (this->hour * 24 + this->minute) -
               (other.hour * 24 + other.minute);
    }

    Time add(int hour, int minute)
    {
        return Time(this->hour + hour, this->minute + minute);
    }
};

class ThirtyHours
{
private:
    Time Start;

public:
    /* 初始化，输入开始的小时和分钟。 */
    ThirtyHours(int start_h, int start_min) : Start(start_h, start_min) {}

    /* 时间转换。 */
    Time convert(Time tf)
    {
        if (tf.diff(Start) < 0)
        {
            return tf.add(24, 0);
        }
        return tf;
    }
};

int main()
{
    ThirtyHours th(6, 0);
    int hour;
    int minute;
    scanf("%d:%d", &hour, &minute);
    Time origin(hour, minute);
    Time ans = th.convert(origin);

    ans.print();
    return 0;
}

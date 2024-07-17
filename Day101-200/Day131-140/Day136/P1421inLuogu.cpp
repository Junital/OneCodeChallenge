/***************************************************************
 * 题目：小玉买文具
 * 描述：元、角换算。
 * 思路：模拟。
 * 对象：Money模拟钱。
 * 注意：无。
 **************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Money
{
private:
    int Yuan;
    int Jiao;

public:
    /* 初始化，输入元和角。 */
    Money(int yuan, int jiao = 0) : Yuan(yuan), Jiao(jiao) {}

    /* 加法。*/
    Money operator+(Money &other)
    {
        int resJiao = Jiao + other.Jiao;
        int resYuan = Yuan + other.Yuan;

        if (resJiao >= 10)
        {
            resJiao %= 10;
            resYuan += 1;
        }

        return Money(resYuan, resJiao);
    }

    /* 减法。 */
    Money operator-(Money &other)
    {
        int resJiao = Jiao - other.Jiao;
        int resYuan = Yuan - other.Yuan;

        if (resJiao < 0)
        {
            resJiao += 10;
            resYuan -= 1;
        }

        return Money(resYuan, resJiao);
    }

    /* 除法。 */
    int operator/(Money &other)
    {
        return (Yuan * 10 + Jiao) / (other.Yuan * 10 + other.Jiao);
    }
};

int main()
{
    Money pen(1, 9);

    int yuan, jiao;
    cin >> yuan >> jiao;

    Money xiaoyu(yuan, jiao);

    cout << xiaoyu / pen << endl;
    return 0;
}

/**********************************************************
 * 题目：【Mc生存】经验值
 * 描述：每次付出一些生命换取经验值，一级需要2^m经验。
 * 思路：模拟。
 * 对象：HP_ExP模拟生命值和经验值。
 * 注意：注意逻辑问题，注意溢出问题。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class HP_EXP
{
private:
    double HP; // 血量
    ll EXP;    // 经验值
    ll Level;  // 等级

public:
    HP_EXP()
    {
        EXP = 0;
        Level = 0;
        HP = 10.0;
    }

    /* 将血量换为经验。 */
    void change(double HPoffset, ll EXPincrease)
    {
        if (HP == 0) // 这里怕又救回来
        {
            return;
        }

        HP = min(10.0, max(0.0, HP - HPoffset)); // 不能高于10，不能低于0

        if (HP == 0) // 这里提防已经死了
        {
            return;
        }

        ll EXPLeft = EXPincrease + EXP; // 目前所有的经验值
        ll RequireEXP = 1 << Level;
        while (EXPLeft >= RequireEXP)
        {
            Level++;
            EXPLeft -= RequireEXP;

            RequireEXP = 1 << Level;
        }

        EXP = EXPLeft;
    }

    /* 获得等级和经验值。 */
    pair<ll, ll> getLevel_EXP()
    {
        return make_pair(Level, EXP);
    }
};

int main()
{
    HP_EXP hpexp;

    int op_time;
    cin >> op_time;

    rep(i, 1, op_time)
    {
        double hp;
        ll exp;
        cin >> hp >> exp;
        hpexp.change(hp, exp);
    }

    pair<ll, ll> Level_EXP = hpexp.getLevel_EXP();

    cout << Level_EXP.first << " " << Level_EXP.second << endl;
    return 0;
}

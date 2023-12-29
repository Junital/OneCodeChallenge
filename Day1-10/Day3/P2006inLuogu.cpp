/************************************************************
 * 题目：赵神牛的游戏
 * 要求：在体力消耗光前，能否击败最终Boss呢？
 * 作者：Junital
 * 函数：函数Fight来模拟对战。
 ***********************************************************/

#include <bits/stdc++.h>

using namespace std;

/*****************************************************************
参数（玩家的法力值，Boss的血量，技能每次消耗的法力值，技能每次造成的伤害）
返回值：如果成功打败Boss，返回True；否则返回False
******************************************************************/
bool Fight(int mana, int Boss_HP, int per_mana, int per_harm)
{
    // 特殊情况：如果攻击伤害为0，直接退出
    if (per_harm == 0)
    {
        return false;
    }

    // 计算一下击败Boss需要几次攻击
    int TimesInNeed;
    if (Boss_HP % per_harm == 0)
    {
        TimesInNeed = Boss_HP / per_harm; // 除法和取模的时候还是要当心
    }
    else
    {
        TimesInNeed = Boss_HP / per_harm + 1;
    }

    // 计算一下一共消耗的体力
    int TotalManaInNeed = TimesInNeed * per_mana;

    if (TotalManaInNeed > mana)
    {
        // 体力值超支，那么不能释放技能了
        return false;
    }
    else
    {
        // 体力值没超支，成功打败Boss
        return true;
    }
}

int main()
{
    int mana;                     // 玩家的法力
    int Boss_HP;                  // Boss的血量
    int Gambit_num;               // 招式数量
    vector<int> candidate_gambit; // 可以成功击败Boss的技能编号数组
    int success_cnt = 0;          // 记录击败Boss的技能个数

    cin >> mana >> Gambit_num >> Boss_HP;

    for (int i = 1; i <= Gambit_num; i++)
    {
        int per_mana; // 每次耗费的法力
        int per_harm; // 每次造成的伤害
        cin >> per_mana >> per_harm;
        if (Fight(mana, Boss_HP, per_mana, per_harm)) // 尝试挑战
        {
            // 挑战成功
            candidate_gambit.push_back(i); // 添加此技能编号
            success_cnt++;                 // 总的成功个数 + 1
        }
    }

    // 判断是否有成功的
    if (success_cnt == 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        // 按顺序输出技能
        for (int i = 0; i < success_cnt; i++)
        {
            cout << candidate_gambit[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
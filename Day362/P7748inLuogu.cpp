/*****************************************************************
 * 题目：[COCI2013-2014#2] VOLIM
 * 描述：一个简单游戏，算是答题版定时炸弹。
 * 思路：模拟。
 * 对象：ILoveMyCountry模拟游戏。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class ILoveMyCountry
{
private:
    int PeopleNum;
    int LimitTime;

    int get_next(int current)
    {
        int res = current + 1;
        if (res > PeopleNum)
        {
            res -= PeopleNum;
        }

        return res;
    }

public:
    /* 初始化，输入人数。 */
    ILoveMyCountry(int people_num, int limit_time)
        : PeopleNum(people_num), LimitTime(limit_time) {}

    /* 输入开始索引和游戏进程，判断最后是谁拿到了炸弹。 */
    int start(int Begin, vector<pair<int, char>> Process)
    {
        int people = Begin;
        int time_left = LimitTime;
        for (auto pic : Process)
        {
            time_left -= pic.first;

            if (time_left < 0)
            {
                return people;
            }

            assert(pic.second == 'T' ||
                   pic.second == 'N' ||
                   pic.second == 'P');

            if (pic.second == 'T')
            {
                people = get_next(people);
            }
        }

        return -1;
    }
};

int main()
{
    const int people_num = 8, time_limit = 210;
    ILoveMyCountry ilmc(people_num, time_limit);

    int start_people, process_size;
    cin >> start_people >> process_size;

    vector<pair<int, char>> process(process_size);
    rep(i, 0, process_size - 1)
    {
        cin >> process[i].first >> process[i].second;
    }
    cout << ilmc.start(start_people, process) << endl;
    return 0;
}
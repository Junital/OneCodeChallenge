/*****************************************************************
 * 题目：『JROI-5』Music
 * 描述：计算听音乐的时间，每首音乐只有第一次听才有效。
 * 思路：集合操作。
 * 对象：CloudMusic计算时间。
 * 注意：提升读入速度。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

struct MusicEntry
{
    int id;
    int time;
};

class CloudMusic
{
private:
    set<int> IDs;
    ll TotTime;

public:
    /* 初始化。 */
    CloudMusic()
    {
        TotTime = 0;
    }

    void add(vector<MusicEntry> Record)
    {
        for (auto entry : Record)
        {
            if (IDs.count(entry.id) == 0 && entry.time > 1)
            {
                IDs.insert(entry.id);
                TotTime += entry.time;
            }
        }
    }

    ll getTotalTime()
    {
        return TotTime;
    }
};

int main()
{
    ios::sync_with_stdio(false); // 提升读入速度
    cin.tie(0);

    CloudMusic cm;

    int entry_num;
    cin >> entry_num;
    vector<MusicEntry> record(entry_num);

    rep(i, 0, entry_num - 1)
    {
        cin >> record[i].id >> record[i].time;
    }

    cm.add(record);
    cout << cm.getTotalTime() << endl;
    return 0;
}
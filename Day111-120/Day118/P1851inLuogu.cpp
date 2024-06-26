/**********************************************************
 * 题目：好朋友
 * 描述：两个好朋友的约数之和等于互相的序列号，那么他们是非常好友。
 * 思路：模拟。
 * 对象：GoodFriends模拟好朋友。
 * 注意：注意溢出问题，注意时间问题。
 *********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ll long long                             // 定义长整型
#define rep(i, s, k) for (ll i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (ll i = s; i >= k; i--) // 定义倒置循环
#define MAXINT 18500                             // 定义最大值。

class GoodFriends
{
private:
    struct Friends
    {
        ll first;
        ll second;

        Friends(ll a, ll b = -1) : first(a), second(b) {}

        bool operator<(const Friends &other) const
        {
            return first < other.first;
        }
    };

    vector<Friends> BestFriends; // 存储好朋友

    /* 获得约数之和（除了自己） */
    ll getFactorSum(ll Num)
    {
        ll Sum = 1;
        ll EndNum = sqrt(Num);
        per(i, Num - 1, EndNum)
        {
            if (Num % i == 0)
            {
                Sum += i;
                Sum += (Num / i);
            }
        }

        return Sum;
    }

    /* 初始化 */
    void init()
    {
        // rep(i, 1, MAXINT)
        // {
        //     int fri = getFactorSum(i);
        //     if (getFactorSum(fri) == i && fri != i)
        //     {
        //         // cout << i << " " << fri << endl;
        //         BestFriends.push_back(Friends(i, fri));
        //     }
        // }

        BestFriends.push_back(Friends(220, 284));
        BestFriends.push_back(Friends(284, 220));
        BestFriends.push_back(Friends(1184, 1210));
        BestFriends.push_back(Friends(1210, 1184));
        BestFriends.push_back(Friends(2620, 2924));
        BestFriends.push_back(Friends(2924, 2620));
        BestFriends.push_back(Friends(5020, 5564));
        BestFriends.push_back(Friends(5564, 5020));
        BestFriends.push_back(Friends(6232, 6368));
        BestFriends.push_back(Friends(6368, 6232));
        BestFriends.push_back(Friends(10744, 10856));
        BestFriends.push_back(Friends(10856, 10744));
        BestFriends.push_back(Friends(12285, 14595));
        BestFriends.push_back(Friends(14595, 12285));
        BestFriends.push_back(Friends(17296, 18416));
        BestFriends.push_back(Friends(18416, 17296));
    }

public:
    GoodFriends()
    {
        // cout << getFactorSum(220) << " " << getFactorSum(284) << endl;
        init();
    }

    /* 找呀找呀找朋友 */
    pair<ll, ll> find(ll Base)
    {
        vector<Friends>::iterator it = lower_bound(BestFriends.begin(),
                                                   BestFriends.end(), Friends(Base));

        return make_pair(it->first, it->second);
    }
};

int main()
{
    GoodFriends gf;

    ll base;
    cin >> base;

    pair<ll, ll> friends = gf.find(base);
    cout << friends.first << " " << friends.second;

    return 0;
}

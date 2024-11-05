/*****************************************************************
 * 题目：[语言月赛202303] Coin Selection G
 * 描述：按照情况拿走硬币，问最后每个人拿了多少？
 * 思路：模拟。
 * 对象：CoinGame模拟硬币游戏。
 * 注意：注意数据范围，可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define ll long long                              // 定义长整型

class CoinGame
{
private:
public:
    /* 输入玩家人数和硬币数组，输出每个玩家的最终硬币数。 */
    vector<ll> StartGame(int PlayerNum, vector<ll> Coins)
    {
        sort(Coins.begin(), Coins.end());
        vector<ll> Players(PlayerNum, 0);

        int player_idx = 0;
        while (Coins.size() != 0)
        {
            auto it = upper_bound(Coins.begin(), Coins.end(), Players[player_idx]);

            if (it != Coins.begin())
            {
                it--;
            }
            Players[player_idx] += *it;

            Coins.erase(it);
            player_idx = (player_idx + 1) % PlayerNum;
        }

        return Players;
    }
};

int main()
{
    CoinGame cg;
    const int player_num = 2;
    int coin_num;

    cin >> coin_num;
    vector<ll> coins(coin_num);
    rep(i, 0, coin_num - 1)
    {
        cin >> coins[i];
    }

    auto res = cg.StartGame(player_num, coins);
    for (auto r : res)
    {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}
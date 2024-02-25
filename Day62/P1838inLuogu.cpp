/***********************************************
 * 题目：三子棋I
 * 描述：输入双方下的位置，返回最后的赢家。
 * 思路：拆成两位玩家进行分析。
 * 对象：ThreeALine模拟三子棋。
 * 注意：考虑所有赢的情况。
 ***********************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 模拟快速循环
#define EMPTY 0                                   // 无棋子
#define NOTEMPTY 1                                // 有棋子

class ThreeALine
{
private:
    map<int, bitset<1>> Player1; // 小A的棋
    map<int, bitset<1>> Player2; // Uim的棋

    /* 将下棋的过程拆分成两个玩家 */
    void SpilitGame(string Game)
    {
        /* player1先下 */
        int GameSize = Game.size();

        rep(i, 0, GameSize - 1)
        {
            assert(Game[i] >= '0' && Game[i] <= '9');
            if (i % 2 == 0)
            {
                Player1[Game[i] - '0'] = NOTEMPTY;
            }
            else
            {
                Player2[Game[i] - '0'] = NOTEMPTY;
            }
        }
    }

    /* 判断一个玩家有没有赢 */
    bool JudgeWin(map<int, bitset<1>> Player)
    {
        if (Player[1] == NOTEMPTY && Player[5] == NOTEMPTY &&
            Player[9] == NOTEMPTY)
        {
            return true;
        }

        if (Player[3] == NOTEMPTY && Player[5] == NOTEMPTY &&
            Player[7] == NOTEMPTY)
        {
            return true;
        }

        if (Player[1] == NOTEMPTY && Player[2] == NOTEMPTY &&
            Player[3] == NOTEMPTY)
        {
            return true;
        }

        if (Player[4] == NOTEMPTY && Player[5] == NOTEMPTY &&
            Player[6] == NOTEMPTY)
        {
            return true;
        }

        if (Player[7] == NOTEMPTY && Player[8] == NOTEMPTY &&
            Player[9] == NOTEMPTY)
        {
            return true;
        }

        if (Player[1] == NOTEMPTY && Player[4] == NOTEMPTY &&
            Player[7] == NOTEMPTY)
        {
            return true;
        }

        if (Player[2] == NOTEMPTY && Player[5] == NOTEMPTY &&
            Player[8] == NOTEMPTY)
        {
            return true;
        }

        if (Player[3] == NOTEMPTY && Player[6] == NOTEMPTY &&
            Player[9] == NOTEMPTY)
        {
            return true;
        }

        return false;
    }

public:
    /* 初始化，输入游戏下棋情况。 */
    ThreeALine(string game)
    {
        SpilitGame(game);
    }

    /* 输出胜负情况。 */
    void printWinInfo()
    {
        bool Player1Win = JudgeWin(Player1);
        bool Player2Win = JudgeWin(Player2);

        if (Player1Win && !Player2Win)
        {
            cout << "xiaoa wins." << endl;
        }
        else if (Player2Win && !Player1Win)
        {
            cout << "uim wins." << endl;
        }
        else if (!Player1Win && !Player2Win)
        {
            cout << "drew." << endl;
        }
        else
        {
            cout << "Cannot happen." << endl;
        }
    }
};

int main()
{
    string game;

    cin >> game;

    ThreeALine tal(game);
    tal.printWinInfo();

    return 0;
}
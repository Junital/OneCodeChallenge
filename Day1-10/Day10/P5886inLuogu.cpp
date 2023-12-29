/************************************************************
 * 题目：Hello, 2020!
 * 要求：n个出题人，m个选手，有p个出题人的预测第一名是对的，根据出题人各自的预测来判断谁是第一名。
 * 作者：Junital
 * 思路：进行统计，如果预测正确数和这位选手被预测的个数对的上，那么他就有可能获得第一名。
 * 函数：FindWinner找到黑马选手。
 ***********************************************************/

#include <bits/stdc++.h>
using namespace std;

#define MAXPLAYERNUM 1000006                      // 最多选手的个数
#define rep(i, s, k) for (int i = s; i <= k; i++) // 简便循环

int players[MAXPLAYERNUM] = {0}; // 表示每位选手被评委预测的个数

/* 输入出题人个数，玩家个数，预测正确的个数，打印输出黑马选手个数已经各自的编号 */
void FindWinner(int judges_num, int player_num, int correct_pred_num)
{
    rep(i, 1, judges_num)
    {
        int pred_num; // 预测个数
        cin >> pred_num;
        rep(j, 1, pred_num)
        {
            int pred_player_id; // 预测的选手编号
            cin >> pred_player_id;
            players[pred_player_id]++; // 对应选手被预测的个数加一
        }
    }

    vector<int> winners; // 存储所有的黑马
    rep(i, 1, player_num)
    {
        if (players[i] == correct_pred_num) // 如果被预测的个数刚好和正确预测的个数相匹配
        {
            winners.push_back(i);
        }
    }

    int winner_num = winners.size(); // 黑马的个数
    cout << winner_num << endl;
    rep(i, 0, winner_num - 1)
    {
        cout << winners[i] << " ";
    }
    cout << endl;
}

int main()
{
    int judges_num;       // 出题人个数
    int player_num;       // 选手个数
    int correct_pred_num; // 预测正确的个数

    cin >> judges_num >> player_num >> correct_pred_num;
    FindWinner(judges_num, player_num, correct_pred_num); // 寻找黑马选手
    return 0;
}
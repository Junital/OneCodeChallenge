/*****************************************************************
 * 题目：[USACO22JAN] Herdle B
 * 描述：Herdle解谜，两个矩阵比较，如果有位置相同的元素就绿色标记；
        如果位置不同，元素相同，就黄色标记。
 * 思路：集合判断 + 位置判断。
 * 对象：Herdle模拟该游戏。
 * 注意：看看怎么封装好一些。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class Herdle
{
private:
    vector<vector<char>> GroundTruth;

    /* 处理操作，统计矩阵中的元素。 */
    map<char, int> count_element(vector<vector<char>> matrix)
    {
        map<char, int> elements;
        for (auto arr : matrix)
        {
            for (auto e : arr)
            {
                elements[e]++;
            }
        }

        return elements;
    }

public:
    /* 初始化，输入答案。 */
    Herdle(vector<vector<char>> gt) : GroundTruth(gt)
    {
    }

    /* 输入猜测的答案。 */
    pair<int, int> judge(vector<vector<char>> Guess)
    {
        assert(Guess.size() == GroundTruth.size());
        int rown = Guess.size();
        int green = 0, yellow = 0;

        map<char, int> GT_elements = count_element(GroundTruth);
        map<char, int> guess_elements = count_element(Guess);

        rep(i, 0, rown - 1)
        {
            assert(Guess[i].size() == GroundTruth[i].size());

            int coln = Guess[i].size();

            rep(j, 0, coln - 1)
            {
                if (Guess[i][j] == GroundTruth[i][j])
                {
                    green++;
                    GT_elements[Guess[i][j]]--;
                    guess_elements[Guess[i][j]]--;
                }
            }
        }

        for (auto pii : guess_elements)
        {
            if (GT_elements[pii.first] > 0)
            {
                yellow += min(pii.second, GT_elements[pii.first]);
            }
        }

        return make_pair(green, yellow);
    }
};

int main()
{
    const int size = 3;
    vector<vector<char>> gt(size), guess(size);
    rep(i, 0, size - 1)
    {
        gt[i].resize(size);
        rep(j, 0, size - 1)
        {
            cin >> gt[i][j];
        }
    }

    Herdle H(gt);

    rep(i, 0, size - 1)
    {
        guess[i].resize(size);
        rep(j, 0, size - 1)
        {
            cin >> guess[i][j];
        }
    }
    auto res = H.judge(guess);
    cout << res.first << endl;
    cout << res.second << endl;
    return 0;
}
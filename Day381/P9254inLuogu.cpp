/*****************************************************************
 * 题目：[PA 2022] Liczenie punktów
 * 描述：答题，将字符串分成n份，每次要全部答对才算分。
 * 思路：任务特殊，另外制作对象。
 * 对象：CodeTest模拟代码测试。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class CodeTest
{
private:
    const char CORRECT = 'T';
    const char WRONG = 'N';
    const int ProblemNum = 10;

    vector<string> split_string(string str)
    {
        vector<string> res;

        int strlen = str.size();
        assert(strlen % ProblemNum == 0);

        int test_point = strlen / ProblemNum;
        rep(i, 0, ProblemNum - 1)
        {
            res.push_back(str.substr(i * test_point, test_point));
        }

        return res;
    }

    bool judge_pass(string str)
    {
        for (auto ch : str)
        {
            assert(ch == CORRECT || ch == WRONG);
            if (ch == WRONG)
            {
                return false;
            }
        }
        return true;
    }

public:
    CodeTest() {}

    int query(string str)
    {
        for (auto ch : str)
        {
            assert(ch == CORRECT || ch == WRONG);
        }

        auto splits = split_string(str);

        int count = 0;
        for (auto s : splits)
        {
            if (judge_pass(s))
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{
    CodeTest ct;

    string str;

    int num;
    cin >> num;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, str);

    cout << ct.query(str) << endl;
    return 0;
}
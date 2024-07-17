/**********************************************************
 * 题目：[COCI2010-2011#3] ZBROJ
 * 描述：数字5、6可能混淆，要求为两个数字相加提供范围。
 * 思路：为了封装好一些，我觉得可以就把数字的范围提供出来
        然后将最大的相加。
 * 对象：AbstractNum模拟模糊的数字。
 * 注意：需要注意前缀0这种情况。
 **********************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class AbstractNum
{
private:
    set<int> ConfusNums; // 混淆的数字

public:
    /* 初始化，输入容易混淆的数字。 */
    AbstractNum(set<int> nums) : ConfusNums(nums)
    {
        // cout << "construct" << endl;
        for (auto i : ConfusNums)
        {
            assert(i < 10 && i >= 0);
        }
    }

    /* 输入一个数字，输出这个数字可能出现的情况。 */
    vector<int> Confuse(int Num)
    {
        set<string> PossibleAns;
        string Num_string = to_string(Num);

        int NumLen = Num_string.length();

        PossibleAns.insert(Num_string);
        rep(i, 0, NumLen - 1)
        {
            char ch = Num_string[i];
            /* 对每个数进行置换 */
            if (ConfusNums.count((int)(ch - '0')) > 0)
            {
                for (auto num : PossibleAns)
                {
                    for (auto digit : ConfusNums)
                    {
                        string NumTmp(num);
                        NumTmp[i] = digit + '0';
                        // cout << NumTmp << endl;
                        PossibleAns.insert(NumTmp);
                    }
                }
            }
        }

        vector<int> Ans;
        for (auto pa : PossibleAns)
        {
            Ans.push_back(stoi(pa));
        }
        return Ans;
    }
};

int main()
{
    set<int> confusnums;
    confusnums.insert(5);
    confusnums.insert(6);
    AbstractNum AN(confusnums);

    int NumA, NumB;
    cin >> NumA >> NumB;

    vector<int> PossibleA = AN.Confuse(NumA);
    vector<int> PossibleB = AN.Confuse(NumB);

    assert(PossibleA.size() > 0);
    assert(PossibleB.size() > 0);
    auto MinA = min_element(PossibleA.begin(), PossibleA.end());
    auto MinB = min_element(PossibleB.begin(), PossibleB.end());
    auto MaxA = max_element(PossibleA.begin(), PossibleA.end());
    auto MaxB = max_element(PossibleB.begin(), PossibleB.end());

    cout << *MinA + *MinB << " " << *MaxA + *MaxB << endl;
    return 0;
}

/*****************************************************************
 * 题目：[HUSTFC 2023] 不定项选择题
 * 描述：需要点多少次才能遍历所有可能的答案。
 * 思路：幂次计算。
 * 对象：DefiniteAnswer模拟不定项答案。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class DefiniteAnswer
{
private:
public:
    /* 输入选项，输出最多的答案数量。 */
    int max_answer(int ChoiceNum)
    {
        return (1 << ChoiceNum) - 1;
    }
};

int main()
{
    DefiniteAnswer da;

    int choice_num;
    cin >> choice_num;

    cout << da.max_answer(choice_num) << endl;
    return 0;
}

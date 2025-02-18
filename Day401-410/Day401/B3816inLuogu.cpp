/*****************************************************************
 * 题目：[语言月赛 202308] 小粉兔的挂科与压力
 * 描述：根据公式计算压力值。
 * 思路：O(1)复杂度的遍历。
 * 对象：PressureValue模拟压力值。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class PressureValue
{
private:
    int Coefficient; // 压力系数

public:
    /* 初始化，输入压力系数。 */
    PressureValue(int coefficient) : Coefficient(coefficient) {}

    /* 输入科目，输出最小压力的科目数和压力值。 */
    pair<long long, long long> query(vector<int> exams)
    {
        int min_exam_num = 0;
        int exam_num = exams.size();
        long long min_value = (long long)Coefficient * exam_num;
        long long current_value = min_value;
        int max_difficulty = 0;

        for (int i = 1; i <= exam_num; i++)
        {
            current_value -= max_difficulty;
            max_difficulty = max(max_difficulty, exams[i - 1]);
            current_value += max_difficulty;
            current_value -= Coefficient;

            if (current_value < min_value)
            {
                min_value = current_value;
                min_exam_num = i;
            }
        }

        return make_pair(min_exam_num, min_value);
    }
};

int main()
{
    int size, coefficient;
    cin >> size >> coefficient;

    PressureValue pv(coefficient);

    vector<int> exams(size);
    for (int i = 0; i < size; i++)
    {
        cin >> exams[i];
    }

    auto res = pv.query(exams);
    cout << res.first << " " << res.second << endl;
    return 0;
}
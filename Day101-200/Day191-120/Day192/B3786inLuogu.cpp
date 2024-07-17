/*********************************************************
 * 题目：[信息与未来 2023] 幸运数字
 * 描述：判断数字的奇位偶位和是否相同。
 * 思路：逐个判断。
 * 对象：LuckyNumber模拟幸运数字。
 * 注意：注意时间限制。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

class LuckyNumber
{
private:
    const int DEC = 10;
    const int GROUPNUM = 2;

    bool judge_luck(int Num)
    {
        vector<int> Sum(GROUPNUM, 0);
        int sum_pointer = 0; // 指向第一个或第二个和

        while (Num >= DEC)
        {
            int digit = Num % DEC;
            Sum[sum_pointer] += digit;
            Num /= DEC;                    // 移位
            sum_pointer = 1 - sum_pointer; // 更新指针
        }

        Sum[sum_pointer] += Num;

        rep(i, 1, GROUPNUM - 1)
        {
            if (Sum[0] != Sum[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    /* 输入数据范围，输出幸运数字的个数。 */
    int lucky_count(int Begin, int End)
    {
        int Count = 0; // 计数器

        rep(i, Begin, End)
        {
            if (judge_luck(i))
            {
                Count += 1;
            }
        }

        return Count;
    }
};

int main()
{
    LuckyNumber ln;
    int begin, end;

    cin >> begin >> end;
    cout << ln.lucky_count(begin, end) << endl;
    return 0;
}

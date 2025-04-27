/*****************************************************************
 * 题目：[GESP202309 三级] 进制判断
 * 描述：判断字符串的最大进制。
 * 思路：封装一个进制转换器。
 * 对象：NumSysConverter模拟进制转换器。
 * 注意：输出后，还需要再判断。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace Tools
{
#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环
#define per(i, s, k) for (int i = s; i >= k; i--) // 定义逆向循环
#define ll long long                              // 定义长整型
#define ull unsigned long long                    // 定义无符号长整型
#define pii pair<int, int>                        // 定义pair
#define vi vector<int>                            // 定义vector
#define i64 int64_t                               // 定义int64
#define div_up(a, b) (a) / (b) + ((a) % (b) != 0) // 定义 上整除
    /* 四舍五入 */
    int Approximate(double Num)
    {
        double Ceil = ceil(Num);
        double Floor = floor(Num);

        if (Ceil - Num <= Num - Floor)
        {
            return (int)Ceil;
        }
        else
        {
            return (int)Floor;
        }
    }
};

using namespace Tools;

class NumSysConverter
{
private:
    /* 根据字符，转化为数字（十进制）。 */
    int char2number(char ch)
    {
        if (ch >= '0' && ch <= '9')
        {
            return ch - '0';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            return 10 + (ch - 'A');
        }
        else
        {
            throw invalid_argument("Input must be capital letters or numbers!");
        }
    }

public:
    /* 找到最小可能的进制。 */
    int min_possible_numsys(string str)
    {
        int max_num = 0;
        for (auto ch : str)
        {
            max_num = max(max_num, char2number(ch));
        }

        return max_num + 1;
    }
};

int main()
{
    const vector<int> num_sys = {2, 8, 10, 16};
    NumSysConverter nsc;

    int size;
    cin >> size;

    rep(i, 1, size)
    {
        string num;
        cin >> num;

        int min_possible = nsc.min_possible_numsys(num);
        int ans_size = num_sys.size();

        rep(i, 0, ans_size - 1)
        {
            if (num_sys[i] < min_possible)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
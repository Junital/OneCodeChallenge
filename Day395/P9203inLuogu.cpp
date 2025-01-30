/*****************************************************************
 * 题目：时效「月岩笠的诅咒」
 * 描述：判断两个高精度浮点数的小数部分是否一样。
 * 思路：模拟高精度浮点数。
 * 对象：无。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class BigFloat
{
private:
    std::string value; // 例如 "12345.6789"
    bool isNegative;   // 是否为负数

    bool judge(string val)
    {
        int size = val.size();
        if (size == 0)
        {
            throw invalid_argument("The string must have content.");
            return false;
        }

        int start_idx = 0;
        if (val[0] == '-')
        {
            start_idx++;
        }

        int dot_num = 0;
        for (int i = start_idx; i < size; i++)
        {
            if (val[i] >= '0' && val[i] <= '9')
            {
                continue;
            }
            else if (val[i] == '.')
            {
                dot_num++;
            }
            else
            {
                throw invalid_argument("Wrong character in the string.");
                return false;
            }
        }

        if (dot_num > 1)
        {
            throw invalid_argument("The dot num in a float number shouldn't more than 1.");
            return false;
        }
        return true;
    }

public:
    // 构造函数
    BigFloat(const std::string &val = "0")
    {
        if (!judge(val))
        {
            throw invalid_argument("Wrong string!");
        }

        if (val[0] == '-')
        {
            isNegative = true;
            value = val.substr(1);
        }
        else
        {
            isNegative = false;
            value = val;
        }
    }

    // 重载输出流
    friend std::ostream &operator<<(std::ostream &os, const BigFloat &num)
    {
        if (num.isNegative)
            os << "-";
        os << num.value;
        return os;
    }

    // 分割整数、小数部分
    pair<string, string> split_frac()
    {
        int idx = value.find('.');
        string dec, frac;
        if (idx >= 0)
        {
            frac = value.substr(idx + 1);
            dec = value.substr(0, idx);
        }
        else
        {
            frac = "";
            dec = value;
        }

        if (isNegative)
        {
            dec = "-" + dec;
        }

        frac.erase(frac.find_last_not_of('0') + 1);

        return make_pair(dec, frac);
    }
};

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    BigFloat bf1(str1), bf2(str2);

    auto A = bf1.split_frac();
    auto B = bf2.split_frac();
    if (A.second == B.second)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
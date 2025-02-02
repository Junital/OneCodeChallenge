/*****************************************************************
 * 题目：[NAPC-#1] Stage1 - Simple
 * 描述：将一个整数进行平分，平分成N个整数。
 * 思路：对类对象进行平分。
 * 对象：IntegerSplitter模拟整数平分。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class IntegerSplitter
{
private:
    T Total;

public:
    IntegerSplitter(T total) : Total(total)
    {
        if (total < 0)
        {
            throw std::invalid_argument("total 必须为非负整数");
        }
    }

    vector<T> split(T num_parts)
    {
        if (num_parts <= 0)
        {
            throw std::invalid_argument("num_parts 必须为正整数");
        }

        T quotient = Total / num_parts;
        T remainder = Total % num_parts;

        vector<T> result;
        result.reserve(num_parts); // 预分配内存
        result.insert(result.end(), remainder, quotient + 1);
        result.insert(result.end(), num_parts - remainder, quotient);

        return result;
    }
};

int main()
{
    long long total, limit, maxdis, num_parts;
    cin >> num_parts >> limit >> maxdis >> total;

    IntegerSplitter<long long> is(total);
    for (auto e : is.split(num_parts))
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
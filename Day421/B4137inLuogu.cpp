/*****************************************************************
 * 题目：[信息与未来 2016] 幸运数字
 * 描述：满足任意一个条件就算幸运数字。
 * 思路：遍历寻找。
 * 对象：NumberFilter模拟数字过滤器。
 * 注意：注意数据范围。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

class NumberFilter
{
private:
    function<bool(int)> predicate; // 存储判断条件的函数对象
public:
    // 默认构造函数，初始化为接受所有数字
    NumberFilter() : predicate([](int)
                               { return true; }) {}

    // 允许用户传入初始过滤条件的构造函数
    explicit NumberFilter(function<bool(int)> func) : predicate(move(func)) {}

    // 设置新的过滤条件
    void setFilter(function<bool(int)> func)
    {
        predicate = move(func);
    }

    // 过滤数字并返回符合条件的列表
    vector<int> filter(const vector<int> &numbers) const
    {
        vector<int> result;
        for (int num : numbers)
        {
            if (predicate(num))
            {
                result.push_back(num);
            }
        }
        return result;
    }

    // 过滤区间内的数字。
    vector<int> filter(int begin, int end)
    {
        vector<int> result;

        for (int i = begin; i <= end; i++)
        {
            if (predicate(i))
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

bool customed_filter(int number)
{

    if (number % 4 == 0)
    {
        return true;
    }
    if (number % 7 == 0)
    {
        return true;
    }

    //----------字符串部分-----------//
    const string A = "44";
    const string B = "77";

    string str = to_string(number);
    if (str.find(A) != -1)
    {
        return true;
    }
    if (str.find(B) != -1)
    {
        return true;
    }
    return false;
}

int main()
{
    NumberFilter nf([](int x)
                    { return customed_filter(x); });

    int end;
    cin >> end;

    cout << nf.filter(1, end).size() << endl;
    return 0;
}
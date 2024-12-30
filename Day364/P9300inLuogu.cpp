/*****************************************************************
 * 题目：[CCC 2023 J2] Chili Peppers
 * 描述：求解字符串到int的表格对应求和。
 * 思路：映射求和。
 * 对象：MapSum模拟映射求和。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename T>
class MapSum
{
private:
    map<T, int> ElementMap;

    bool all_digit_judge()
    {
        rep(i, 0, MAX_DIGIT)
        {
            auto it = ElementMap.find(i);
            if (it == ElementMap.end())
            {
                return false;
            }
        }

        return true;
    }

    const int MAX_DIGIT = 9;

public:
    /* 初始化，输入映射。 */
    MapSum(map<T, int> Map) : ElementMap(Map)
    {
        // assert(all_digit_judge());
    }

    /* 请求，输入元素，输出求和。 */
    int query(vector<T> elements)
    {
        int Sum = 0;

        for (auto e : elements)
        {
            Sum += ElementMap[e];
        }

        return Sum;
    }
};

int main()
{
    const map<string, int> sim = {
        {"Poblano", 1500},
        {"Mirasol", 6000},
        {"Serrano", 15500},
        {"Cayenne", 40000},
        {"Thai", 75000},
        {"Habanero", 125000}};

    MapSum<string> ms(sim);

    int size;
    cin >> size;

    vector<string> names(size);
    rep(i, 0, size - 1)
    {
        cin >> names[i];
    }

    cout << ms.query(names) << endl;
    return 0;
}
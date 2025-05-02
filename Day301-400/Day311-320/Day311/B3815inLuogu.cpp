/*****************************************************************
 * 题目：[语言月赛 202308] 小粉兔做麻辣兔头
 * 描述：求出一个骰子塔暴露在空气中的点数和。
 * 思路：了解骰子的结构。
 * 对象：DiceTower模拟骰子塔。
 * 注意：注意可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

/* 双向映射 */
template <typename Type>
class BiMap
{
private:
    std::unordered_map<Type, Type> forwardMap;
    std::unordered_map<Type, Type> reverseMap;

public:
    // 类型定义方便用户访问迭代器类型
    using iterator = typename std::unordered_map<Type, Type>::iterator;
    using const_iterator = typename std::unordered_map<Type, Type>::const_iterator;

    // 默认构造函数
    BiMap() = default;

    // 使用initializer_list构造函数
    BiMap(std::initializer_list<std::pair<const Type, Type>> initList)
    {
        for (const auto &pair : initList)
        {
            insert(pair.first, pair.second);
        }
    }

    void insert(Type key, const Type &value)
    {
        if (forwardMap.find(key) != forwardMap.end() || reverseMap.find(value) != reverseMap.end())
        {
            throw std::runtime_error("Duplicate key or value.");
        }
        forwardMap[key] = value;
        reverseMap[value] = key;
    }

    Type getAnother(Type key)
    {
        bool forward_find = true, reverse_find = true;

        if (forwardMap.find(key) == forwardMap.end())
        {
            forward_find = false;
        }

        if (reverseMap.find(key) == reverseMap.end())
        {
            reverse_find = false;
        }

        if (!forward_find && !reverse_find)
        {
            throw std::runtime_error("Key not found.");
        }

        if (forward_find)
        {
            return forwardMap[key];
        }

        if (reverse_find)
        {
            return reverseMap[key];
        }
    }

    void erase(const Type &key)
    {
        auto it = forwardMap.find(key);
        if (it != forwardMap.end())
        {
            reverseMap.erase(it->second);
            forwardMap.erase(it);
        }

        auto rev_it = reverseMap.find(key);
        if (rev_it != reverseMap.end())
        {
            forwardMap.erase(rev_it->second);
            reverseMap.erase(rev_it);
        }
    }

    // 迭代器相关方法
    iterator begin()
    {
        return forwardMap.begin();
    }

    iterator end()
    {
        return forwardMap.end();
    }

    const_iterator begin() const
    {
        return forwardMap.cbegin();
    }

    const_iterator end() const
    {
        return forwardMap.cend();
    }
};

class DiceTower
{
private:
    BiMap<int> OppositeSide;

public:
    DiceTower(BiMap<int> sides) : OppositeSide(sides) {}

    /* 计算可见点数。 */
    int visible_count(vector<int> TopSides)
    {
        int dice_num = TopSides.size();
        int count = 0;
        rep(i, 0, dice_num - 1)
        {
            for (auto doubleside : OppositeSide)
            {
                if (doubleside.first != TopSides[i] &&
                    doubleside.second != TopSides[i])
                {
                    count += doubleside.first;
                    count += doubleside.second;
                }
            }
        }

        count += TopSides[dice_num - 1];
        return count;
    }
};

int main()
{
    const BiMap<int> opposite_side = {{1, 2}, {3, 4}, {5, 6}};
    DiceTower dt(opposite_side);

    int dice_num;
    cin >> dice_num;

    vector<int> topsides(dice_num);
    rep(i, 0, dice_num - 1)
    {
        cin >> topsides[i];
    }

    cout << dt.visible_count(topsides) << endl;
    return 0;
}
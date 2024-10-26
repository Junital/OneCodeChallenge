/*********************************************************
 * 题目：[语言月赛 202308] 小粉兔还会忘记考试吗
 * 描述：统计小粉兔的是否都参加了所有考试。
 * 思路：统计集合中所有元素是否被访问。
 * 对象：Vector2Set将数组转变为集合；MapLimit用于设定阈值，获得map子集。
 * 注意：注意提高拓展性。
 *******************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

template <typename Container>
Container Intersection(const Container &A, const Container &B)
{
    Container result;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                     inserter(result, result.begin()));
    return result;
}

template <typename Type>
set<Type> vector2set(vector<Type> Arr)
{
    set<Type> Res(Arr.begin(), Arr.end());
    return Res;
}

template <typename Key, typename Value>
map<Key, Value> MapLimit(map<Key, Value> mymap, int limit)
{
    map<Key, Value> res;
    for (auto p : mymap)
    {
        if (p.second < limit)
        {
            res[p.first] = p.second;
        }
    }

    return res;
}

int main()
{
    const int PassLine = 60;

    int set_size, arr_size;
    vector<int> arr;
    set<int> myset;
    map<int, int> Scores;
    cin >> set_size >> arr_size;

    rep(i, 1, set_size)
    {
        int element;
        cin >> element;
        myset.insert(element);
    }

    rep(i, 1, arr_size)
    {
        int element, score;
        cin >> element >> score;

        arr.push_back(element);
        Scores[element] = score;
    }

    auto subset = Intersection(vector2set(arr), myset);
    cout << myset.size() - subset.size() << endl;
    cout << MapLimit(Scores, PassLine).size() + myset.size() - subset.size() << endl;
    return 0;
}

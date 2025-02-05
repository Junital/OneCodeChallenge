/*****************************************************************
 * 题目：[COCI2015-2016#1] AKCIJA
 * 描述：书店优惠活动，买三本书最便宜的书不要钱。
 * 思路：从大到小排序，看怎么最优惠。
 * 对象：BookShop模拟书店。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, k) for (int i = s; i <= k; i++) // 定义快速循环

namespace VectorExtensions
{
    /* 定义数组求和 */
    template <typename Type>
    Type ArrSum(vector<Type> &Arr)
    {
        Type Sum = 0;
        for (auto element : Arr)
        {
            Sum += element;
        }
        return Sum;
    }

    /* 某个索引后的最小值。 */
    template <typename Type>
    Type SubArrMin(vector<Type> &Arr, int Index)
    {
        int Size = Arr.size();
        assert(Index < Size);

        auto start = Arr.begin() + Index;
        return *(min_element(start, Arr.end()));
    }

    // 交换数组中两个元素
    template <typename Type>
    void swapElements(std::vector<Type> &arr, int index1, int index2)
    {
        if (index1 < 0 || index1 >= arr.size() || index2 < 0 || index2 >= arr.size())
        {
            std::cerr << "Error: Indices out of bounds." << std::endl;
            return;
        }

        // Swapping the elements
        Type temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }

    // 将数组视为最大堆，将最大元素退出。
    template <typename Type>
    Type pop_max(vector<Type> &arr)
    {
        pop_heap(arr.begin(), arr.end());
        Type res = arr.back();
        arr.pop_back();

        return res;
    }
}

class BookShop
{
private:
    const int Mod = 3;

public:
    /* 模拟购买，输出最小价格。 */
    int buy(vector<int> Prices)
    {
        sort(Prices.begin(), Prices.end(), greater<>());
        int ItemNum = Prices.size();
        int final_price = 0;
        int idx = 0;

        rep(i, 1, ItemNum / Mod)
        {
            final_price += Prices[idx++];
            final_price += Prices[idx++];
            idx++;
        }

        while (idx < ItemNum)
        {
            final_price += Prices[idx++];
        }

        return final_price;
    }
};

int main()
{
    int size;
    cin >> size;
    vector<int> prices(size);

    rep(i, 0, size - 1)
    {
        cin >> prices[i];
    }

    BookShop bs;

    cout << bs.buy(prices) << endl;
    return 0;
}
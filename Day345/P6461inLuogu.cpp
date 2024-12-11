/*****************************************************************
 * 题目：[COCI2006-2007#5] TRIK
 * 描述：三仙归洞，问最后球在哪个杯子下。
 * 思路：模拟。
 * 对象：ThreeCupGuess模拟三仙归洞。
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
}

class ThreeCupGuess
{
private:
    typedef void (*Func)(vector<bool> &);
    const int size = 3;

    vector<bool> Cups;

    static void op_A(vector<bool> &cups)
    {
        VectorExtensions::swapElements(cups, 0, 1);
    }

    static void op_B(vector<bool> &cups)
    {
        VectorExtensions::swapElements(cups, 1, 2);
    }

    static void op_C(vector<bool> &cups)
    {
        VectorExtensions::swapElements(cups, 0, 2);
    }

    const map<char, Func> OpMap = {{'A', &op_A},
                                   {'B', &op_B},
                                   {'C', &op_C}};

public:
    ThreeCupGuess(int index) : Cups(size, false)
    {
        assert(index > 0 && index <= size);
        Cups[index - 1] = true;
    }

    /* 输入一个字符串，开始游戏。 */
    int start(string Str)
    {
        vector<bool> game = Cups;
        for (auto ch : Str)
        {
            auto it = OpMap.find(ch);
            assert(it != OpMap.end());

            it->second(game);
        }

        return find(game.begin(), game.end(), true) -
               game.begin() + 1;
    }
};

int main()
{
    ThreeCupGuess tcg(1);
    string str;
    cin >> str;

    cout << tcg.start(str) << endl;
    return 0;
}
/*****************************************************************
 * 题目：[语言月赛202212] 旋转排列
 * 描述：有一个循环数组的排列，现在需要不断将最后一个元素放到第一个元素的位置，
        直到最后一个元素是1~n最大的那个元素。中间不断输出数组目前的顺序。
 * 思路：模拟循环操作。
 * 对象：CircularArray循环数组。
 * 注意：无。
 ****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

/**
 * 循环数组类
 */
class CircularArray
{
private:
    vector<int> array;
    int n;
    int index;
    int head;

public:
    CircularArray(const vector<int> &arr) : array(arr), n(arr.size()), index(0), head(0) {}

    void init()
    {
        index = 0;
    }

    void next()
    {
        index = (index + 1) % n;
    }

    int get()
    {
        return array[index];
    }

    int getByIdx(int idx)
    {
        return array[(head + idx) % n];
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            cout << getByIdx(i) << " ";
        }
        cout << endl;
    }

    void rotate()
    {
        head = (head - 1 + n) % n;
        index = head;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    CircularArray circularArray(a);
    circularArray.init();

    do
    {
        circularArray.rotate();
        circularArray.print();
    } while (circularArray.getByIdx(n - 1) != n);

    return 0;
}
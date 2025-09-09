/*****************************************************************
 * 题目：[CCC 2008 J2] Do the Shuffle
 * 描述：四种操作，1.第一个元素放到末尾；2.将最后一个元素放到第一个位置；
        3. 交换前两个元素；4. 停止之后的操作，输出结果。
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
template <typename T>
class CircularArray
{
private:
    vector<T> array;
    int n;
    int index;
    int head;

public:
    CircularArray(const vector<T> &arr) : array(arr), n(arr.size()), index(0), head(0) {}

    void init()
    {
        index = 0;
    }

    void next()
    {
        index = (index + 1) % n;
    }

    T get()
    {
        return array[index];
    }

    T getByIdx(int idx)
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

    void rotateBack()
    {
        head = (head + 1) % n;
        index = head;
    }

    void rotate()
    {
        head = (head - 1 + n) % n;
        index = head;
    }

    void swapFirst()
    {
        T temp = array[head];
        array[head] = array[(head + 1) % n];
        array[(head + 1) % n] = temp;
    }
};

int main()
{
    vector<char> arr = {'A', 'B', 'C', 'D', 'E'};
    CircularArray<char> circularArray(arr);

    int b, n; // b代表操作，n代表次数。
    while (cin >> b >> n)
    {
        if (b == 1)
        {
            for (int i = 0; i < n; i++)
            {
                circularArray.rotateBack();
                // circularArray.print();
            }
        }
        else if (b == 2)
        {
            for (int i = 0; i < n; i++)
            {
                circularArray.rotate();
                // circularArray.print();
            }
        }
        else if (b == 3)
        {
            for (int i = 0; i < n; i++)
            {
                circularArray.swapFirst();
                // circularArray.print();
            }
        }
        else if (b == 4)
        {
            circularArray.print();
            break;
        }
    }

    return 0;
}
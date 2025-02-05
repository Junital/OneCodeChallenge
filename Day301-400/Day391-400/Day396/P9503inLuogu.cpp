/*****************************************************************
 * 题目：『MGOI』Simple Round I | B. 魔法照相馆
 * 描述：照相的背景要求右侧的幕布全部要拉上去，问一套下来花了多少精力。
 * 思路：拓展二进制，并模拟。
 * 对象：BackdropManagement模拟管理幕布。
 * 注意：注意提高可拓展性。
 ****************************************************************/

#include <bits/stdc++.h>

using namespace std;

namespace BinaryWorld
{
    template <size_t Length>
    class Binary
    {
    private:
        std::bitset<Length> bits; // 用于存储二进制数的bitset

    public:
        // 默认构造函数（初始化为0）
        Binary() : bits(0) {}

        // 使用整数初始化
        explicit Binary(unsigned long long value)
        {
            if (value >= (1ULL << Length))
            {
                throw std::out_of_range("Value exceeds the length of the binary representation");
            }
            bits = std::bitset<Length>(value);
        }

        // 使用二进制字符串初始化
        explicit Binary(const std::string &binaryString)
        {
            if (binaryString.size() > Length)
            {
                throw std::invalid_argument("Binary string exceeds the specified length");
            }
            bits = std::bitset<Length>(binaryString);
        }

        explicit Binary(const char *binaryString)
        {
            std::string str(binaryString); // 将 const char* 转为 std::string
            if (str.size() > Length)
            {
                throw std::invalid_argument("Binary string exceeds the specified length");
            }
            bits = std::bitset<Length>(str);
        }

        // 获取位数长度
        constexpr size_t size() const
        {
            return Length;
        }

        // 设置二进制值（支持整数）
        void setValue(unsigned long long value)
        {
            if (value >= (1ULL << Length))
            {
                throw std::out_of_range("Value exceeds the length of the binary representation");
            }
            bits = std::bitset<Length>(value);
        }

        // 设置二进制值（支持二进制字符串）
        void setValue(const std::string &binaryString)
        {
            if (binaryString.size() > Length)
            {
                throw std::invalid_argument("Binary string exceeds the specified length");
            }
            bits = std::bitset<Length>(binaryString);
        }

        // 获取二进制表示的字符串
        std::string toString() const
        {
            return bits.to_string();
        }

        // 获取十进制值
        unsigned long long toDecimal() const
        {
            return bits.to_ullong();
        }

        // 按位操作示例（按位与）
        Binary<Length> operator&(const Binary<Length> &other) const
        {
            Binary<Length> result;
            result.bits = bits & other.bits;
            return result;
        }

        // 按位操作示例（按位或）
        Binary<Length> operator|(const Binary<Length> &other) const
        {
            Binary<Length> result;
            result.bits = bits | other.bits;
            return result;
        }

        // 确定目标是否能覆盖住
        bool canCover(const Binary<Length> &other) const
        {
            return (bits & other.bits) == other.bits;
        }

        // 统计不同的位数
        size_t count_different_bits(const Binary<Length> &other)
        {
            return (bits ^ other.bits).count();
        }
    };

    /* 构造前N个为1，后M个为0的二进制。 */
    unsigned long long construct_bitmask(unsigned long long N,
                                         unsigned long long M)
    {
        if (N == 0)
            return 0; // 处理N=0的边界情况
        return ((1ULL << N) - 1) << M;
    }
};

using namespace BinaryWorld;

#define ull unsigned long long

template <size_t Length>
class BackdropManagement
{
private:
    Binary<Length> bits;

public:
    /* 初始化，全设为1。 */
    BackdropManagement()
    {
        bits.setValue((1ULL << Length) - 1);
    }

    /* 输入索引序列，输出需要消耗多少体力。 */
    ull query(vector<ull> idx)
    {
        ull count = 0;
        Binary<Length> current = bits;
        for (auto i : idx)
        {
            /* 先与，保留前面、删掉后面。 */
            Binary<Length> change(construct_bitmask(Length - i, i));

            Binary<Length> new_bits = current & change;

            /* 再或，调整本位。 */
            change.setValue(1ULL << i);
            new_bits = new_bits | change;

            // cout << current.count_different_bits(new_bits) << endl;
            count += current.count_different_bits(new_bits);
            current = new_bits;
        }

        return count;
    }
};

int main()
{
    const int size = 3;
    const map<char, ull> color2idx = {{'W', 0}, {'B', 1}, {'R', 2}};

    int len;
    cin >> len;

    string str;
    cin >> str;

    vector<ull> idx;
    for (auto ch : str)
    {
        idx.push_back(color2idx.find(ch)->second);
    }

    BackdropManagement<size> bm;
    cout << bm.query(idx) << endl;

    return 0;
}

/*****************************************************************
 * 题目：[蓝桥杯 2023 国 Python A] 残缺的数字
 * 描述：如果有些灯坏了，问数字有多少种情况。
 * 思路：拓展二进制处理。
 * 空间：BinaryWorld模拟二进制处理。
 * 注意：注意数据范围。
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
    };
};

int main()
{

    using Binary8 = BinaryWorld::Binary<8>;

    std::vector<Binary8> Numbers = {
        Binary8("1111110"),
        Binary8("0110000"),
        Binary8("1101101"),
        Binary8("1111001"),
        Binary8("0110011"),
        Binary8("1011011"),
        Binary8("1011111"),
        Binary8("1110000"),
        Binary8("1111111"),
        Binary8("1111011")};

    vector<Binary8> Brokens = {
        Binary8("0000011"),
        Binary8("1001011"),
        Binary8("0000001"),
        Binary8("0100001"),
        Binary8("0101011"),
        Binary8("0110110"),
        Binary8("1111111"),
        Binary8("0010110"),
        Binary8("0101001"),
        Binary8("0010110"),
        Binary8("1011100"),
        Binary8("0100110"),
        Binary8("1010000"),
        Binary8("0010011"),
        Binary8("0001111"),
        Binary8("0101101"),
        Binary8("0110101"),
        Binary8("1101010")};

    unsigned long long ans = 1;
    for (auto bn : Brokens)
    {
        int num = 0;
        for (auto n : Numbers)
        {
            if (n.canCover(bn))
            {
                num++;
            }
        }
        ans *= num;
    }

    cout << ans << endl;
    return 0;
}
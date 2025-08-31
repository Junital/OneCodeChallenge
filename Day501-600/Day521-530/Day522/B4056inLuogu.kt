/*****************************************************************
 * 题目：[语言月赛 202411] 卡牌
 * 描述：每次选择自己能买得起的最大卡牌。
 * 思路：搜索，每次找到刚好能买的起的卡牌。
 * 对象：BuyCards模拟买卡片。
 * 注意：时间很紧迫。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

// 全局工具
private val reader = BufferedReader(InputStreamReader(System.`in`))
private var tokenizer = StringTokenizer("")

// 不断从 reader 读取行，然后往 tokenizer 塞
private fun next(): String {
    while (!tokenizer.hasMoreTokens()) {
        tokenizer = StringTokenizer(reader.readLine() ?: "")
    }
    return tokenizer.nextToken()
}

// 读取一个 Int
private fun nextInt(): Int = next().toInt()

// 读取一个 Long
private fun nextLong(): Long = next().toLong()

// 读取一个 Double
private fun nextDouble(): Double = next().toDouble()

// 读取一个 Char
private fun nextChar(): Char = next().first()

/**
 * 把 Pair<A,B> 转成 "$first<sep>$second" 的字符串
 */
fun <A, B> Pair<A, B>.joinToString(
    separator: CharSequence = ", "
): String = listOf(first, second)
    .joinToString(separator) { it.toString() }

/**
 * 返回第一个大于 value 的位置（若都 ≤ value 则返回 size）。
 */
fun <T : Comparable<T>> List<T>.upperBound(value: T): Int {
    // binarySearch 找到 value 时返回某个 idx；找不到时返回 insertionPoint = -idx-1
    val idx = this.binarySearch(value)
    return if (idx >= 0) {
        // 如果正好命中一个 value，还要往右跳过所有相等的元素
        var i = idx + 1
        while (i < size && this[i] == value) i++
        i
    } else {
        // 如果没命中，-idx-1 本身就是第一个 > value 的插入点
        -idx - 1
    }
}

class BuyCards(val cardNum: Int, val packNum: Int){
    
    val cards = MutableList<MutableList<Int>>(packNum) { MutableList<Int>(cardNum) { nextInt() } }

    fun buy(money: Int){
        var left = money
        val record = MutableList<Int>(cardNum) {0}

        for(i in 1..packNum){
            cards[i - 1].sort()
            val idx = cards[i - 1].upperBound(left) - 1

            if(idx >= 0){
                val consume = cards[i - 1][idx]
                left -= consume
                record[consume - 1]++
            }
        }

        println(record.joinToString(" "))
        println(left)
    }
}

fun main(args: Array<String>) {
    val cardNum = 5
    val money = nextInt()
    val packNum = nextInt()

    val bc = BuyCards(cardNum, packNum)
    bc.buy(money)
}
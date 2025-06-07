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

class BuyCards(val cardNum: Int, val packNum: Int){
    
    val cards = MutableList<MutableList<Int>>(packNum) { MutableList<Int>(cardNum) { nextInt() } }

    fun buy(money: Int){
        var left = money
        val record = MutableList<Int>(cardNum) {0}

        for(i in 1..packNum){
            val consume = cards[i - 1].filter { it <= left }.maxOrNull() ?: 0
            left -= consume

            if(consume != 0){
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
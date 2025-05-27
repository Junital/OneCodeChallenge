/*****************************************************************
 * 题目：药房管理
 * 描述：有一定余量，不断对其请求。问最后请求失败的个数。
 * 思路：模拟。
 * 对象：ConsumableValue模拟可消耗值。
 * 注意：提高可拓展性。
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
 * 可消耗的整型值：每次消耗后剩余量递减，消耗失败（不够用）返回 false。
 */
class ConsumableInt(var remaining: Int) {
    init {
        require(remaining >= 0) { "Initial remaining must be >= 0, but was $remaining" }
    }

    /**
     * 尝试消耗 [amount]，如果剩余 >= amount，则扣减并返回 true，否则不变并返回 false。
     */
    fun consume(amount: Int): Boolean {
        require(amount >= 0) { "Amount to consume must be >= 0, but was $amount" }
        return if (remaining >= amount) {
            remaining -= amount
            true
        } else {
            false
        }
    }

    /**
     * 批量消耗：依次尝试对 list 中的每个元素调用 consume，
     * 并返回成功消耗的个数。
     */
    fun consumeAll(list: Iterable<Int>): Int =
        list.count { consume(it) }
}

fun main(args: Array<String>) {
    val cint = ConsumableInt(nextInt())
    val query_len = nextInt()
    val query_list = List<Int>(query_len) { nextInt() }

    println(query_len - cint.consumeAll(query_list))
}
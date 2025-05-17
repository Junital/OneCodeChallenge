/*****************************************************************
 * 题目：digit 函数
 * 描述：输出数字从右往左数的第k个数字。
 * 思路：先切分为数字，然后从右往左索引。
 * 函数：toDigitList模拟切分数字字符列表。
 * 注意：索引的准确性。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.absoluteValue

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

/**
 * 把 Pair<A,B> 转成 "$first<sep>$second" 的字符串
 */
fun <A, B> Pair<A, B>.joinToString(
    separator: CharSequence = ", "
): String = listOf(first, second)
    .joinToString(separator) { it.toString() }

/**
 * 将整型拆成数字字符数组。
 */
fun Int.toDigitList(): List<Int> =
    this.absoluteValue.toString().map { it - '0' }

/**
 * 构造List索引函数。
 */
operator fun <T> List<T>.get(idx: Int, fromRight: Boolean = false): T {
    return if (!fromRight) this[idx]
           else this[this.lastIndex - idx]
}

fun main(args: Array<String>)
{
    val N = nextInt()
    val idx = nextInt()

    val digits = N.toDigitList()
    println(digits.get(idx - 1, fromRight=true))
}
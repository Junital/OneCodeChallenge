/*****************************************************************
 * 题目：[蓝桥杯 2023 国 Python A/Java A] 整数变换
 * 描述：数字减去各位之和，问几次变0。
 * 思路：模拟。
 * 函数：getDigitSum代表获取位数之和。
 * 注意：无。
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
 * 批量读取 n 个 Int，返回 List<Int>
 * 可以和解构声明一起使用：
 * val (x,y,z,w) = nextInts(4)
 */
fun nextInts(n: Int): List<Int> = List(n) { nextInt() }

// 读取一个 Long
private fun nextLong(): Long = next().toLong()

/**
 * 批量读取 n 个 Long，返回 List<Long>
 * 可以和解构声明一起使用：
 * val (x,y,z,w) = nextLongs(4)
 */
fun nextLongs(n: Int): List<Long> = List(n) { nextLong() }

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
 * 将整型拆成数字字符数组。
 */
fun Int.toDigitList(): List<Int> =
    this.absoluteValue.toString().map { it - '0' }

/**
 * 获取整形各位之和。
 */
fun Int.getDigitSum(): Int =
    this.toDigitList().sum()

fun main(args: Array<String>) {
    var num = nextInt()
    var cnt = 0

    while (num != 0) {
        num = num - num.getDigitSum()
        cnt++
    }

    println(cnt)
}
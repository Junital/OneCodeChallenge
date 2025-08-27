/*****************************************************************
 * 题目：「Daily OI Round 4」Analysis
 * 描述：将一个字符串，转变为全是大写字母需要的最少操作次数。
 * 思路：找到最近邻的大写字母，计算距离，取最小值。
 * 函数：minOperationsToAllUpperCase模拟。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.EOFException
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

/**
 * 批量读取 n 个 String，返回 List<String>
 * 可以和解构声明一起使用：
 * val (x,y,z,w) = nextStrings(4)
 */
fun nextStrings(n: Int): List<String> = List(n) { next() }

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

// 读取n个Double
fun nextDoubles(n: Int): List<Double> = List(n) { nextDouble() }

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
 * 名称：minOperationsToAllUpperCase
 * 输入：一个字符串
 * 输出：将这个字符串转变为全是大写字母需要的最少操作次数。
 */
fun minOperationsToAllUpperCase(s: String): Int {
    var operations = 0
    for (c in s) {
        // 找到ASCII表上最近的大写字母，计算距离
        if(!c.isUpperCase()){
            val upperCaseIndex = if (c < 'A') 'A' else 'Z'
            operations += (upperCaseIndex - c).absoluteValue
        }
    }
    return operations
}

fun main(args: Array<String>) {
    val s = next()
    println(minOperationsToAllUpperCase(s))

}
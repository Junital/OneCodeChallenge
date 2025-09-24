/*****************************************************************
 * 题目：[USACO20FEB] Mad Scientist B
 * 描述：每次可以操作一个子串，将其翻转，看变成另一个字符串最少需要几步，
 * 思路：统计连续不同的个数即可。
 * 函数：findConsecutiveDiff模拟。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.EOFException
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
 * 找到 s1 中，相比 s2 连续不同的子串的个数
 */
fun findConsecutiveDiff(s1: String, s2: String): Int {
    var i = 0
    var count = 0
    while (i < s1.length) {
        if (s1[i] != s2[i]) {
            count++
            while (i < s1.length && s1[i] != s2[i]) {
                i++
            }
        }
        i++
    }
    return count
}


fun main(args: Array<String>) {
    val size = nextInt()
    val s1 = next()
    val s2 = next()
    val diff = findConsecutiveDiff(s1, s2)
    println(diff)

}
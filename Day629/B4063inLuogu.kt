/*****************************************************************
 * 题目：[GESP202412 一级] 奇数和偶数
 * 描述：给定n个数，问其中有多少个奇数和偶数
 * 思路：遍历每个数，判断是否为奇数或偶数，分别统计个数
 * 函数：statsEvenOdd模拟统计奇偶。
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
 * 统计一个 Int 列表中奇数和偶数的个数
 */
fun statsEvenOdd(nums: List<Int>): Pair<Int, Int> {
    var evenCount = 0
    var oddCount = 0
    for (num in nums) {
        if (num % 2 == 0) {
            evenCount++
        } else {
            oddCount++
        }
    }
    return evenCount to oddCount
}


fun main(args: Array<String>) {
    val n = nextInt()
    val nums = nextInts(n)
    val (evenCount, oddCount) = statsEvenOdd(nums)
    println("${oddCount} ${evenCount}")

}
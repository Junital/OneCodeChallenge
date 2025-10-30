/*****************************************************************
 * 题目：[COCI 2018/2019 #3] Pismo
 * 描述：求一个数组中，任意两个数之差的最小值。
 * 思路：遍历。
 * 函数：minPairDiff模拟数组相邻两数最小差。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.EOFException
import java.util.StringTokenizer
import kotlin.math.abs

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
 * 求一个数组中，相邻两个数之差的最小值。
 */
fun minPairDiff(arr: List<Int>): Int {
    var minDiff = Int.MAX_VALUE
    for (i in 0 until arr.size - 1) {
        minDiff = minOf(minDiff, abs(arr[i] - arr[i + 1]))
    }
    return minDiff
}

fun main(args: Array<String>) {
    val n = nextInt()
    
    // 流式输入
    var last = nextInt()
    var minDiff = Int.MAX_VALUE
    // val arr = nextInts(n)
    for (i in 0 until n - 1) {
        val cur = nextInt()
        minDiff = minOf(minDiff, abs(last - cur))
        last = cur
    }

    println(minDiff)
}
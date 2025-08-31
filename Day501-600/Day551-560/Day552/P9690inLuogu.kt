/*****************************************************************
 * 题目：[GDCPC 2023] Programming Contest
 * 描述：已知开始年份和停办的若干年份，问今年是第几次举办。
 * 思路：upperbound。
 * 函数：upperbound模拟二分搜索。
 * 注意：无。
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

fun main(args: Array<String>) {
    val query = nextInt()

    repeat(query){
        val startYear = nextInt()
        val stopYearNum = nextInt()
        val stopYears = List<Int>(stopYearNum) { nextInt() }

        val queryYear = nextInt()

        println(queryYear - startYear - stopYears.upperBound(queryYear) + 1)
    }
}
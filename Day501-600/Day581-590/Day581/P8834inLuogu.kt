/*****************************************************************
 * 题目：[传智杯 #3 决赛] 序列
 * 描述：给一个数组和一个阈值k，问有多少对元素，满足相乘小于等于k？
 * 思路：可以先排序，之后遍历寻找。
 * 函数：findPairsWithProductLessThanK模拟寻找满足条件的对。
 * 注意：有可能会溢出。
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
 * 寻找满足条件的对
 */
fun findPairsWithProductLessThanK(arr: List<Int>, k: Int): Int {
    val sortedArr = arr.sorted()
    var count = 0
    for (i in sortedArr.indices) {
        // 内层循环从 i+1 开始，避免重复计算同一对
        for (j in i + 1 until sortedArr.size) {
            // 转换为 Long 避免 Int 相乘溢出
            if (sortedArr[i].toLong() * sortedArr[j] <= k) {
                count++
            } else {
                // 排序后，j 增大时乘积必然增大，直接退出内层循环
                break
            }
        }
    }
    return count
}


fun main(args: Array<String>) {
    val (n, k) = nextInts(2)
    val arr = nextInts(n)
    println(findPairsWithProductLessThanK(arr, k))

}
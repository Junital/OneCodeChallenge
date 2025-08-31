/*****************************************************************
 * 题目：[语言月赛202208] 俊俏地鼠的远亲
 * 描述：知道一个二维数组，求每个元素到相同元素的最远距离。
 * 思路：做一个映射，记录元素对应的所有坐标，然后快速计算最远距离。
 * 函数：maxDistanseWithSameElement模拟。
 * 注意：元素类型为Long。
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
 * 计算二维数组中每个元素到相同元素的最远距离。
 */
fun maxDistanseWithSameElement(
    n: Int,
    m: Int,
    a: List<List<Long>>
): List<List<Int>> {
    val map = mutableMapOf<Long, MutableList<Pair<Int, Int>>>()
    for (i in 0 until n) {
        for (j in 0 until m) {
            map.getOrPut(a[i][j]) { mutableListOf() }.add(i to j)
        }
    }

    val ans = List(n) { MutableList(m) { 0 } }
    for (i in 0 until n) {
        for (j in 0 until m) {
            val list = map[a[i][j]] ?: continue
            var min = Int.MIN_VALUE
            for (p in list) {
                // 要算距离的平方
                min = maxOf(min, (i - p.first) * (i - p.first) + (j - p.second) * (j - p.second))
            }
            ans[i][j] = min
        }
    }
    return ans
}


fun main(args: Array<String>) {
    val (n, m) = nextInts(2)
    val a = List(n) { nextLongs(m) }
    val ans = maxDistanseWithSameElement(n, m, a)
    for (i in 0 until n) {
        for (j in 0 until m) {
            print("${ans[i][j]} ")
        }
        println()
    }
}
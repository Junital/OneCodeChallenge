/*****************************************************************
 * 题目：[JOI2025 预选赛 R1H1] 铜锣烧
 * 描述：按照(a_i + b_j) \times max(a_i, b_j)公式计算铜锣烧的美味值之和。
 * 思路：根据公式计算即可。
 * 函数：dorayakiDeliciousness模拟铜锣烧美味值之和。
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
 * 模拟铜锣烧美味值之和。
 * @param a 第一个数组。
 * @param b 第二个数组。
 * @return 铜锣烧美味值之和。
 */

fun dorayakiDeliciousness(a: List<Int>, b: List<Int>): Long {
    var ans = 0L
    for (i in a.indices) {
        for (j in b.indices) {
            ans += (a[i] + b[j]) * maxOf(a[i], b[j])
        }
    }
    return ans
}

fun main(args: Array<String>) {
    val (n, m) = nextInts(2)
    val a = nextInts(n)
    val b = nextInts(m)
    println(dorayakiDeliciousness(a, b))
}
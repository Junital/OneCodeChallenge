/*****************************************************************
 * 题目：[GESP202312 二级] 小杨做题
 * 描述：第一天做a道题，第二天做b道题，之后每天做的题数是前两天的和，如果某一天做的题超过了m，之后就不去做了，问第N天一共做了多少题？
 * 思路：模拟。
 * 函数：
 * 注意：
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
 * limitedFibonacciSum
 * 计算斐波那契数列的第n项，但是只计算到第m项，超过m项的部分都返回0
 * 输入：a,b,m,n
 * 输出：前n项的和。
 */
fun limitedFibonacciSum(a: Long, b: Long, m: Int, n: Int): Long {
    if (n == 1) return a
    if (n == 2) return b
    var sum = a + b
    var a1 = a
    var b1 = b
    for (i in 3..n) {
        val c = a1 + b1
        sum += c
        a1 = b1
        b1 = c
        if (c >= m) break
    }
    return sum
}


fun main(args: Array<String>) {
    val (a, b) = nextLongs(2)
    val (m, n) = nextInts(2)

    println(limitedFibonacciSum(a, b, m, n))
}
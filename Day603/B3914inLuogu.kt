/*****************************************************************
 * 题目：[语言月赛 202401] 分饼干 I
 * 描述：有三包饼干，要分给两个人，不可以拆包，要尽可能平均，从大到小输出。
 * 思路：穷举所有情况，取最优解。
 * 函数：shareCookies模拟分饼干。
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
 * 分饼干
 * @param a, b, c 饼干大小
 * @return 分好的饼干大小

 */
fun shareCookies(a: Int, b: Int, c: Int): Pair<Int, Int> {
    var minDiff = Int.MAX_VALUE
    var ans = Pair(0, 0)


    // (a + b) vs c 
    var diff = (a + b) - c
    if (diff < minDiff) {
        minDiff = diff
        ans = Pair(a + b, c)
    }

    // (a + c) vs b
    diff = (a + c) - b
    if (diff < minDiff) {
        minDiff = diff
        ans = Pair(a + c, b)
    }


    // (b + c) vs a
    diff = (b + c) - a
    if (diff < minDiff) {
        minDiff = diff
        ans = Pair(b + c, a)
    }

    if(ans.first < ans.second) {
        return Pair(ans.second, ans.first)
    }

    return ans
}

fun main(args: Array<String>) {
    val (a, b, c) = nextInts(3)
    val (x, y) = shareCookies(a, b, c)
    println("$x $y")
}
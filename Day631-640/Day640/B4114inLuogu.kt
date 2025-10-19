/*****************************************************************
 * 题目：JOI2025 预选赛 R1H2 猜拳
 * 描述：R代表石头，P代表布，S代表剪刀，根据两个字符串，判断胜、负、平的个数。
 * 思路：直接判断每个位置上的字符，根据规则判断胜、负、平的个数。
 * 函数：strRockPaperScissors模拟字符串石头剪刀布。
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
 * 模拟字符串石头剪刀布。
 * param a 第一个字符串
 * param b 第二个字符串
 * return 一个 Triple，分别是 a 胜、负、平的个数。
 */
fun strRockPaperScissors(a: String, b: String): Triple<Int, Int, Int> {
    var aWin = 0
    var aLose = 0
    var aDraw = 0
    for (i in a.indices) {
        when (a[i]) {
            'R' -> when (b[i]) {
                'R' -> aDraw++
                'P' -> aLose++
                'S' -> aWin++
            }
            'P' -> when (b[i]) {
                'R' -> aWin++
                'P' -> aDraw++
                'S' -> aLose++
            }
            'S' -> when (b[i]) {
                'R' -> aLose++
                'P' -> aWin++
                'S' -> aDraw++
            }
        }
    }
    return Triple(aWin, aLose, aDraw)
}


fun main(args: Array<String>) {
    val n = nextInt()
    val a = next()
    val b = next()
    val (aWin, aLose, aDraw) = strRockPaperScissors(a, b)
    println("$aWin $aLose")

}
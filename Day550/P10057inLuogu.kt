/*****************************************************************
 * 题目：Line
 * 描述：问两个线段（与坐标轴平行）之间的最短距离。
 * 思路：两两求距离。
 * 空间：无。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.hypot
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

// 二维点
data class Point(val x: Int, val y: Int) {}

fun main(args: Array<String>) {
    val query = nextInt()

    repeat(query) {
        val xA = nextInt(); val yA = nextInt()
        val xB = nextInt(); nextInt()/* yA == yB */
        val xC = nextInt(); 
        val yC = nextInt(); nextInt() /* xC == xD */
        val yD = nextInt()
        // 判断 x 方向是否重合
        val overlapX = xC in xA..xB
        // 判断 y 方向是否重合
        val overlapY = yA in yC..yD
        val ans = when {
            overlapX && overlapY -> 0
            overlapX || overlapY -> 1
            else -> 2
        }
        println(ans)
    }
}
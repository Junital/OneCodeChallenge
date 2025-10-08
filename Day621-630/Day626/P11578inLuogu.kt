/*****************************************************************
 * 题目：[CCC 2020] Art
 * 描述：给出n个点的坐标，问如何设计一个最小的矩形，使得所有点都在矩形内。
 * 思路：minX减1, minY减1, maxX加1, maxY加1
 * 函数：minRectForPoints模拟。
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

// 读取 n 个Double
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
 * 对象：Point
 * 描述：点的坐标
 */
data class Point(val x: Int, val y: Int) {
    /**
     * 描述：判断点是否在矩形内
     */
    fun isInRect(rect: Rect): Boolean =
        x in rect.minX..rect.maxX && y in rect.minY..rect.maxY
}

/**
 * 对象：Rect
 * 描述：矩形的坐标
 */
data class Rect(val minX: Int, val minY: Int, val maxX: Int, val maxY: Int) {
    /**
     * 描述：判断矩形是否包含点
     */
    fun contains(point: Point): Boolean =
        point.isInRect(this)

    /**
     * 定义输出格式
     */
    override fun toString(): String =
        "$minX,$minY\n$maxX,$maxY"
}

/**
 * 描述：模拟最小矩形包含所有点
 */
fun minRectForPoints(points: List<Point>): Rect {
    val minX = points.minOf { it.x }
    val minY = points.minOf { it.y }
    val maxX = points.maxOf { it.x }
    val maxY = points.maxOf { it.y }
    return Rect(minX - 1, minY - 1, maxX + 1, maxY + 1)
}

fun main(args: Array<String>) {
    val n = nextInt()
    // 读取 n 个点（XY坐标被逗号隔开）
    val points = List(n) {
        val (x, y) = next().split(',').map { it.toInt() }
        Point(x, y)
    }

    // 模拟最小矩形包含所有点
    val rect = minRectForPoints(points)
    // 输出矩形的坐标
    println(rect)
}
/*****************************************************************
 * 题目：计算三角形面积
 * 描述：给出三角形三个顶点的坐标，要求计算这个三角形的面积。
 * 思路：底乘高的计算方式。
 * 对象：Triangle模拟三角形。
 * 注意：输出格式。
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

// 读取一个 Double
private fun nextDouble(): Double = next().toDouble()

/**
 * 把 Pair<A,B> 转成 "$first<sep>$second" 的字符串
 */
fun <A, B> Pair<A, B>.joinToString(
    separator: CharSequence = ", "
): String = listOf(first, second)
    .joinToString(separator) { it.toString() }

// 二维点
data class Point(val x: Double, val y: Double) {
    /** 与另一个点的欧氏距离 */
    fun distanceTo(other: Point): Double =
        hypot(other.x - x, other.y - y)
}

/**
 * 计算点 P 到由 A、B 确定的**无限直线**的距离
 *
 * 公式：| (B−A) × (P−A) | / |B−A|
 * 其中二维叉积 (x1,y1)×(x2,y2) = x1*y2 – y1*x2
 */
fun Point.distanceToLine(a: Point, b: Point): Double {
    // 向量 AB 和 AP
    val abx = b.x - a.x
    val aby = b.y - a.y
    val apx = x   - a.x
    val apy = y   - a.y

    // 叉积的绝对值
    val cross = abs(abx * apy - aby * apx)
    // 线段 AB 的长度
    val abLen = hypot(abx, aby)
    return if (abLen == 0.0) {
        // A、B 重合时退化为点距离
        hypot(apx, apy)
    } else {
        cross / abLen
    }
}

data class Triangle(val a: Point, val b: Point, val c: Point) {
    /**
     * 三角形面积 = 底边 BC 的长度 * A 到直线 BC 的距离 / 2
     */
    fun area(): Double {
        // 高：顶点 A 到 BC 所在直线的距离
        val height = a.distanceToLine(b, c)
        // 底：BC 的长度
        val base   = b.distanceTo(c)
        return base * height / 2
    }

    /**
     * 三角形面积 = 叉积计算面积
     */
    fun area_opt(): Double {
        val abx = b.x - a.x
        val aby = b.y - a.y
        val acx = c.x - a.x
        val acy = c.y - a.y
        val cross = abs(abx*acy - aby*acx)
        return cross / 2
    }
}

fun main(args: Array<String>) {
    val A = Point(nextDouble(), nextDouble())
    val B = Point(nextDouble(), nextDouble())
    val C = Point(nextDouble(), nextDouble())

    val ans = String.format("%.2f", Triangle(A, B, C).area())

    println(ans) 
}
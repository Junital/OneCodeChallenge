/*****************************************************************
 * 题目：[GESP202406 一级] 立方数
 * 描述：确定一个数是否是立方数。
 * 思路：直接开根号。
 * 函数：isPerfectCube判断一个数是否是立方数。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.roundToLong  

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
 * 判断某个数是否是立方数。
 */
fun isPerfectCube(n: Long): Boolean {
    // 计算 n 的立方根（Double）
    val root = Math.cbrt(n.toDouble())
    // 四舍五入到最接近的长整型
    val rounded = root.roundToLong()
    // 检查 rounded^3 是否等于 n
    return rounded * rounded * rounded == n
}

fun main(args: Array<String>) {
    val n = nextLong()

    if(isPerfectCube(n)) {
        println("Yes")
    }else {
        println("No")
    }
}
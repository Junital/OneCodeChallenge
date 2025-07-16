/*****************************************************************
 * 题目：[语言月赛 202408] 皆与生物有缘
 * 描述：求向上取整平均分。
 * 思路：求和，divUp。
 * 函数：divUp为向上整除。
 * 注意：会溢出。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
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
 * 向上整除：a / b，如果有余数则结果再加 1
 */
fun Int.divUp(b: Int): Int =
    this / b + if (this % b != 0) 1 else 0

/**
 * 向上整除：a / b，如果有余数则结果再加 1
 */
fun Long.divUp(b: Long): Long =
    this / b + if (this % b != 0L) 1L else 0L

fun main(args: Array<String>) {
    val problemNum = nextInt()
    val scores = mutableListOf<Long>()

    repeat(2){
        val problems = List<Long>(problemNum) { nextLong() }

        scores.add(problems.sum())
    }

    println(scores.sum().divUp(scores.size.toLong()))
}
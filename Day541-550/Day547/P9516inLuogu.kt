/*****************************************************************
 * 题目：color
 * 描述：根据分数，判断用户名颜色。
 * 思路：when语法糖。
 * 函数：getNameColor模拟获取用户颜色。
 * 注意：无。
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
 * 根据区间判断用户名颜色。
 */
fun getNameColor(score: Int): String = when(score) {
    in 0..99 -> "Gray"
    in 100..119 -> "Blue"
    in 120..169 -> "Green"
    in 170..229 -> "Orange"
    in 230..500 -> "Red"
    else -> "Null"
}

fun main(args: Array<String>) {
    val (basicCredit, commuContri, competition, practice, achievement) = nextInts(5)

    println(getNameColor(basicCredit + commuContri + competition + practice + achievement))
}
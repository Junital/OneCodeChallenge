/*****************************************************************
 * 题目：「Wdoi-4」使用三个系统程度的能力
 * 描述：根据文本的换行符，判断对应的操作系统。
 * 思路：\r\n是Windows系统的换行符，\n是Linux系统的换行符，\r是Mac系统的换行符。
 * 函数：judgeOSbyText模拟根据文本判断操作系统。
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
 * 模拟根据文本判断操作系统。
 * @param text 文本
 * @return 操作系统
 */
fun judgeOSbyText(text: String): String {
    if (text.contains("\\r\\n")) {
        return "windows"
    } else if (text.contains("\\n")) {
        return "linux"
    } else if (text.contains("\\r")) {
        return "mac"
    } else {
        return "Unknown"
    }
}

fun main(args: Array<String>) {
    val text = reader.readLine() ?: ""
    println(judgeOSbyText(text))
}
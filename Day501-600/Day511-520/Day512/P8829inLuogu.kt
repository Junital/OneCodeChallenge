/*****************************************************************
 * 题目：
 * 描述：
 * 思路：
 * 空间：
 * 注意：
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

fun main(args: Array<String>) {
    // 读入形如 "128MB=?GB" 的表达式
    val input = readLine()!!.trim()
    // 正则：分成三组 —— 数字、源单位、目标单位
    val regex = """^(\d+(?:\.\d+)?)([KMG]?B)=\?([KMG]?B)$""".toRegex()

    val match = regex.matchEntire(input)
        ?: error("输入格式不对，示例：128MB=?GB")

    val (numStr, fromUnit, toUnit) = match.destructured
    val value = numStr.toDouble()

    val factor = mapOf(
        "B"  to 1_024.0,
        "KB" to 1_024.0 * 1_024,
        "MB" to 1_024.0 * 1_024 * 1_024,
        "GB" to 1_024.0 * 1_024 * 1_024 * 1_024,
    )

    val bytes = value * (factor[fromUnit] ?: error("未知单位 $fromUnit"))
    val result = bytes / (factor[toUnit] ?: error("未知单位 $toUnit"))

    // 保留三位小数输出
    println(String.format("%.6f", result))
}
/*****************************************************************
 * 题目：[四川青少年 C++ 算法设计大赛 2024] 4-5 年级组第 2 题
 * 描述：计算两个时间点的差距。
 * 思路：用Duration封装。
 * 函数：diffAsHMS计算时刻之间差距。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import java.time.Duration
import java.time.LocalTime

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
 * 计算两个 LocalTime 之间的差值，结果格式为 "HH:mm:ss"。
 * 如果 end 在 start 之前，默认认为跨了一天（+24h）。
 */
fun diffAsHMS(start: LocalTime, end: LocalTime): String {
    // 先算标准的 Duration
    var duration = Duration.between(start, end)
    // 如果为负，说明 end 在前一天，补 24 小时
    if (duration.isNegative) {
        duration = duration.plusDays(1)
    }
    // 拆分小时/分钟/秒
    val totalSeconds = duration.seconds
    val hours = totalSeconds / 3600
    val minutes = (totalSeconds % 3600) / 60
    val seconds = totalSeconds % 60

    // 格式化为两位
    return "${hours} ${minutes} ${seconds}"
}

fun main(args: Array<String>) {
    val endTime = LocalTime.of(nextInt(), nextInt(), nextInt())
    val beginTime = LocalTime.of(nextInt(), nextInt(), nextInt())

    println(diffAsHMS(beginTime, endTime))
}
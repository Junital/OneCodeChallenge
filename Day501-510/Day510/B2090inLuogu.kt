/*****************************************************************
 * 题目：年龄与疾病
 * 描述：根据患者的年龄，输出每个年龄阶段的比例。
 * 思路：切分列表。
 * 函数：splitByThresholds模拟按照阈值切分。
 * 注意：输出格式。
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


/**
 * 按升序阈值列表把 this 分成 N+1 段：
 *  (-∞..t0], (t0..t1], …, (t_{k-1}..∞)
 */
fun List<Int>.splitByThresholds(thresholds: List<Int>): List<List<Int>> {
    require(thresholds == thresholds.sorted()) { "阈值列表必须升序" }
    val groups = List(thresholds.size + 1) { mutableListOf<Int>() }
    for (x in this) {
        // 找到第一个不小于 x 的阈值
        val idx = thresholds.indexOfFirst { x <= it }
        if (idx >= 0) groups[idx].add(x)
        else            groups.last().add(x)
    }
    return groups
}

fun main(args: Array<String>) {
    val thresholds = listOf(18, 35, 60)
    val size = nextInt()

    val patients = MutableList<Int>(size){nextInt()}
    val subPatients = patients.splitByThresholds(thresholds)

    for(i in subPatients.indices)
    {
        val ratio = subPatients[i].size * 100.0 / size

        println(String.format("%.2f%%", ratio))
    }
}
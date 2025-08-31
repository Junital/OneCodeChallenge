/*****************************************************************
 * 题目：[语言月赛 202411] K/D/A
 * 描述：根据K/D/A三个参数转化为实力，找到实力最高的人。
 * 思路：数组找最大。
 * 函数：achieveToPower模拟战绩到实力。
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
 * 将三个参数转化为对应的实力。
 */
fun achieveToPower(K: Int, D: Int, A: Int): Int {
    return when {
        K - D >= 10 -> K * (K - D) + A
        K >= D -> (K - D + 1) * 3 + A
        else -> A * 2
    }
}

fun main(args: Array<String>) {
    val warriorNum = nextInt()
    val warriors = mutableListOf<Int>()
    
    repeat(warriorNum) {
        val (K, D, A) = next().split("/").map { it.toInt() }

        warriors.add(achieveToPower(K, D, A))
    }

    println(warriors.withIndex().maxByOrNull { it.value }?.index?.let { it + 1 })
}
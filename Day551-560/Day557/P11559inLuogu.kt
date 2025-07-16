/*****************************************************************
 * 题目：【MX-X7-T0】[LSOT-3] 嗯欧哎
 * 描述：问是否成绩满足一些情况。
 * 思路：先划分，再判断。
 * 函数：
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
 * 根据分数判断通过状态。
 */
fun getPassState(score: Int): String = when(score) {
    in 85..100 -> "ApproxiPass"
    in 45..84 -> "HighBrute"
    in 25..44 -> "LowBrute"
    in 1..24 -> "ExpBrute"
    0 -> "ZeroBrute"
    else -> "Null"
}

fun main(args: Array<String>) {
    val stateCnt = mutableMapOf<String, Int>()
    val scores = nextInts(3)

    for(score in scores) {
        val key = getPassState(score)
        stateCnt[key] = stateCnt.getOrPut(key) { 0 } + 1
    }

    if (
        (stateCnt.getOrDefault("HighBrute", 0) == 1 &&
        stateCnt.getOrDefault("LowBrute", 0) == 1 &&
        stateCnt.getOrDefault("ExpBrute", 0) == 1) ||

        (stateCnt.getOrDefault("ApproxiPass", 0) == 1 &&
        stateCnt.getOrDefault("HighBrute", 0) == 1 &&
        stateCnt.getOrDefault("LowBrute", 0) == 1) ||

        (stateCnt.getOrDefault("ApproxiPass", 0) == 2 &&
        stateCnt.getOrDefault("HighBrute", 0) + stateCnt.getOrDefault("LowBrute", 0) == 1) ||

        (stateCnt.getOrDefault("ApproxiPass", 0) == 3)
    ) {
        println("Yes")
    } else {
        println("No")
    }
}
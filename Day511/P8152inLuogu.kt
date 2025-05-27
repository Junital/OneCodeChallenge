/*****************************************************************
 * 题目：「PMOI-5」破译
 * 描述：每次分割右下角的正方形，问最后分成了多少个正方形。
 * 思路：找规律。
 * 空间：无。
 * 注意：数据会溢出，并且需要取模。
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
    val cutSize = nextLong()
    val itNum = nextLong()
    val mod = 998244353

    val squareMinusOne = (cutSize * cutSize % mod - 1 + mod) % mod
    val ans = (itNum * squareMinusOne % mod + 1) % mod

    println(ans)
}
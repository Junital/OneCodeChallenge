/*****************************************************************
 * 题目：[PA 2018] Język polski
 * 描述：输入一个字符串，问有多少子串满足里面包含连续3个波兰语元音a e i o u y
        或连续3个辅音。
 * 思路：计数器累加（之前没接触过）
 * 函数：subStringCount模拟统计子串。
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

// 读取n个Double
fun nextDoubles(n: Int): List<Double> = List(n) { nextDouble() }

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
 * 统计字符串 s 中满足条件的子串数量
 * 条件：
 *  连续3个波兰语元音a e i o u y
 *  连续3个辅音
 */
fun subStringCount(s: String): Long {
    var vow = 0
    var con = 0
    var lastIndex = 0
    var count = 0L
    for (i in s.indices) {
        if (s[i] in "aeiouy") {
            vow++
            con = 0
        } else {
            con++
            vow = 0
        }
        if (vow >= 3 || con >= 3) {
            count += i - 1
            lastIndex = i
        }else {
            count += maxOf(lastIndex - 1, 0)

        }
    }

    return count
}


fun main(args: Array<String>) {
    val s = next()
    println(subStringCount(s))

}
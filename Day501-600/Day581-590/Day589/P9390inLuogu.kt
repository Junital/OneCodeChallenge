/*****************************************************************
 * 题目：金盏花
 * 描述：已知Y为12位数X的后6位，还已知Z，求可能的|X - Z|的最小值。
 * 思路：前六位不能前导零，至少是100000~999999，获取Y的前六位，然后枚举X的前六位，计算|X - Z|的最小值。
 * 函数名：minDiff模拟这个过程。
 * 注意：类型是Long。
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

/*
 * 函数：minDiff
 * 描述：计算|X - Z|的最小值。
 * 输入：Y,Z
 * 输出：|X - Z|的最小值。
 */
fun minDiff(Y: Long, Z: Long): Long {
    var minDiff = Long.MAX_VALUE

    for (i in 100000..999999) {
        val x = i.toLong() * 1000000 + Y
        val diff = Math.abs(x - Z)
        if (diff < minDiff) {
            minDiff = diff
        }
    }
    return minDiff
}


fun main(args: Array<String>) {
    val (Y, Z) = nextLongs(2)
    println(minDiff(Y, Z))
}
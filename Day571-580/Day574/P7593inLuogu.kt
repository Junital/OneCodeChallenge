/*****************************************************************
 * 题目：「EZEC-8」凑数
 * 描述：问能否从1到n中，恰好选择k个不重复的数，使其和为s。
 * 思路：贪心算法。
 * 函数：chooseSum模拟选择和为S的组合，没有返回空。
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
 * 在 [1..n] 中选出 k 个不同的数，使它们的和为 s。
 * @return 满足条件的数列表（长度恰好为 k），如果无解则返回空列表。
 */
fun chooseSum(
    n: Int, k: Int, s: Long
): Boolean {
    // 1. 先做可行性剪枝：最小和与最大和
    // 最小和 = 1 + 2 + ... + k = k*(k+1)/2
    val minSum = k.toLong() * (k + 1) / 2
    // 最大和 = n + (n-1) + ... + (n-k+1) = k*(2n-k+1)/2
    val maxSum = k.toLong() * (2L * n - k + 1) / 2
    if (s < minSum || s > maxSum) return false

    return true
}

fun main(args: Array<String>) {
    val queryNum = nextInt()

    repeat(queryNum) {
        val (n, k) = nextInts(2)
        val s = nextLong()

        if (chooseSum(n, k, s)) {
            println("Yes")
        }else {
            println("No")
        }
    }
}
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

fun main() {
    // 读入
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map { it.toInt() }

    // 阈值：红边胜场必须 <= T
    val T = n / 2

    // 构造原始和加权后红边胜利的二值数组（1 表示红边胜，0 表示粉边胜）
    val orig = IntArray(n) { i -> if (a[i] >= 50) 1 else 0 }
    val adj  = IntArray(n) { i -> if (a[i] >= 52) 1 else 0 }

    // 前缀和，长度 n+1，pre[0]=0
    val preOrig = LongArray(n + 1)  // 用 Long 以防万一
    val preAdj  = LongArray(n + 1)
    for (i in 1..n) {
        preOrig[i] = preOrig[i - 1] + orig[i - 1]
        preAdj [i] = preAdj [i - 1] + adj [i - 1]
    }

    val totalOrig = preOrig[n]  // 原始红边总胜场
    var ans = 0

    // 枚举区间起点 l from 1 to n-k+1（1-based）
    for (l in 1..n - k + 1) {
        val r = l + k - 1
        val winOrig = preOrig[r] - preOrig[l - 1]
        val winAdj  = preAdj [r] - preAdj [l - 1]
        val totalRed = totalOrig - winOrig + winAdj
        if (totalRed <= T) {
            ans++
        }
    }

    // 输出答案
    println(ans)
}

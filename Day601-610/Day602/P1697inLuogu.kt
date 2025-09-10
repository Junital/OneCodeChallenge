/*****************************************************************
 * 题目：[USACO18JAN] Lifeguards B
 * 描述：有若干个线段，每个线段有一个开始时间和一个结束时间，问去掉一个线段后，
        其他线段的总长度的最大值是多少。
 * 思路：
  1. 差分数组 + 前缀和
  2. 离散化
  3. 计算每个线段独占的时间长度
  4. 枚举去掉哪个线段
 * 函数：chooseUselessSegment模拟去掉一个最差线段
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
 * 选择一个最差的线段去掉
 * 最差的定义：去掉这个线段后，其他线段的总长度的最大值最小
 * 思路：
 * 1. 先计算每个线段独占的时间长度
 * 2. 枚举去掉哪个线段
 * 3. 计算去掉这个线段后，其他线段的总长度的最大值
 * 4. 取所有最大值的最小值
 * 时间复杂度：O(n^2)
 */
fun chooseUselessSegment(segments: List<Pair<Int, Int>>): Int {
    val n = segments.size
    val exclusiveTime = IntArray(1001)
    for (i in 0 until n) {
        val (start, end) = segments[i]
        for (j in start until end) {
            exclusiveTime[j]++
        }
    }

    var maxTotalLength = 0
    for (i in 0 until n) {
        val (start, end) = segments[i]
        var totalLength = 0
        for (j in 0 until 1001) {
            if (exclusiveTime[j] > 1 || (exclusiveTime[j] == 1 && (j < start || j >= end))) {
                totalLength++
            }
        }
        maxTotalLength = maxTotalLength.coerceAtLeast(totalLength)
    }
    return maxTotalLength
}


fun main(args: Array<String>) {
    val n = nextInt()
    val segments = List(n) {
        val (start, end) = nextInts(2)
        start to end
    }
    val minTotalLength = chooseUselessSegment(segments)
    println(minTotalLength)
}
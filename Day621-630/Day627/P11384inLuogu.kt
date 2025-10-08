/*****************************************************************
 * 题目：[POI 2024/2025 R1] Usuwanie
 * 描述：从一段连续的数字中，找到最多的配对，两者和为偶数。
 * 思路：统计奇数和偶数的数量。
 * 函数：statsOddEven模拟统计奇偶。
 * 注意：类型为long。
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
 * 统计奇数和偶数的数量
 */
fun statsOddEven(start: Long, end: Long): Pair<Long, Long> {
    // 不能遍历所有数字，范围可能很大，只能统计数量
    val totalNum = end - start + 1
    val odd = totalNum / 2 + if (start % 2 == 1L && end % 2 == 1L) 1 else 0
    val even = totalNum - odd
    return odd to even
}


fun main(args: Array<String>) {
    val (start, end) = nextLongs(2)
    val (odd, even) = statsOddEven(start, end)
    
    var cnt = 0L
    if(odd % 2 == 0L) {
        cnt += odd
    } else {
        cnt += (odd - 1)
    }

    if(even % 2 == 0L) {
        cnt += even
    } else {
        cnt += (even - 1)
    }

    println(cnt)
}
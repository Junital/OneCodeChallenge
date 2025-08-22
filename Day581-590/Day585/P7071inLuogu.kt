/*****************************************************************
 * 题目：[CSP-J2020] 优秀的拆分
 * 描述：求出一个数是否能被拆分成若干个不同的2的整数次幂数。
 * 思路：通过观察发现，似乎只要是偶数都能被拆分。
 * 函数：splitEven模拟拆分偶数。
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
 * 拆分偶数
 */
fun splitEven(n: Int): List<Int> {
    val list = mutableListOf<Int>()
    var x = n
    while (x > 0) {
        val p = Integer.highestOneBit(x)
        list.add(p) // 要加入刚好小于等于这个数的2的次幂
        x -= p
    }

    // 检验一下是否x等于0
    if (x != 0) {
        throw Exception("Can not split!")
    }

    return list
}

fun main(args: Array<String>) {
    val n = nextInt()
    if(n % 2 != 0) {
        println(-1)
    } else {
        val list = splitEven(n)
        // 从大到小排序
        println(list.joinToString(" "))
    }
}
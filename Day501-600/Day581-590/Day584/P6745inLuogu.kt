/*****************************************************************
 * 题目：『MdOI R3』Number
 * 描述：给出k和x，求出10^k+x的值。
 * 思路：k很大，只能输出字符串，还需要知道x的位数，判断所占的0。
 * 函数：decToStr模拟十进制计数法。
 * 注意：x的类型为Long。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.EOFException
import java.util.StringTokenizer
import java.math.BigInteger


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
 * 根据k和x，返回10^k+x的值。
 * param k 指数
 * param x 系数
 * return 10^k+x的值
 */
fun decToStr(k: Int, x: Long): String {
    require(k >= 0) { "k must be non-negative" }
    val bigX = BigInteger.valueOf(x)
    val pow10 = BigInteger.TEN.pow(k)
    return pow10.add(bigX).toString()
}


fun main(args: Array<String>) {
    val k = nextInt()
    val x = nextLong()
    println(decToStr(k, x))
}
/*****************************************************************
 * 题目：【MX-X15-T1】奶龙龙
 * 描述：给定原价，触发促销价的个数，降价后的单价，以及至少想买的个数。
        问最少需要花多少钱。
 * 思路：取最小值。
 * 函数：minPrice模拟计算最小价格。
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
 * 计算最小价格。
 * @param originalPrice 原价
 * @param triggerNum 触发促销价的个数
 * @param discountPrice 降价后的单价
 * @param buyNum 至少想买的个数
 * @return 最少需要花多少钱
 */
fun minPrice(
    originalPrice: Int,
    triggerNum: Int,
    discountPrice: Int,
    buyNum: Int
): Int {
    if(buyNum >= triggerNum) {
        return buyNum * discountPrice
    }
    return minOf(buyNum * originalPrice, triggerNum * discountPrice)
}


fun main(args: Array<String>) {
    val (originalPrice, triggerNum, discountPrice, buyNum) = nextInts(4)
    println(minPrice(originalPrice, triggerNum, discountPrice, buyNum))
}
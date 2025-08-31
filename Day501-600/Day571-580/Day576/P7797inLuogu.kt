/*****************************************************************
 * 题目：[COCI 2015/2016 #6] BELA
 * 描述：分数求和。
 * 思路：映射，求和。
 * 空间：无。
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

fun main(args: Array<String>) {
    val num = nextInt()
    val specialSymbol = nextChar()
    var totalValue = 0

    val cardValueMap = mapOf(
        'A' to mapOf("special" to 11, "normal" to 11),
        'K' to mapOf("special" to 4, "normal" to 4),
        'Q' to mapOf("special" to 3, "normal" to 3),
        'J' to mapOf("special" to 20, "normal" to 2),
        'T' to mapOf("special" to 10, "normal" to 10),
        '9' to mapOf("special" to 14, "normal" to 0),
        '8' to mapOf("special" to 0, "normal" to 0),
        '7' to mapOf("special" to 0, "normal" to 0)
    )

    repeat(4 * num) {
        val (card, symbol) = next().toCharArray()

        if(symbol == specialSymbol) {
            totalValue += cardValueMap[card]?.get("special") ?: 0
        }else {
            totalValue += cardValueMap[card]?.get("normal") ?: 0
        }
    }

    println(totalValue)
}
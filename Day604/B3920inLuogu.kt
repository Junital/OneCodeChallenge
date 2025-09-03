/*****************************************************************
 * 题目：[语言月赛 202401] Genshin 玩家
 * 描述：寻找方案，找到子串Genshin和子串player，需要保证前后关系，问方案数。
 * 思路：记录子串的开始位置，然后计算统计。
 * 函数：countSubstrings统计子串的数量。
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
 * 统计子串的数量，返回子串的开始位置
 */
fun countSubstrings(str: String, sub: String): List<Int> {
    val positions = mutableListOf<Int>()
    for (i in 0 until str.length) {
        if (str.startsWith(sub, i)) {
            positions.add(i)
        }
    }
    return positions

}


fun main(args: Array<String>) {
    val str = next()
    val sub1 = "Genshin"
    val sub2 = "player"
    val positions1 = countSubstrings(str, sub1)
    val positions2 = countSubstrings(str, sub2)
    var count = 0L

    for (i in positions1) {
        for (j in positions2) {
            if (i < j) {
                count++
            }
        }
    }

    println(count)
}
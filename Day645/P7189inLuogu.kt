/*****************************************************************
 * 题目：[COCI 2007/2008 #6] PARKING
 * 描述：三辆车有各自的停车时间，如果同一时间有两辆或以上车在停，费用不一样。
 * 思路：时间范围少，可以直接模拟。
 * 空间：无。
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

fun main(args: Array<String>) {
    val (a, b, c) = nextInts(3)

    val (abegin, aend) = nextInts(2)
    val (bbegin, bend) = nextInts(2)
    val (cbegin, cend) = nextInts(2)

    var cost = 0
    for (i in abegin until aend) {
        if(i in bbegin until bend && i in cbegin until cend){
            cost += c
        }else if (i in bbegin until bend || i in cbegin until cend) {
            cost += b
        } else {
            cost += a
        }
    }
    for (i in bbegin until bend) {
        if (i in abegin until aend && i in cbegin until cend) {
            cost += c
        } else if (i in abegin until aend || i in cbegin until cend) {
            cost += b
        }else {
            cost += a
        }
    }
    for (i in cbegin until cend) {
        if (i in abegin until aend && i in bbegin until bend) {
            cost += c
        } else if (i in abegin until aend || i in bbegin until bend) {
            cost += b
        }else {
            cost += a
        }
    }
    println(cost)

}
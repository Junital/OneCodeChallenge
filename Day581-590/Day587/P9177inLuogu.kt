/*****************************************************************
 * 题目：[COCI 2022/2023 #5] Kalendar
 * 描述：根据这个月的天数和初始天的星期，给出这个月的日历表。
 * 思路：有点复杂，需要设计一个类来表示这个月的日历表。
 * 对象：Kalendar模拟日历表。
 * 注意：按照格式输出。
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
 * 向上整除：a / b，如果有余数则结果再加 1
 */
fun Int.divUp(b: Int): Int =
    this / b + if (this % b != 0) 1 else 0

/**
 * Kalendar
 * 描述：根据这个月的天数和初始天的星期，给出这个月的日历表。
 * 思路：有点复杂，需要设计一个类来表示这个月的日历表。
 * 对象：Kalendar模拟日历表。
 * 注意：按照格式输出。
 */
class Kalendar(
    val day: Int,
    val week: Int
) {
    /*
     * 要求：
     * 第一行和最后一行为+---------------------+
     * 中间行的第一个和最后一个字符为|
     * 中间行其他字符有21个，每个位置占3个字符。
     * 1 如果无数字，输出...
     * 2 如果有数字，输出数字，不足3位用.补全, 右对齐。
     */
    fun print() {
        println("+---------------------+")
        // 计算初始位置，需要几行。
        val row = (day + week - 1).divUp(7)
        // 计算初始位置，需要几个空格。
        val space = week - 1

        for (i in 0 until row) {
            print("|")
            for (j in 0 until 7) {
                if (i == 0 && j < space) {
                    print("...")
                } else {
                    val d = i * 7 + j - space + 1
                    if (d <= 0 || d > day) {
                        print("...")
                    } else {
                        print(d.toString().padStart(3, '.'))
                    }
                }
            }
            println("|")
        }

        // 输出最后一行
        println("+---------------------+")
    }

}


fun main(args: Array<String>) {
    val (day, week) = nextInts(2)
    val kalendar = Kalendar(day, week)
    kalendar.print()
}
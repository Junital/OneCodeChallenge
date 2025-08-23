/*****************************************************************
 * 题目：[语言月赛202209] 排排队
 * 描述：将一个数组拆成两个数组，分别为奇数数组和偶数数组。
 * 思路：遍历数组，将奇数放到奇数数组，偶数放到偶数数组。
 * 函数：splitArrayByOddEven模拟拆分奇偶数组。
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
 * 拆分数组为奇数数组和偶数数组
 * param arr 原始数组
 * return 奇数数组和偶数数组的 Pair
 */
fun splitArrayByOddEven(arr: IntArray): Pair<IntArray, IntArray> {
    val oddArr = mutableListOf<Int>()
    val evenArr = mutableListOf<Int>()
    for (i in arr) {
        if (i % 2 == 0) {
            evenArr.add(i)
        } else {
            oddArr.add(i)
        }
    }
    return oddArr.toIntArray() to evenArr.toIntArray()
}

fun main(args: Array<String>) {
    val n = nextInt()
    val arr = nextInts(n).toIntArray()
    val (oddArr, evenArr) = splitArrayByOddEven(arr)
    println(oddArr.joinToString(" "))
    println(evenArr.joinToString(" "))
}
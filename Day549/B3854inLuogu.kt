/*****************************************************************
 * 题目：[语言月赛 202309] 数组与内存 EV
 * 描述：问数组是否会非法访问内存。
 * 思路：转换，看是否越界。
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
    val (row, col) = nextLongs(2)
    val (x, y) = nextInts(2)

    if(x * col + y + 1 <= row * col){
        println("Program ends with return value 0.")
    }else{
        println("Segmentation fault.")
    }
}
/*****************************************************************
 * 题目：[NOISG 2019 Prelim] Palindromic FizzBuzz
 * 描述：问数字是否回文。
 * 思路：转为字符串，然后调用函数。
 * 函数：isPalindrome判断是否回文。
 * 注意：小心溢出情况。
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

/**
 * 判断字符串是否是回文（忽略大小写和非字母数字字符）。
 */
fun String.isPalindrome(): Boolean {
    // 只保留字母和数字，并统一为小写
    val sanitized = this
        .filter { it.isLetterOrDigit() }
        .lowercase()
    // 与反转后的字符串比较
    return sanitized == sanitized.reversed()
}


fun main(args: Array<String>) {
    val (left, right) = nextLongs(2)

    for(i in left..right) {
        if(i.toString().isPalindrome()) {
            println("Palindrome!")
        }else {
            println(i)
        }
    }
}
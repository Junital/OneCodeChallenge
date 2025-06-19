/*****************************************************************
 * 题目：[信息与未来 2024] 幸运数字
 * 描述：判断数字的二进制中，0和1是否落单。
 * 思路：字符串计数判断。
 * 函数：judgeSingleBinary模拟判断落单二进制数。
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
 * 判断二进制数是否落单。
 */
fun judgeSingleBinary(num: Int): Boolean{
    val str = num.toString(2)

    var i = 0

    while(i < str.length){
        val ch = str[i]
        var cnt = 0

        while(i < str.length && str[i] == ch){
            cnt++
            i++
        }

        if(cnt == 1){
            return false
        }
    }

    return true
}

fun main(args: Array<String>) {
    val (begin, end) = nextInts(2)

    var cnt = 0
    for(i in begin..end){
        if(judgeSingleBinary(i)){
            cnt++
        }
    }
    println(cnt)
}
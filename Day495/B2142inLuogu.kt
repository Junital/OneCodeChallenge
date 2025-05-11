/*****************************************************************
 * 题目：求 1+2+3+...+N 的值
 * 描述：必须用递归的方式求。
 * 思路：逐层递归。
 * 函数：sumToN模拟数列求和。
 * 注意：别溢出了。
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
 * 把 Pair<A,B> 转成 "$first<sep>$second" 的字符串
 */
fun <A, B> Pair<A, B>.joinToString(
    separator: CharSequence = ", "
): String = listOf(first, second)
    .joinToString(separator) { it.toString() }

/**
 * 计算从1到N的求和
 */
fun sumToN(n: Int): Int
{
    return if (n == 1) 1
    else sumToN(n - 1) + n
}

fun main(args: Array<String>) {
    val N = nextInt()

    println(sumToN(N))
}
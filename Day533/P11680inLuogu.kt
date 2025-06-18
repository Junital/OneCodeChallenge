/*****************************************************************
 * 题目：[Algo Beat Contest 001 B] Between Head and Tail
 * 描述：求区间内的首中尾相等数。
 * 思路：判断函数。
 * 函数：judgeHMT模拟判断首中尾数。
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
 判断是否是首中尾数。
 */
fun judgeHMT(num: Int): Boolean{
    val str = num.toString()

    if(str.length % 2 == 0){
        return false
    }

    return str[0] == str[(str.length - 1) / 2] && str[(str.length - 1) / 2] == str[str.length - 1]
}

fun main(args: Array<String>) {
    val queryNum = nextInt()

    repeat(queryNum){
        val (begin, end) = nextInts(2)
        val res = mutableListOf<Int>()
        for(i in begin..end){
            if(judgeHMT(i)){
                res.add(i)
            }
        }
        println(res.joinToString(" "))
    }
}
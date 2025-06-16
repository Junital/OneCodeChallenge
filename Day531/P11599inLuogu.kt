/*****************************************************************
 * 题目：『Fwb』神话の传播
 * 描述：夸父几天才能追到太阳。
 * 思路：先休息，再去追。
 * 函数：divUp模拟上整除。
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
 * 向上整除：a / b，如果有余数则结果再加 1
 */
fun Int.divUp(b: Int): Int =
    this / b + if (this % b != 0) 1 else 0

fun main(args: Array<String>) {
    val (dis, chase, stamina) = nextInts(3)

    var chaseDay = dis.divUp(chase)

    if(chaseDay > stamina){
        chaseDay += (chaseDay - stamina).divUp(stamina)
    }

    println(chaseDay)
}
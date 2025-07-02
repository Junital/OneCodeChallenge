/*****************************************************************
 * 题目：[语言月赛 202407] rules
 * 描述：问一条规则是否获得了大家的支持。
 * 思路：存储判断。
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
    val (peopleNum, dayNum, code) = nextInts(3)
    var dailyCnt = 0
    var totalCnt = 0

    repeat(dayNum){
        dailyCnt = 0
        repeat(peopleNum){
            if(nextInt() == code){
                dailyCnt++
            }
        }

        if(dailyCnt >= (peopleNum + 1) / 2){
            totalCnt++
        }
    }

    if(totalCnt >= (dayNum + 1) / 2){
        println("YES")
    }else{
        println("NO")
    }
}
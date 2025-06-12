/*****************************************************************
 * 题目：[语言月赛 202408] 游戏与共同语言
 * 描述：比较胜局、净胜、平局记录。
 * 思路：设计compare函数。
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

/**
战队
 */
class Team(val winNum: Int, val netWin: Int, val drawNum: Int)

fun main(args: Array<String>) {
    val t1 = Team(nextInt(), nextInt(), nextInt())
    val t2 = Team(nextInt(), nextInt(), nextInt())

    val comparator = compareByDescending <Team> { it.winNum }
        .thenByDescending { it.netWin }
        .thenBy { it.drawNum }
    
    if (comparator.compare(t2, t1) > 0){
        println("A")
    }else{
        println("B")
    }
}
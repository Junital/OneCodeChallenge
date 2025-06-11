/*****************************************************************
 * 题目：[语言月赛 202408] 两座城市的 543 千米
 * 描述：问从城市A到城市B的直达高铁有多少辆。
 * 思路：查找。
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
    val (cityNum, rallNum, start, end) = nextInts(4)

    var cnt = 0
    repeat(rallNum){
        val stationNum = nextInt()
        val stations = List<Int>(stationNum) { nextInt() }

        val startIdx = stations.indexOf(start)
        val endIdx = stations.indexOf(end)

        if(startIdx >= 0 && endIdx >= 0 && startIdx < endIdx){
            cnt++
        }
    }

    println(cnt)
}
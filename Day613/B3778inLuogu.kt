/*****************************************************************
 * 题目：[语言月赛202306] 教学楼
 * 描述：三栋楼分别是3 5 9层，已知三栋楼的人流量，求不低于n层且人流量最小的楼。
 * 思路：filter 过滤出不低于n层的楼，然后取人流量最小的楼
 * 对象：SchoolBuilding模拟教学楼。
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
 * 模拟教学楼
 */
data class SchoolBuilding(
    val name: String,
    val height: Int,
    val people: Int
)


fun main(args: Array<String>) {
    val (n, p1, p2, p3) = nextInts(4)
    val buildings = listOf(
        SchoolBuilding("library", 3, p1),
        SchoolBuilding("comprehensive", 5, p2),
        SchoolBuilding("art", 9, p3)
    )
    val result = buildings.filter { it.height >= n }
        .minByOrNull { it.people }
    println(result?.name ?: "No")
}
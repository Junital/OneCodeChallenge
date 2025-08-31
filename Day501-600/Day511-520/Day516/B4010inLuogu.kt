/*****************************************************************
 * 题目：[语言月赛 202407] eating
 * 描述：对每个饭店按照吸引力+距离进行排序。
 * 思路：compareByDescending thenBy函数
 * 对象：Resturant模拟饭店。
 * 注意：排序要快。
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

/* 饭店 */
data class Resturant(val id: Int, val dis: Int, val taste: Int) {}

fun main(args: Array<String>) {
    val num = nextInt()
    val resturants = mutableListOf<Resturant>()

    repeat(num){ i ->
        resturants.add(Resturant(i, 
                                 nextInt(), 
                                 nextInt()))
    }

    resturants.sortWith(compareByDescending<Resturant> { it.taste * 1.0 / it.dis }.thenBy {it.dis})

    println(resturants[0].id + 1)
}
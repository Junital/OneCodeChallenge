/*****************************************************************
 * 题目：[CCC 2023 J3] Special Event
 * 描述：统计最多人能参加的那几天。
 * 思路：先纵向计算每天的人数，然后找到最多的那几天。
 * 函数：maxElements模拟找到数组中所有最大值的下标。
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
 * 找到数组中所有最大值的下标
 */
fun maxElements(arr: List<Int>): List<Int> {
    val max = arr.maxOrNull() ?: return emptyList()
    return arr.indices.filter { arr[it] == max }
}


fun main(args: Array<String>) {
    val dayNum = 5
    val peopleNum = nextInt()

    val peopleMatrix = Array(peopleNum) { next() }
    val dayPeopleNumList = MutableList(dayNum) { 0 }

    for(i in 0 until dayNum) {
        var dayPeopleNum = 0
        for(j in 0 until peopleNum) {
            if(peopleMatrix[j][i] == 'Y') {
                dayPeopleNum++
            }
        }
        dayPeopleNumList[i] = dayPeopleNum
    }

    var maxDayList = maxElements(dayPeopleNumList)
    // 每个元素 加1
    maxDayList = maxDayList.map { it + 1 }
    println(maxDayList.joinToString(","))

}
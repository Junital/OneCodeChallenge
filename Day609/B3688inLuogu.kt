/*****************************************************************
 * 题目：[语言月赛202212] 旋转排列
 * 描述：有一个循环数组的排列，现在需要不断将最后一个元素放到第一个元素的位置，
        直到最后一个元素是1~n最大的那个元素。中间不断输出数组目前的顺序。
 * 思路：模拟循环操作。
 * 对象：circularArray循环数组。
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
 * 循环数组
 */
class CircularArray<T>(private val array: Array<T>) {
    private val n = array.size
    private var index = 0
    private var head = 0
    fun init() {
        index = 0
    }

    fun next() {
        index = (index + 1) % n
    }
    fun get() = array[index]
    fun getByIdx(idx: Int) = array[(head + idx) % n]

    fun print() {
        for (i in 0 until n) {
            print("${getByIdx(i)} ")
        }
        println()
    }

    fun rotate() {
        head = (head - 1 + n) % n
        index = head
    }
}


fun main(args: Array<String>) {
    val n = nextInt()
    val a = nextInts(n).toTypedArray()
    val circularArray = CircularArray(a)
    circularArray.init()
    // circularArray.print()
    do {
        circularArray.rotate()
        circularArray.print()
    } while (circularArray.getByIdx(n - 1) != n)

}
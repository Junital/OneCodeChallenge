/*****************************************************************
 * 题目：[COCI 2022/2023 #1] Desni klik
 * 描述：问一个数组最大值与最小值的差。
        另外还需要转换矩阵到数组，每i个元素代表第i列从下往上数到第一个#。
 * 思路：两个函数，一个转换矩阵到数组，一个求最大值与最小值的差。
 * 函数：convertMatrixToColumnArray
 * 函数：getMaxMinDiff
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
 * 把矩阵转换为列数组
 */
fun convertMatrixToColumnArray(matrix: Array<String>): IntArray {
    val n = matrix.size
    val m = matrix[0].length
    val columnArray = mutableListOf<Int>()
    for (i in 0 until m) {
        for (j in n - 1 downTo 0) {
            if (matrix[j][i] == '#') {
                columnArray.add(n - j)
                break
            }
        }
    }
    return columnArray.toIntArray()
}

/**
 * 求数组最大值与最小值的差
 */
fun getMaxMinDiff(columnArray: IntArray): Int {
    val max = columnArray.max()
    val min = columnArray.min()
    return max - min
}

fun main(args: Array<String>) {
    val queryNum = nextInt()
    val (n, m) = nextInts(2)
    repeat(queryNum) {
        val matrix = Array(n) { next() }
        val columnArray = convertMatrixToColumnArray(matrix)
        // println(columnArray.joinToString())
        val maxMinDiff = getMaxMinDiff(columnArray)
        println(maxMinDiff)
    }

}
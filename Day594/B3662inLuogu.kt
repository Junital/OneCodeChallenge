/*****************************************************************
 * 题目：[语言月赛202209] 山峰
 * 描述：给定一个二维数组，找到那些比相邻（上下左右）的数都大的数的坐标。
 * 思路：遍历二维数组，判断每个数是否比相邻的数都大。
 * 函数：findPeaks模拟查找山峰。
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
 * 找出二维数组中的山峰元素
 * 一个元素如果比它上下左右的元素都大，那么它就是一个山峰元素。
 * 函数：findPeaks模拟查找山峰。
 */
fun findPeaks(grid: Array<IntArray>): List<Pair<Int, Int>> {
    val peaks = mutableListOf<Pair<Int, Int>>()
    for (i in grid.indices) {
        val row = grid[i]
        for (j in row.indices) {
            val current = row[j]
            var isPeak = true
            
            // 检查上邻居
            if (i > 0 && grid[i-1][j] >= current) isPeak = false
            // 检查下邻居
            if (isPeak && i < grid.size - 1 && grid[i+1][j] >= current) isPeak = false
            // 检查左邻居
            if (isPeak && j > 0 && row[j-1] >= current) isPeak = false
            // 检查右邻居
            if (isPeak && j < row.size - 1 && row[j+1] >= current) isPeak = false
            
            if (isPeak) {
                peaks.add(i to j)
            }
        }
    }
    return peaks
}


fun main(args: Array<String>) {
    val (n, m) = nextInts(2)
    // 将网格改为Array<IntArray>以提高性能
    var grid = Array(n) { nextInts(m).toIntArray() }

    // 输入变化数量T，接下来T行输入x1 y1 x2 y2 表示交换(x1,y1)和(x2,y2)
    val t = nextInt()
    val changes = List(t) { nextInts(4) }
    for (change in changes) {
        val (x1, y1, x2, y2) = change
        // 直接操作数组元素，避免List的装箱开销
        val temp = grid[x1 - 1][y1 - 1]
        grid[x1 - 1][y1 - 1] = grid[x2 - 1][y2 - 1]
        grid[x2 - 1][y2 - 1] = temp
    }

    val peaks = findPeaks(grid)
    println(peaks.size)
    for (peak in peaks) {
        println("${peak.first + 1} ${peak.second + 1}")
    }
}
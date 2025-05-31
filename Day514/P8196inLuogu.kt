/*****************************************************************
 * 题目：[传智杯 #4 决赛] 三元组
 * 描述：一个数组中存在多少三元组（i,j,k）满足前两个元素相加等于第三个？
 * 思路：直接遍历。
 * 空间：无。
 * 注意：注意时间复杂度。
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

fun countTriples(arr: IntArray): Long {
    var cnt = 0L
    // freq 存放前缀 [0..y-1] 中各数出现的次数
    val freq = mutableMapOf<Int, Int>()
    for (z in arr.indices) {
        // 对每个 z，遍历 y 从 0..z-1
        for (y in 0 until z) {
            // 想要 arr[x] = arr[z] - arr[y]
            val need = arr[z] - arr[y]

            // 然后把 arr[y] 记入 freq，供后续 y+1..z-1 用
            freq[arr[y]] = freq.getOrDefault(arr[y], 0) + 1

            // 累加在 [0..y-1] 中出现 need 的次数
            cnt += freq.getOrDefault(need, 0)
        }
        // 清空 freq，为下一个 z 重置前缀
        freq.clear()
    }
    return cnt
}

fun main(args: Array<String>) {
    val queryNum = nextInt()

    repeat(queryNum) {
        val n = nextInt()
        // 读入数组
        val arr = IntArray(n) { nextInt() }
        // 计数
        val ans = countTriples(arr)
        println(ans)
    }
}
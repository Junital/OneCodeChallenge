/*****************************************************************
 * 题目：
 * 描述：
 * 思路：
 * 空间：
 * 注意：
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

/**
 * 批量读取 n 个 Long，返回 List<Long>
 * 可以和解构声明一起使用：
 * val (x,y,z,w) = nextLongs(4)
 */
fun nextLongs(n: Int): List<Long> = List(n) { nextLong() }

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
 * 寻找差为k的配对。
 */
fun findPairWithDifference(collection: Collection<Int>, k: Int): Pair<Int, Int>? {
    val set = HashSet<Int>()
    for (x in collection) {
        if (k == 0) {
            if (set.contains(x)) {
                return Pair(x, x)
            }
        } else {
            if (set.contains(x + k)) {
                return Pair(x + k, x)
            }
            if (set.contains(x - k)) {
                return Pair(x, x - k)
            }
        }
        set.add(x)
    }
    return null
}

fun main(args: Array<String>) {
    val (num, k) = nextInts(2)
    val difficulties = List<Int>(num) { nextInt() }

    if(findPairWithDifference(difficulties, k) != null) {
        println("Yes")
    }else{
        println("No")
    }
}
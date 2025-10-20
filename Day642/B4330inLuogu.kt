/*****************************************************************
 * 题目：[语言月赛 202505] 种子队
 * 描述：判断n个整数是否分别出现在之后的n个数组中。
 * 思路：哈希集合存储，第一个数组的数依次查询第二个数组的集合。
 * 函数：checkSeedTeam 检查种子队
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
 * 检查种子队
 * param k 数组个数
 * param seed 种子数组（长度为k）
 * param arrs k个数组
 * return 是否是种子队
 */
fun checkSeedTeam(k: Int, seed: List<Int>, arrs: List<List<Int>>): Boolean {
    /* 每个数组只包含一个种子队，且不重复。 */
    val seedSet = seed.toSet()

    for(i in 0 until k) {
        var found = false
        for(x in arrs[i]) {
            if(x in seedSet) {
                if(found) {
                    return false
                }
                found = true
            }
        }

        if(!found) {
            return false
        }
    }

    return true
}

fun main(args: Array<String>) {
    val (n, k) = nextInts(2)
    val seed = nextInts(k)
    val arrs = List(k) { nextInts(n / k) }

    if(checkSeedTeam(k, seed, arrs)) {
        println("\"MiaoW\"")
    } else {
        println("\\QAQ/")
    }
}
/*****************************************************************
 * 题目：[语言月赛 202401] 跳房子
 * 描述：有一个数组，每个元素表示跳的距离，问能否跳到最后一个格子，需要几步？
 * 思路：模拟。
 * 函数：hopscotch模拟跳房子。
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
 * 跳房子
 * 模拟跳房子，返回跳的步数。
 * 跳的规则：
 * 1. 从第一个格子开始跳。
 * 2. 每次跳的距离为当前格子的数字。
 * 3. 不能跳回之前的格子。
 * 4. 不能跳超过最后一个格子。
 * 5. 如果不能跳到最后一个格子，返回 -1。
 */
fun hopscotch(nums: List<Int>): Pair<Boolean, Int> {

    val n = nums.size
    var pos = 0
    var step = 0
    while (pos < n - 1) {
        val jump = nums[pos]
        if (jump == 0) return false to step
        pos += jump
        step++
    }

    if(pos == n - 1) return true to step
    else return false to step
}


fun main(args: Array<String>) {
    val n = nextInt()
    val nums = nextInts(n)

    val (canJump, step) = hopscotch(nums)
    if(canJump){
        println("Yes")
    }else{
        println("No")
    }
    println(step)
}
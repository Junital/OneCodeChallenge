/*****************************************************************
 * 题目：[语言月赛202303] Stone Gambling S
 * 描述：一个游戏，如果目前自己分数大于对方，就去除一半，否则加一分。
        问一方为0分时，双方的分数。
 * 思路：不太确定能否找规律，可以先模拟试一下。
 * 函数：stoneGambling
    * 描述：计算游戏结束时双方的分数。
    * 输入：Y,Z
    * 输出：游戏结束时双方的分数。
 * 注意：输入类型为Long。
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
 * 函数：stoneGambling
 * 描述：计算游戏结束时双方的分数。
 * 输入：Y,Z
 * 输出：游戏结束时双方的分数。
 * 注意：输入类型为Long。
 */
fun stoneGambling(Y: Long, Z: Long): Pair<Long, Long> {
    var (y, z) = Y to Z
    while (y > 0 && z > 0) {
        if(y >= z) {
            y /= 2
        } else {
            y++
        }

        if(y == 0L) {
            break
        }

        if(z >= y) {
            z /= 2
        } else {
            z++
        }
    }
    return y to z
}

fun main(args: Array<String>) {
    val queryNum = nextInt()
    repeat(queryNum) {
        val (y, z) = nextLongs(2)
        val (x, w) = stoneGambling(y, z)
        println("$x $w")
    }
}
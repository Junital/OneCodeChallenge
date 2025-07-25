/*****************************************************************
 * 题目：「NnOI R2-T1」Khronostasis Katharsis
 * 描述：不同气球的上升速度和运动时间不一样，问最后谁最高。
 * 思路：简单乘法+比较。
 * 空间：无。
 * 注意：无。
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

fun main(args: Array<String>) {
    val (num, endTime) = nextInts(2)
    var (maxIdx, maxHeight) = listOf(-1, -1)
    
    for(i in 1..num){
        val (v, t) = nextInts(2)
        val curHeight = maxOf(endTime - t, 0) * v

        if(curHeight > maxHeight){
            maxHeight = curHeight
            maxIdx = i
        }
    }

    println(maxIdx)
}
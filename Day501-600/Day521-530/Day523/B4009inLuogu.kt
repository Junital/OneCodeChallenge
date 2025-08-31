/*****************************************************************
 * 题目：[语言月赛 202407] value
 * 描述：判断是否满足平衡条件。
 * 思路：考虑多种情况。
 * 空间：无。
 * 注意：分母为零/无法整除。
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

/**
    判断情况
 */
fun judgeValid(denominator: Int, numerator: Int): Boolean{
    if(denominator == 0)
    {
        return numerator == 0
    }

    if(numerator == 0)
    {
        return denominator == 0
    }

    return numerator % denominator == 0
}

/**
    判断是否无敌
 */
fun judgeAny(denominator: Int, numerator: Int): Boolean{
    return denominator == 0 && numerator == 0
}

fun main(args: Array<String>) {
    val (x, y, z, w) = nextInts(4)

    if (judgeValid(z, x) && judgeValid(w, y)){
        if(judgeAny(z, x)){
            println(y / w)
        }else if(judgeAny(w, y)){
            println(x / z) 
        }else if(y /w == x / z){
            println(y / w)
        }else{
            println(-1)
        }
    }else{
        println(-1)
    }
}
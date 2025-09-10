/*****************************************************************
 * 题目：[GESP202312 三级] 单位转换
 * 描述：换算米、千米、毫米；千克、克、毫克。
 * 思路：根据字符串获取转换表达式，给出对应的结果。
 * 函数：transformUnits模拟单位转换。
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
 * 单位转换
 * 字符串形式：1 km = ? mm
 */
fun transformUnits(input: String): Int {
    val parts = input.split(" ")
    if (parts.size != 5 || parts[2] != "=" || parts[3] != "?") {
        return -1
    }
    val value = parts[0].toDoubleOrNull() ?: return -1
    val fromUnit = parts[1]
    val toUnit = parts[4]

    val lengthUnits = mapOf("mm" to 1, "cm" to 10, "m" to 1000, "km" to 1000000)
    val weightUnits = mapOf("mg" to 1, "g" to 1000, "kg" to 1000000)

    return when {
        fromUnit in lengthUnits && toUnit in lengthUnits -> {
            val inMeters = value * lengthUnits[fromUnit]!!
            val result = inMeters / lengthUnits[toUnit]!!
            result.toInt()

        }
        fromUnit in weightUnits && toUnit in weightUnits -> {
            val inGrams = value * weightUnits[fromUnit]!!
            val result = inGrams / weightUnits[toUnit]!!
            result.toInt()

        }
        else -> -1
    }
}

fun main(args: Array<String>) {
    val queryNum = readLine()?.toIntOrNull() ?: 0
    repeat(queryNum) {
        val input = readLine() ?: throw EOFException("No more input")
        val result = transformUnits(input)
        println(input.replace("?", result.toString()))
    }
}
/*****************************************************************
 * 题目：[GESP202412 一级] 温度转换
 * 描述：输入一个开尔文温度，输出对应的摄氏温度和华氏温度。
 * 思路：直接套公式计算。
 * 函数：kelvinToCelsius模拟开尔文温度转摄氏温度。
 * 注意：注意输出格式。
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
 * 开尔文温度转摄氏温度
 */
fun kelvinToCelsius(kelvin: Double): Double = kelvin - 273.15

/**
 * 开尔文温度转华氏温度
 */
fun kelvinToFahrenheit(kelvin: Double): Double = kelvinToCelsius(kelvin) * 9 / 5 + 32

fun main(args: Array<String>) {
    val kelvin = nextDouble()
    val celsius = kelvinToCelsius(kelvin)
    val fahrenheit = kelvinToFahrenheit(kelvin)

    if(fahrenheit > 212.0) {
        println("Temperature is too high!")
        return
    }

    println("%.2f %.2f".format(celsius, fahrenheit))
}
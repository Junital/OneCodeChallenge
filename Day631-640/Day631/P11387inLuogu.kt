/*****************************************************************
 * 题目：[COCI 2024/2025 #1] 身份证 / Osobna
 * 描述：第一行由 5 个字母，21 个数字和 4 个 < 组成。最后 11 位数字为校验码。
        第二行的前两位数字为出生年，特别地，若出生年 ≤24，则表示是在 21 世纪出生的；
        否则表示在 20 世纪出生的。
        第二行的出生年后两位数字表示出生月，出生月后两位数字表示出生日。
        第三行，先是持有人的名，接着是两个 <，再是持有者的姓，都是大写字母。
        如果不满 30 个字符，则用 < 填充。
 * 思路：直接按要求输出。
 * 函数：printId模拟格式化输出身份证。
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
 * 格式化输出身份证号。
 * @param id 身份证号，格式为 5 个字母，21 个数字，4 个 <，最后 11 位数字为校验码。
 * @param birth 出生年月，格式为 4 个数字，前两位为出生年，后两位为出生月。
 * @param name 持有人姓名，格式为 30 个字符，不足用 < 填充。
 */
fun printId(id: String, birth: String, name: String) {
    var (ime, prezime) = name.split("<<")

    /* 除了首字母外，其他字母都转换为小写 */
    ime = ime.first().uppercase() + ime.drop(1).lowercase()
    prezime = prezime.first().uppercase() + prezime.drop(1).lowercase()

    var god = birth.substring(0, 2)
    val mesec = birth.substring(2, 4)
    val dan = birth.substring(4, 6)
    if (god.toInt() <= 24) {
        god = "20$god"
    } else {
        god = "19$god"
    }
    val oib = id.substring(15, 26)
    println("Ime: $ime")
    println("Prezime: $prezime")
    println("Datum rodjenja: $dan-$mesec-$god")
    println("OIB: $oib")
}

fun main(args: Array<String>) {
    val id = next()
    val birth = next()
    val name = next()
    printId(id, birth, name)
}
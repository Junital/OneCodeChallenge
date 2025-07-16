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

class Calendar {
    private val num2Month: Map<Int, String>
    private val monthDay: Map<String, Int>
    
    init {
        // 初始化月份索引映射
        num2Month = mapOf(
            1 to "Jan",
            2 to "Feb", 
            3 to "Mar",
            4 to "Apr",
            5 to "May",
            6 to "Jun",
            7 to "Jul",
            8 to "Aug",
            9 to "Sep",
            10 to "Oct",
            11 to "Nov",
            12 to "Dec"
        )
        
        // 初始化每月天数映射
        monthDay = mapOf(
            "Jan" to 31,
            "Feb" to 28,
            "Mar" to 31,
            "Apr" to 30,
            "May" to 31,
            "Jun" to 30,
            "Jul" to 31,
            "Aug" to 31,
            "Sep" to 30,
            "Oct" to 31,
            "Nov" to 30,
            "Dec" to 31
        )
    }
    
    /**
     * 判断是否为闰年
     * 普通闰年：公历年份是4的倍数，且不是100的倍数的，为闰年（如2004年、2020年等就是闰年）。
     * 世纪闰年：公历年份是整百数的，必须是400的倍数才是闰年（如1900年不是闰年，2000年是闰年）。
     */
    private fun isLeap(year: Int): Boolean {
        return when {
            year % 400 == 0 -> true
            year % 100 == 0 -> false
            year % 4 == 0 -> true
            else -> false
        }
    }
    
    /**
     * 获取某年某月的天数
     */
    fun getDaysNum(year: Int, month: Int): Int {
        val monthName = num2Month[month] ?: throw IllegalArgumentException("Invalid month: $month")
        
        return if (monthName == "Feb" && isLeap(year)) {
            monthDay[monthName]!! + 1
        } else {
            monthDay[monthName]!!
        }
    }
}

fun main(args: Array<String>) {
    val calendar = Calendar()

    val (year, month) = nextInts(2)
    println(calendar.getDaysNum(year, month))
}
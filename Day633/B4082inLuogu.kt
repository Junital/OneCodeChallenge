/*****************************************************************
 * 题目：[语言月赛 202412] 古希腊掌管罚时的神
 * 描述：计算未通过次数 * 20 加上每次通过的时间。
 * 思路：直接公式计算。
 * 对象：PenaltyCalculator模拟罚时计算器。
 * 注意：有可能会溢出。
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
 * 模拟比赛日志
 */
data class MatchLog(
    val time: Int,
    val passOrNot: Boolean
)

/**
 * 模拟罚时计算器
 */
class PenaltyCalculator {
    private var penalty = 0L
    private var failCount = 0L
    private var lastPassTime = 0L

    fun addLog(log: MatchLog) {
        if (log.passOrNot) {
            penalty += log.time
        } else {
            failCount++
        }
    }

    fun addLogs(logs: List<MatchLog>) {
        logs.forEach { addLog(it) }
    }

    fun getPenalty(): Long = penalty + failCount * 20
}


fun main(args: Array<String>) {
    val n = nextInt()
    val logs = mutableListOf<MatchLog>()

    repeat(n) {
        val time = nextInt()
        val passOrNot = nextInt() == 1
        logs.add(MatchLog(time, passOrNot))
    }

    val calculator = PenaltyCalculator()
    calculator.addLogs(logs)
    println(calculator.getPenalty())
}
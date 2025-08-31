/*****************************************************************
 * 题目：角谷猜想
 * 描述：奇数，则乘三加一；偶数，除二。
 * 思路：模拟。
 * 对象：KakutaniConjecture模拟角谷猜想
 * 注意：可能会溢出，小心为妙。
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
 * 角谷猜想（Collatz）可视化及序列生成。
 *
 * @property start 起始值，必须 > 0
 */
class KakutaniConjecture(private val start: Long) {
    init {
        require(start > 0) { "起始值必须大于 0，但现在是 $start" }
    }

    /**
     * 打印从 start 到 1 的 Collatz 序列变化过程。
     */
    fun visualize() {
        val sequence = sequenceUntilOne()

        sequence.zipWithNext().forEach { (a, b) ->
            when {
                a % 2 == 0L -> println("$a/2=$b")
                else -> println("$a*3+1=$b")
            }
        }
        println("End")
    }

    /**
     * 返回 Collatz 序列直到 1，包括起始值和 1。
     */
    fun sequenceUntilOne(): List<Long> =
        generateSequence(start) { current ->
            when {
                current <= 1   -> null
                current % 2 == 0L -> current / 2
                else             -> current * 3 + 1
            }
        }.toList()
}

fun main(args: Array<String>) {
    val start = nextLong()
    val kc = KakutaniConjecture(start)
    kc.visualize()
}
/*****************************************************************
 * 题目：求正整数 2 和 n 之间的完全数
 * 描述：除了这个数本身，其他因数相加和这个数相等，就叫完全数。
 * 思路：将所有因数相加，得到这个数的两倍即可。
 * 空间：divisors模拟因数数组。
 * 注意：时间复杂度和溢出情况。
 ****************************************************************/

import kotlin.math.sqrt
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
* 枚举所有正因数。
*/
fun Int.divisors(): List<Int> {
    require(this > 0) { "Only positive integers are supported." }
    val n = this
    val limit = sqrt(n.toDouble()).toInt()
    return buildList {
        for (i in 1..limit) {
            if (n % i == 0) {
                add(i)
                val other = n / i
                if (other != i) add(other)
            }
        }
    }
}

/**
 * 计算所有正因数之和。
 */
fun Int.sumOfDivisors(): Int = divisors().sum()

fun main(args: Array<String>) {
    val start = 2
    val end = nextInt()

    for(i in start..end)
    {
        if(i.sumOfDivisors() == i * 2)
        {
            println(i)
        }
    }
}
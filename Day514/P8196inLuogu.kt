/*****************************************************************
 * 题目：[传智杯 #4 决赛] 三元组
 * 描述：一个数组中存在多少三元组（i,j,k）满足前两个元素相加等于第三个？
 * 思路：直接遍历。
 * 空间：无。
 * 注意：注意时间复杂度。
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

fun main(args: Array<String>) {
    val queryNum = nextInt()

    for(i in 1..queryNum)
    {
        val size = nextInt()
        val arr = MutableList(size) { nextInt() }
        var cnt = 0

        for(x in 0 until size)
        {
            for(y in x until size)
            {
                for(z in y + 1 until size)
                {
                    if(arr[x] + arr[y] == arr[z])
                    {
                        // println("$x $y $z")
                        cnt++
                    }
                }
            }
        }

        println(cnt)
    }
}
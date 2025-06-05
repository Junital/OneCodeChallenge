/*****************************************************************
 * 题目：[语言月赛 202412] 题目名没活了
 * 描述：根据提交记录，判断完成了几道题。
 * 思路：维护一个只增不减的数组。
 * 对象：SingleChangeArray模拟不可从true变成false的数组。
 * 注意：输入的格式。
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

class SingleChangeList(val capacity: Int){
    val array = MutableList<Boolean>(capacity){ false }

    fun change(idx: Int, value: Boolean)
    {
        if(value)
        {
            array[idx] = true
        }
    }

    fun countTrue(): Int
    {
        var cnt = 0
        for(i in array.indices)
        {
            if(array[i]){
                cnt++
            }
        }
        return cnt
    }
}

fun main(args: Array<String>) {
    val record_num = nextInt()
    val capacity = nextInt()

    val scl = SingleChangeList(capacity)
    repeat(record_num){
        val id = nextInt()
        val value = if (nextInt() == 1) true else false
        scl.change(id - 1, value)
    }

    println(scl.countTrue())
}
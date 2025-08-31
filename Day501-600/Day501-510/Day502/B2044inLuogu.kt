/*****************************************************************
 * 题目：有一门课不及格的学生
 * 描述：判断目前学生成绩是否只不及格一门。
 * 思路：用filter试试
 * 空间：无。
 * 注意：小心。
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
    val size = 3
    val passingLine = 60
    val scores = MutableList(size) {0}

    repeat(size) { i ->
        scores[i] = nextInt()
    }

    val failedSubjects = scores.filter { it < passingLine }

    if(failedSubjects.size == 1)
    {
        println(1)
    }else{
        println(0)
    }
}
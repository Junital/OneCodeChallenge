/*****************************************************************
 * 题目：最高分数的学生姓名
 * 描述：根据每个学生的成绩，输出最高分数的学生姓名。
 * 思路：构建
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

// 学生分数
data class StudentScore(val name: String, val score: Int) {}

fun main(args: Array<String>) {
    val stuNum = nextInt()
    val students = mutableListOf<StudentScore>()

    repeat(stuNum)
    {
        val score = nextInt()
        val name = next()

        students.add(StudentScore(name, score))
    }

    val maxStuScore = students.maxBy{ it.score }
    println(maxStuScore.name)
}
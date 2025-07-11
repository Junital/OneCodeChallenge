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

/**
 * 操作函数，输出所有可能的结果。
 */
fun <A, B, R> operate(
    setA: Collection<A>,
    setB: Collection<B>,
    functions: Collection<(A, B) -> R>
): List<R> {
    val results = mutableListOf<R>()
    for (a in setA) {
        for (b in setB) {
            for (f in functions) {
                results.add(f(a, b))
            }
        }
    }
    return results
}

fun main(args: Array<String>) {
    val (a, b, c, d) = nextInts(4)

    val functions = listOf<(Int, Int) -> Int>(
        { a, b -> a + b },
        { a, b -> a - b },
        { a, b -> a * b }
    )

    val results = operate(operate(listOf(a), listOf(b), functions), listOf(c), functions)

    if(d in results){
        println("Yes")
    }else{
        println("No")
    }
}
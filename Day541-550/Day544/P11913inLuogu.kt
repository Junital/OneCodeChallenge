/*****************************************************************
 * 题目：[PA 2025] 晋级者 / Finaliści
 * 描述：找出能进入决赛的所有选手。
 * 思路：直接判断。
 * 空间：无。
 * 注意：无。
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
    val playerNum = nextInt()
    val winners = mutableListOf<Int>()

    val firstPart = 10
    val secondPart = 20

    repeat(playerNum){ i ->
        val winInfo = next()
        val exper = nextInt()

        if(winInfo == "TAK"){
            if(winners.size < firstPart){
                winners.add(i + 1)
            }else if(winners.size < secondPart && exper < 2){
                winners.add(i + 1)
            }
        }
    }

    println(winners.joinToString(" "))
}
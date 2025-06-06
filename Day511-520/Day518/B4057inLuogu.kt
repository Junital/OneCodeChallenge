/*****************************************************************
 * 题目：[语言月赛 202411] Rise
 * 描述：管理花盆，会增长、也会裁剪。
 * 思路：模拟。
 * 空间：FlowersManagement模拟花朵管理。
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

/** 花朵管理 */
class FlowersManagement(val capacity: Int){
    private val flowers = MutableList<Int>(capacity) { 0 }

    fun water(left: Int, right: Int){
        for(i in left..right){
            flowers[i]++
        }
    }

    fun cut(left: Int, right: Int, threshold: Int): Int{
        var cnt = 0

        for(i in left..right){
            if(flowers[i] >= threshold)
            {
                cnt++
                flowers[i] = 0
            }
        }

        return cnt
    }
}

fun main(args: Array<String>) {
    val fm = FlowersManagement(nextInt())

    val opNum = nextInt()

    repeat(opNum){
        val opStr = next()

        if(opStr == "water"){
            val left = nextInt()
            val right = nextInt()

            fm.water(left - 1, right - 1)
        }else if(opStr == "rise"){
            val left = nextInt()
            val right = nextInt()
            val threshold = nextInt()

            println(fm.cut(left - 1, right - 1, threshold))
        }else{
            error("wrong op string!")
        }
    }
}
/*****************************************************************
 * 题目：[语言月赛 202501] 右箭头
 * 描述：自定义参数，画出剪头。
 * 思路：区分两个部分，分别处理。
 * 空间：RightArrow模拟右箭头。
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

/**
 * 右箭头
 */
class RightArrow(val height: Int, val length: Int, val barHeight: Int){
    
    val arrowLength = (height + 1) / 2
    val barLength = maxOf(length - arrowLength, 0)

    fun printAll()
    {
        val spaceHeight = (height - barHeight) / 2
        repeat(height){ row ->
            /* 打印横条 */
            if(row >= spaceHeight && row < height - spaceHeight){
                repeat(barLength){
                    print('#')
                }
            }else{
                repeat(barLength){
                    print('.')
                }
            }

            /* 打印箭头 */
            val arrowFill = if(row <= (height - 1) / 2) row + 1 else height - row

            repeat(arrowFill){
                print("#")
            }

            repeat(arrowLength - arrowFill){
                print(".")
            }
            println()
        }
    }
}

fun main(args: Array<String>) {
    val (height, length, barLength) = nextInts(3)

    val ra = RightArrow(height, length, barLength)

    ra.printAll()
}
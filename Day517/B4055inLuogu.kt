/*****************************************************************
 * 题目：[语言月赛 202411] Phoenix
 * 描述：找出所有比右边所有元素大的索引。
 * 思路：从右向左遍历。
 * 函数：largerThanRight模拟比右边大。
 * 注意：时间复杂度。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.max

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
 * 找到所有“比它右边所有元素都大”的元素索引。
 * 返回的索引列表是从左到右升序排列的。
 */
fun <T: Comparable<T>> List<T>.largerThanRight(): List<Int> {
    if (isEmpty()) return emptyList()
    // 先把最右边那个元素当做当前最大值
    var maxElement = last()
    val itEnd = lastIndex
    // 利用 buildList 构造一个 List<Int>
    val idxList = buildList<Int> {
        add(itEnd)

        // 从倒数第二个元素开始，向左遍历
        for (i in (0 until itEnd).reversed()) {
            val cur = this@largerThanRight[i]
            if (cur > maxElement) {
                add(i)
            }
            // 更新 maxElement：取二者更大者
            maxElement = maxOf(maxElement, cur)
        }
    }
    // 目前 idxList 中的索引顺序是从右向左（因为我们倒序遍历过），
    // 如果想要返回“从左到右”的自然顺序，需要再反转一下：
    return idxList.reversed()
}

fun main(args: Array<String>) {
    val size = nextInt()

    val arr = List<Int>(size) { nextInt() }

    println(arr.largerThanRight().size)
}

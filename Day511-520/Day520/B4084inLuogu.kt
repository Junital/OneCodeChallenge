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

/**
 * 单点更新型布尔列表：仅允许将某个索引置为 true，一旦为 true 不可还原为 false。
 * 具有快速计数和边界检查。
 *
 * @param capacity 列表长度，必须 >= 1
 */
class SingleChangeList(capacity: Int) {
    init {
        require(capacity >= 1) { "capacity must be at least 1" }
    }

    // 用 BooleanArray 存储，性能略高于 MutableList<Boolean>
    private val array = BooleanArray(capacity) { false }
    private var trueCount = 0  // 维护当前为 true 的个数

    /**
     * 将第 idx 位标记为 value(true)，如果此前已是 true，则不重复计数。
     * @param idx 要修改的索引
     * @param value 目标值，仅对 true 生效（设为 false 无效）
     */
    fun change(idx: Int, value: Boolean) {
        require(idx in array.indices) { "Index out of bounds: $idx" }
        if (value && !array[idx]) {
            array[idx] = true
            trueCount++
        }
        // 如果 value 为 false，或已经是 true，则保持不变
    }

    /**
     * 返回当前列表中为 true 的元素个数。
     * O(1) 时间，因为维护了 trueCount。
     */
    fun countTrue(): Int = trueCount

    /**
     * 获取指定索引的布尔值
     */
    operator fun get(idx: Int): Boolean {
        require(idx in array.indices) { "Index out of bounds: $idx" }
        return array[idx]
    }

    /**
     * （调试用）打印当前布尔列表
     */
    fun printState() {
        println(array.joinToString(", ") { if (it) "1" else "0" })
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
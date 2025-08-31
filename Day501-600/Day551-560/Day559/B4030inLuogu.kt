/*****************************************************************
 * 题目：[语言月赛 202409] 距离
 * 描述：问每次事件后，所有人心动值的最大值。
 * 思路：用HashMap模拟。
 * 对象：MaxTrackerRelative模拟最大值跟踪器。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import java.util.TreeMap

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

class MaxTrackerRelative<A, B> {
    private val map = HashMap<Pair<A, B>, Int>()      // 存每个 key 的当前值
    private val count = TreeMap<Int, Int>()          // 存值到出现次数的映射

    /**
     * 对 (keyA, keyB) 的值做 +delta 操作，返回更新后的全局最大值
     */
    fun adjust(keyA: A, keyB: B, delta: Int): Int {
        val key = Pair(keyA, keyB)
        // 1) 取旧值（新 key 默认为 0）
        val oldVal = map.getOrDefault(key, 0)

        // 2) 在 count 中把旧值的计数 -1（减到 0 就移除）
        count.computeIfPresent(oldVal) { _, c ->
            if (c <= 1) null else c - 1
        }

        // 3) 计算新值并写回 map，同时在 count 中 +1
        val newVal = oldVal + delta
        map[key] = newVal
        count.merge(newVal, 1) { a, b -> a + b }

        // 4) 直接返回当前最大值
        return count.lastKey()
    }

    /** 如果需要随时单独 peek 最大值，也可以提供： */
    fun currentMax(): Int? = count.lastKey()
}

fun main(args: Array<String>) {
    val tracker = MaxTrackerRelative<Int, Int>()
    val(studentNum, eventNum) = nextInts(2)

    repeat(eventNum) {
        val (op, stuA, stuB, delta) = nextInts(4)

        if(op == 1){
            println(tracker.adjust(stuA, stuB, delta))
        }else{
            println(tracker.adjust(stuA, stuB, -delta))
        }
    }
}
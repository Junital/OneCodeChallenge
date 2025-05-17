/*****************************************************************
 * 题目：分糖果
 * 描述：每个小朋友将糖果分成三份，自己吃掉多的那一份，剩下两份给旁边的小朋友。
 * 思路：模拟。
 * 对象：ShareCandies模拟分享糖果。
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
 * 把 Pair<A,B> 转成 "$first<sep>$second" 的字符串
 */
fun <A, B> Pair<A, B>.joinToString(
    separator: CharSequence = ", "
): String = listOf(first, second)
    .joinToString(separator) { it.toString() }



/**
 * 模拟在环形队列中，朋友们相互分享糖果的模型。
 * 每位朋友将自己拥有的糖果分为三份：
 *  - 给左侧一份
 *  - 给自己一份
 *  - 给右侧一份
 * 多余（对3取余）的糖果由他本人独享并计算在本轮消耗中。
 *
 * @param capacity 环上朋友的数量 (>=1)
 */
class ShareCandies(capacity: Int) {
    init {
        require(capacity >= 1) { "capacity must be at least 1" }
    }

    // 底层用 MutableList 记录各位朋友手中的糖果数，初始为 0
    private val friends = MutableList(capacity) { 0 }

    /** 环形大小，即朋友总数 */
    val size: Int get() = friends.size

    /** 判断所有朋友是否都没有糖果 */
    fun isEmpty(): Boolean = friends.all { it == 0 }

    /**
     * 为第 idx 位朋友设置初始糖果数
     * @param idx 索引，从 0 到 size-1
     * @param candies 非负糖果数
     */
    fun add(idx: Int, candies: Int) {
        require(idx in 0 until size) { "Index out of bounds: $idx" }
        require(candies >= 0) { "Candies must be non-negative" }
        friends[idx] = candies
    }

    /**
     * 进行一轮分享：每位朋友将糖果分成 3 份给左右和自己，
     * 将多余糖果（mod 3 部分）累加为本轮个人消耗。
     * @return 本轮所有朋友消耗的糖果总数
     */
    fun shareAround(): Int {
        if (isEmpty()) return 0

        val remainders = mutableListOf<Int>()

        for (i in friends.indices) {
            val portion = friends[i] / 3
            val left = (i - 1).mod(size)
            val right = (i + 1).mod(size)

            remainders.add(friends[i] % 3)

            friends[left] += portion
            friends[i] = portion
            friends[right] += portion
        }

        // 4) 返回所有余数之和（本轮消耗）
        return remainders.sum()
    }

    /**
     * 获取当前糖果分布快照（返回不可变 List）
     */
    fun currentDistribution(): List<Int> = friends.toList()
}

 

fun main(args: Array<String>) 
{
    val size = 5
    val sc = ShareCandies(size)

    repeat(size)
    {
        val element = nextInt()
        sc.add(it, element)
    }

    val eaten = sc.shareAround()

    println(sc.currentDistribution().joinToString(" "))
    println(eaten)
}
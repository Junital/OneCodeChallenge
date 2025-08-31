/*****************************************************************
 * 题目：T2 点亮灯笼
 * 描述：点一盏灯笼，会连带点相邻两盏灯笼。
 * 思路：封装一个环形灯笼对象。
 * 空间：LanternRing模拟灯笼环。
 * 注意：加快代码速度。
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
 * 灯笼环：每次点亮/熄灭指定灯及其左右两侧相邻的灯
 * @param capacity 灯的总数，必须 >= 1
 */
class LanternRing(capacity: Int) {
    init {
        require(capacity >= 1) { "capacity must be at least 1" }
    }

    // 灯的状态列表，true 表示亮，false 表示灭
    private val isOn = MutableList(capacity) { false }

    /** 灯的总数 */
    val size: Int
        get() = isOn.size

    /** 切换第 idx 号灯的状态 */
    private fun toggle(idx: Int) {
        isOn[idx.mod(size)] = !isOn[idx.mod(size)]
    }

    /**
     * 点亮/熄灭第 idx 号灯及其左右相邻的灯
     * @param idx 索引，可为任意整数，将按环状取模
     */
    fun lightOn(idx: Int) {
        val i = idx.mod(size)
        toggle(i)
        toggle((i - 1).mod(size))
        toggle((i + 1).mod(size))
    }

    /** 打印当前所有灯的状态，亮=true, 灭=false */
    fun printState() {
        println(isOn.joinToString(" ") { if (it) "1" else "0" })
    }
}

fun main(args: Array<String>) {
    val ring = LanternRing(nextInt())
    val queryNum = nextInt()

    repeat(queryNum)
    {
        val idx = nextInt()
        ring.lightOn(idx - 1)
    }

    ring.printState()
}
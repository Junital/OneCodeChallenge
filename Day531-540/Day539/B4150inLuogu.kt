/*****************************************************************
 * 题目：[厦门小学生 C++ 2022] 打车收费
 * 描述：不同价位收的打车费不一样。
 * 思路：构造收费者。
 * 对象：TaxiFare模拟打车费。
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
 * 单段费率：适用于“超过上限里程 upTo（含）”以内，按 ratePerKm 收费
 * - upTo == null 表示无上限（即最后一段）
 */
data class RateSegment(
    val upTo: Int?,        // 里程上限（包含），单位：公里；null 表示无上限
    val ratePerKm: Int     // 每公里单价，单位：元
)

/**
 * 计费策略接口，任何不同城市／车辆的计费规则都可以实现这个接口
 */
interface FarePolicy {
    /**
     * @param distance 乘车里程，单位：公里
     * @return 车费（元）
     */
    fun calculate(distance: Int): Int
}

/**
 * 通用出租车计费器
 * - 起步价 baseFare（单位：元）；
 * - segments 按里程分段的单价表，必须按 upTo 升序排列，最后一段 upTo == null
 */
class TaxiFareCalculator(
    private val baseFare: Int,
    private val segments: List<RateSegment>
) : FarePolicy {

    init {
        require(segments.isNotEmpty()) { "至少要有一个费率段" }
        // 保证 upTo 升序，且最后一段 upTo 为 null
        val ups = segments.map { it.upTo ?: Int.MAX_VALUE }
        require(ups == ups.sorted()) { "segments 必须按 upTo 升序排列" }
        require(segments.last().upTo == null) { "最后一段必须是无上限段（upTo = null）" }
    }

    override fun calculate(distance: Int): Int {
        require(distance >= 0) { "里程不能为负数" }
        if (distance == 0) return 0

        // 起步里程内（第 1 段）直接返回 baseFare
        val firstLimit = segments.first().upTo ?: Int.MAX_VALUE
        if (distance <= firstLimit) {
            return baseFare
        }

        // 已用掉第一段的里程
        var remaining = distance - firstLimit
        var fare = baseFare

        // 从第二段开始收费
        for (seg in segments.drop(1)) {
            val segLimit = seg.upTo?.let { it - firstLimit } ?: Int.MAX_VALUE
            val use = minOf(remaining, segLimit)
            fare += use * seg.ratePerKm
            remaining -= use
            if (remaining <= 0) break
        }
        return fare
    }
}

// 厦门市标准
val xiamenTexiPolicy = TaxiFareCalculator(
    baseFare = 10,
    segments = listOf(
        // 3 公里内：起步价
        RateSegment(upTo = 3, ratePerKm = 0),

        // 超过 3 公里至 8 公里：3 元/公里
        RateSegment(upTo = 8, ratePerKm = 3),

        // 超过 8 公里以上：5 元/公里
        RateSegment(upTo = null, ratePerKm = 5)
    )
)

fun main(args: Array<String>) {
    val km = nextInt()

    println(xiamenTexiPolicy.calculate(km))
}
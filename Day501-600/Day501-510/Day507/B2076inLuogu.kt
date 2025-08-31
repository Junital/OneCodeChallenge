/*****************************************************************
 * 题目：球弹跳高度的计算
 * 描述：每次球落地会反弹原来的一半，问10次反弹后经过的路程和反弹的高度。
 * 思路：模拟。
 * 空间：ElasticRebound弹性反弹。
 * 注意：控制精度。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.pow

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
 * 模拟小球弹性碰撞 rebound 相关计算。
 *
 * @param elasticCoef 弹性系数 r，范围应在 [0.0, 1.0]
 */
class ElasticRebound(val elasticCoef: Double) {
    init {
        require(elasticCoef in 0.0..1.0) { "The elastic coefficient elasticCoef must be in the range of [0.0, 1.0]. Currently: $elasticCoef" }
    }

    /**
     * 计算第 n 次反弹后的高度：h_n = initHeight * (elasticCoef^n)
     * @param initHeight 初始高度（>= 0）
     * @param bounceCount 反弹次数 n（>= 0）
     * @return 第 n 次反弹的高度
     */
    fun reboundHeight(initHeight: Double, bounceCount: Int): Double {
        require(initHeight >= 0) { "The initial height initHeight must be >= 0, current: $initHeight" }
        require(bounceCount >= 0) { "The number of bounces bounceCount must be >= 0, current: $bounceCount" }
        // 直接使用幂运算
        return initHeight * elasticCoef.pow(bounceCount)
    }

    /**
     * 计算经过 n 次反弹后，小球共运动的总路程。
     * 运动轨迹：从 initHeight 自由落体至地面，然后弹起至 reboundHeight(initHeight,1)，再落下，再弹起...
     * 路程 = initHeight + 2*sum_{i=1..bounceCount} (initHeight * r^i)
     * @param initHeight 初始高度（>= 0）
     * @param bounceCount 反弹次数 n（>= 0）
     * @return 总运动路程
     */
    fun totalPath(initHeight: Double, bounceCount: Int): Double {
        require(initHeight >= 0) { "The initial height initHeight must be >= 0, current: $initHeight" }
        require(bounceCount >= 0) { "The number of bounces bounceCount must be >= 0, current: $bounceCount" }
        if (bounceCount == 0) return initHeight
        // 几何级数求和：sum_{i=1..n} r^i = (r*(1 - r^n)) / (1 - r)
        val r = elasticCoef
        val geometricSum = if (r == 1.0) 0.0 else (r * (1 - r.pow(bounceCount - 1))) / (1 - r)
        // 总路程 = initHeight + 2 * initHeight * geometricSum
        return initHeight + 2 * initHeight * geometricSum
    }
}

fun main(args: Array<String>) {
    val er = ElasticRebound(elasticCoef = 0.5)
    val n = 10
    val initH = nextDouble()

    println(er.totalPath(initH, n))
    println(er.reboundHeight(initH, n))
}
/*****************************************************************
 * 题目：[语言月赛 202308] 小粉兔喜欢下象棋吗
 * 描述：给出棋盘中红帅、红车、黑马的位置，问黑马能否将军抽车。
 * 思路：遍历所有马可以到达的位置，判断是否将军抽车。
 * 类：Horse模拟马。
 * 注意：无。
 ****************************************************************/

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.EOFException
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

/**
 * 批量读取 n 个 String，返回 List<String>
 * 可以和解构声明一起使用：
 * val (x,y,z,w) = nextStrings(4)
 */
fun nextStrings(n: Int): List<String> = List(n) { next() }

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

// 读取n个Double
fun nextDoubles(n: Int): List<Double> = List(n) { nextDouble() }

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
 * 坐标类
 * @param x 横坐标
 * @param y 纵坐标
 */
data class Point(val x: Int, val y: Int) {
}

/**
 * 马类
 * @param x 横坐标
 * @param y 纵坐标
 * @param board 棋盘
 */
data class Horse(val x: Int, val y: Int) {
    /**
     * 计算马可以到达的位置
     */
    fun reachablePoints(): List<Point> {
        val points =  listOf(

            Point(x + 2, y + 1),
            Point(x + 2, y - 1),
            Point(x - 2, y + 1),
            Point(x - 2, y - 1),
            Point(x + 1, y + 2),
            Point(x + 1, y - 2),
            Point(x - 1, y + 2),
            Point(x - 1, y - 2),
        )

        // 得过滤 行在1~10 列在1~9
        return points.filter { it.x in 1..10 && it.y in 1..9 }
    }

    /**
     * 判断马是否可以到达某个位置
     * @param point 目标位置
     * @return 是否可以到达
     */
    fun canReach(point: Point): Boolean {
        return point in reachablePoints()
    }
}

fun main(args: Array<String>) {
    // 红帅
    val (x1, y1) = nextInts(2)
    // 红车
    val (x2, y2) = nextInts(2)
    // 黑马
    val (x3, y3) = nextInts(2)

    val king = Point(x1, y1)
    val car = Point(x2, y2)
    val horse = Horse(x3, y3)

    // 马可以到达的位置
    val reachablePoints = horse.reachablePoints()

    // flag
    var flag = false

    for (point in reachablePoints) {
        val newHorse = Horse(point.x, point.y)

        if(newHorse.canReach(king) && newHorse.canReach(car)) {
            flag = true
            break
        }
    }

    if(flag) {
        println("Yes")
    } else {
        println("No")
    }
}
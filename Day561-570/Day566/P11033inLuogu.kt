/*****************************************************************
 * 题目：【MX-X3-T0】「RiOI-4」宾果游戏
 * 描述：判断目前棋盘是否有五子连珠。
 * 思路：直接判断。
 * 函数：hasFiveInARow判断是否五子连珠。
 * 注意：提高可拓展性。
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

/**
 * 检查 5×5 棋盘是否有五子连珠
 * @param board 5×5 的 Int 数组，0 = 空, 1 = 黑, 2 = 白
 * @return 如果存在任意颜色的 5 子连珠，则返回 true，否则 false
 */
fun hasFiveInARow(board: List<List<Int>>): Boolean {
    val n = 5
    // 四个方向：右 (0,1)，下 (1,0)，右下 (1,1)，右上 (-1,1)
    val dirs = listOf(Pair(0,1), Pair(1,0), Pair(1,1), Pair(-1,1))
    
    for (i in 0 until n) {
        for (j in 0 until n) {
            val color = board[i][j]
            if (color == 0) continue  // 空格跳过
            // 对四个方向分别探测
            for ((dx, dy) in dirs) {
                var count = 1
                var x = i
                var y = j
                // 再往当前方向走 4 步
                repeat(4) {
                    x += dx
                    y += dy
                    // 越界或颜色不一致则中断
                    if (x !in 0 until n || y !in 0 until n || board[x][y] != color) {
                        return@repeat
                    }
                    count++
                }
                if (count == 5) {
                    // 找到五子，立即返回
                    return true
                }
            }
        }
    }
    return false
}

fun main(args: Array<String>) {
    val board = listOf(
        nextInts(5),
        nextInts(5),
        nextInts(5),
        nextInts(5),
        nextInts(5)
    )

    if(hasFiveInARow(board)) {
        println("Yes")
    }else {
        println("No")
    }
}
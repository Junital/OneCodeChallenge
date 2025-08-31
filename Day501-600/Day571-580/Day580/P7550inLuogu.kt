/*****************************************************************
 * 题目：[COCI 2020/2021 #6] Bold
 * 描述：将. #组成的矩阵加粗，每个#向右下方拓展2x2个#。
 * 思路：使用二维数组模拟矩阵，遍历每个#，将其向右下方拓展。
 * 函数：bold模拟加粗过程。
 * 注意：不能在原矩阵直接编辑，不然会永远是#。
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
 * 加粗函数
 */
fun bold(i: Int, j: Int, h: Int, w: Int, boldedMatrix: Array<Array<Char>>) {
    for (x in i..i+1) {
        for (y in j..j+1) {
            if (x < h && y < w) {
                boldedMatrix[x][y] = '#'
            }
        }
    }
}

fun main(args: Array<String>) {
    val (h, w) = nextInts(2)

    val matrix = Array(h) { next() }
    val boldedMatrix = Array(h) { Array(w) { '.' } }

    for (i in 0 until h) {
        for (j in 0 until w) {
            if (matrix[i][j] == '#') {
                bold(i, j, h, w, boldedMatrix)
            }
        }
    }

    for (i in 0 until h) {
        for (j in 0 until w) {
            print(boldedMatrix[i][j])
        }
        println()
    }
}
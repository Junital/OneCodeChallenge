/*****************************************************************
 * 题目：「KDOI-06-J」ION 比赛
 * 描述：根据目前的情况，判断去答哪些题，获得几个测试点来达到要求。
 * 思路：逐一判断。
 * 数据：Problem模拟问题。
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
 * 向上整除：a / b，如果有余数则结果再加 1
 */
fun Int.divUp(b: Int): Int =
    this / b + if (this % b != 0) 1 else 0

/**
 * 每个问题分数及答题情况。
 */
data class Problem(val checkpoints: Int, val passNum: Int){
    val fullScore = 100

    // 获取已经取得的分数
    fun getScore(): Int{
        return fullScore / checkpoints * passNum
    }

    // 获取需要继续答几题来到达目标分数，如果为-1就是到达不了。
    fun furtherAnswerNum(goal: Int): Int{
        val perScore = fullScore / checkpoints

        if((checkpoints - passNum) * perScore < goal)
        {
            return -1
        }

        return goal.divUp(perScore)
    }
}

fun main(args: Array<String>) {
    val problemNum = nextInt()
    val problems = mutableListOf<Problem>()
    var currentScore = 0

    repeat(problemNum){
        val problem = Problem(nextInt(), nextInt())
        problems.add(problem)
        currentScore += problem.getScore()
    }

    val goalScore = nextInt()

    if(currentScore >= goalScore){
        println("Already Au.")
    }else{
        repeat(problemNum){ i ->
            val moreCheckpoints = problems[i].furtherAnswerNum(goalScore - currentScore)

            if(moreCheckpoints == -1){
                println("NaN")
            }else{
                println(moreCheckpoints)
            }
        }
    }
}
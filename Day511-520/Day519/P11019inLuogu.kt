/*****************************************************************
 * 题目：「LAOI-6」[太阳]] 请使用最新版手机 QQ 体验新功能
 * 描述：将QQ表情字符串转化为代码。
 * 思路：提取大写的首字母，转化小写字符串。
 * 函数：QQEmoji模拟QQ表情。
 * 注意：注意可拓展性。
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

/** 表情字符串 */
fun QQEmoji(emojiStr: String): String{
    return buildString{
        append("/")
        for(ch in emojiStr){
            if(ch.isUpperCase()){
                append(ch.lowercase())
            }
        }
    }
}

fun main(args: Array<String>) {
    val input = readLine() ?: ""

    val regex = """
        ^                      # 从行首开始
        \[                     # 一个左方括号
        (                      # 捕获组1：一个或多个“首大写+小写”单词
            [A-Z][a-z]+        #   首字母大写，后跟至少一个小写字母，表示一个英文单词
            (?:[A-Z][a-z]+)*   #   紧跟 0 次或多次的 “大写开头的单词”
        )
        \]\]                   # 两个右方括号
        QingShiYongZuiXinBanShouJiQQTiYanXinGongNeng  # 固定 Pinyin 字符串
        $                      # 行尾
    """.trimIndent().toRegex(RegexOption.COMMENTS)

    val match = regex.matchEntire(input)
        ?: error("输入格式不对，示例：[AaaBbbCcc......]]QingShiYongZuiXinBanShouJiQQTiYanXinGongNeng")

    val (emojiStr) = match.destructured

    println(QQEmoji(emojiStr))
}
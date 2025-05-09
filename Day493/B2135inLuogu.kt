/*****************************************************************
 * 题目：单词替换
 * 描述：将字符串中的单词进行替换。
 * 思路：正则表达式替换。
 * 空间：replaceWord为替换单词。
 * 注意：输入格式。
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
 * 将字符串中的整词（whole word）替换为指定内容。
 * 匹配使用单词边界（\b），避免替换到子串。
 *
 * @param word 待替换的单词（不支持正则）
 * @param replacement 替换为的字符串
 * @param ignoreCase 是否忽略大小写，默认为 false
 * @return 替换后的新字符串
 */
fun String.replaceWord(
    word: String,
    replacement: String,
    ignoreCase: Boolean = false
): String {
    if (word.isEmpty()) return this  // 空单词不做处理
    // 构造正则：\bword\b，并对 word 做转义
    val pattern = "\\b${Regex.escape(word)}\\b"
    val options = if (ignoreCase) setOf(RegexOption.IGNORE_CASE) else emptySet()
    return this.replace(Regex(pattern, options), replacement)
}

fun main(args: Array<String>) {
    val str = readLine() ?: ""
    val word = readLine() ?: ""
    val replacement = readLine() ?: ""

    println(str.replaceWord(word, replacement))
}
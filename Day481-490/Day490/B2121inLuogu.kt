/*****************************************************************
 * 题目：最长最短单词
 * 描述：输出句子中第一个最长的单词和第一个最短的单词。
 * 思路：正则表达式划分。
 * 函数：splitWords模拟切分单词。
 * 注意：输出格式。
 ****************************************************************/

fun String.splitWords(): List<String> =
    split("""[^A-Za-z]+""".toRegex()).filter(String::isNotBlank)

fun main(args: Array<String>) {
    val str = readLine() ?: ""

    val words = str.splitWords()

    println(words.maxBy { it.length })
    println(words.minBy { it.length })
}
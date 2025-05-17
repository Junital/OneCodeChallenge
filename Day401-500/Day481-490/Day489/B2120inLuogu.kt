/*****************************************************************
 * 题目：单词的长度
 * 描述：输入一连串单词序列，要求输出所有单词的长度。
 * 思路：划分再输出。
 * 空间：无。
 * 注意：输出格式。
 ****************************************************************/

fun String.splitWords(): List<String> =
    split("""\s+""".toRegex()).filter(String::isNotBlank)

fun main(args: Array<String>) {
    val str = readLine() ?: ""

    
    val words = str.splitWords()
    val word_lens = mutableListOf<Int>()

    for(word in words)
    {
        word_lens.add(word.length)
    }

    println(word_lens.joinToString(","))
}
package com.Junital.utils

/* 凯撒密码。 */
fun String.caesar_decode(offset: Int): String
{
    val letter_count = 'z' - 'a' + 1
    var res = ""

    return buildString(this.length) {
        for (ch in this@caesar_decode) {
            when {
                ch in 'a'..'z' -> {
                    // 解码：加上偏移；为了避免负数先加上 letter_count
                    val decoded = (((ch - 'a' + offset) % letter_count + letter_count) % letter_count) + 'a'.code
                    append(decoded.toChar())
                }
                ch in 'A'..'Z' -> {
                    // 同理处理大写
                    val decoded = (((ch - 'A' + offset) % letter_count + letter_count) % letter_count) + 'A'.code
                    append(decoded.toChar())
                }
                else -> {
                    // 其他字符不变
                    append(ch)
                }
            }
        }
    }
}

/* 大小写互换 */
fun String.swap_case(): String
{
    return buildString(this.length) {
        for (ch in this@swap_case) {
            when {
                ch in 'a'..'z' -> {
                    val swapped = ch - 'a' + 'A'.code
                    append(swapped.toChar())
                }
                ch in 'A'..'Z' -> {
                    val swapped = ch - 'A' + 'a'.code
                    append(swapped.toChar())
                }
                else -> {
                    // 其他字符不变
                    append(ch)
                }
            }
        }
    }
}

/* 切分单词 */
fun String.splitWords(): List<String> =
    split("""[^A-Za-z]+""".toRegex()).filter(String::isNotBlank)

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
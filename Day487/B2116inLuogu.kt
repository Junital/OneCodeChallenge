/*****************************************************************
 * 题目：加密的病历单
 * 描述：对字符串进行解密
 * 思路：设计字符串拓展。
 * 空间：StringUtils模拟字符串工具包。
 * 注意：输入输出格式。
 ****************************************************************/


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


fun main(args: Array<String>) {
    var s = readLine() ?: ""
    s = s.swap_case()
    s = s.reversed()
    s = s.caesar_decode(3);
    println(s)
}
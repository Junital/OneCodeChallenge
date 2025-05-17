/*****************************************************************
 * 题目：验证子串
 * 描述：输入两个字符串，验证其中一个串是否为另一个串的子串。
 * 思路：内置contains函数。
 * 空间：无
 * 注意：输出格式，还要互相判断。
 ****************************************************************/

fun main(args: Array<String>) {
    val str1 = readLine() ?: ""
    val str2 = readLine() ?: ""

    if(str1.contains(str2))
    {
        println("${str2} is substring of ${str1}")
    }else if(str2.contains(str1))
    {
        println("${str1} is substring of ${str2}")
    }else
    {
        println("No substring")
    }
}
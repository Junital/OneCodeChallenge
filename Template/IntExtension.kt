package com.Junital.utils

/**
* 枚举所有正因数。
*/
fun Int.divisors(): List<Int> {
    require(this > 0) { "Only positive integers are supported." }
    val n = this
    val limit = sqrt(n.toDouble()).toInt()
    return buildList {
        for (i in 1..limit) {
            if (n % i == 0) {
                add(i)
                val other = n / i
                if (other != i) add(other)
            }
        }
    }
}

/**
 * 计算所有正因数之和。
 */
fun Int.sumOfDivisors(): Int = divisors().sum()

/**
 * 将整型拆成数字字符数组。
 */
fun Int.toDigitList(): List<Int> =
    this.absoluteValue.toString().map { it - '0' }

/**
 * 向上整除：a / b，如果有余数则结果再加 1
 */
fun Int.divUp(b: Int): Int =
    this / b + if (this % b != 0) 1 else 0

/**
 * 对Int进行除法，输出商的小数部分的数字数组。
 */
fun Int.fractionalDigits(divisor: Int, vararg positions: Int): List<Int> {
    val digits =  buildList {
        var remainder = this@fractionalDigits % divisor

        repeat(positions.maxOrNull() ?: 0){
            remainder *= 10
            add(remainder / divisor)
            remainder %= divisor
        }
    }

    return positions.map { pos ->
        digits[pos - 1]
    }
}
/*****************************************************************
 * 题目：第 n 小的质数
 * 描述：输出第n小的质数。
 * 思路：通过线性筛先输出一个质数数组，之后再通过索引找到。
 * 函数：getNPrimes返回N个从小到大的素数。
 * 注意：
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

/**
 * 线性筛，返回 [2..n] 范围内所有素数（升序）。
 */
fun linearSieve(n: Int): List<Int> {
    require(n >= 2) { "n must be ≥2" }
    val isComposite = BooleanArray(n + 1)
    val primes = mutableListOf<Int>()
    for (i in 2..n) {
        if (!isComposite[i]) {
            primes.add(i)
        }
        // 用已经找到的小素数去“筛”i * p
        for (p in primes) {
            val x = i * p
            if (x > n) break
            isComposite[x] = true
            // 保证每个合数只被 p 最小的那个素因子标记一次
            if (i % p == 0) break
        }
    }
    return primes
}

/**
 * 获取N个素数
 */
fun getNPrimes(n: Int): List<Int> {
    require(n >= 0) { "n must be >= 0" }
    if (n == 0) return emptyList()

    // 预估上界：当 n >= 6 时，可以用 n*(log n + log log n);
    // 这里简单取 n* (ln n + ln ln n) + 3*n，向上取整
    val m = when {
        n < 6    -> 15
        else     -> (n * (kotlin.math.ln(n.toDouble()) + kotlin.math.ln(kotlin.math.ln(n.toDouble()))) + 3 * n).toInt()
    }

    return linearSieve(m).subList(0, n)
}

fun main(args: Array<String>) {
    val n = nextInt()
    val primes = getNPrimes(n)

    println(primes[primes.size - 1])
}
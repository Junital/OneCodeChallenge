/*****************************************************************
 * 题目：判决素数个数
 * 描述：判断区间内的素数个数。
 * 思路：求出区间内素数数组的长度。
 * 空间：primesInRange获取区间内的素数。
 * 注意：区间开闭情况。
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
 * 获取区间 L..R 内的所有素数。
 */
fun primesInRange(L: Int, R: Int): List<Int> {
    require(L <= R) { "The interval is illegal" }
    if (R < 2) return emptyList()
    val all = linearSieve(R)
    // 只保留 >= L
    return all.filter { it >= L }
}

fun main(args: Array<String>)
{
    var L = nextInt()
    var R = nextInt()

    // 太坏了，居然没给L R设大小
    if (L > R)
    {
        L = R.also{R = L}
    }

    println(primesInRange(L, R).size)
}
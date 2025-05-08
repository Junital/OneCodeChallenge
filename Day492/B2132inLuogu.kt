/*****************************************************************
 * 题目：素数对
 * 描述：求出区间内所有相差为2的素数对。
 * 思路：线性筛
 * 函数：primesInRange获取区间内的素数。
 * 注意：没有结果的情况。
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
 * 获取区间 [L..R] 内的所有素数。
 */
fun primesInRange(L: Int, R: Int): List<Int> {
    require(L <= R) { "The interval is illegal" }
    if (R < 2) return emptyList()
    val all = linearSieve(R)
    // 只保留 >= L
    return all.filter { it >= L }
}

/**
 * 把 Pair<A,B> 转成 "$first<sep>$second" 的字符串
 */
fun <A, B> Pair<A, B>.joinToString(
    separator: CharSequence = ", "
): String = listOf(first, second)
    .joinToString(separator) { it.toString() }

fun main(args: Array<String>) {
    val N = nextInt()
    val primes = linearSieve(N)
    val pairs = mutableListOf<Pair<Int, Int>>()

    for(i in 1 until primes.size)
    {
        if(primes[i] - primes[i - 1] == 2)
        {
            pairs.add(primes[i - 1] to primes[i])
        }
    }

    if(pairs.size != 0)
    {
        for(p in pairs)
        {
            println(p.joinToString(" "))
        }
    }
    else
    {
        println("empty")
    }
}
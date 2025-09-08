package com.Junital.utils

/**
 * 构造List索引函数。
 */
operator fun <T> List<T>.get(idx: Int, fromRight: Boolean = false): T {
    return if (!fromRight) this[idx]
           else this[this.lastIndex - idx]
}

/**
 * 操作函数，输出所有可能的结果。
 */
fun <A, B, R> operate(
    setA: Collection<A>,
    setB: Collection<B>,
    functions: Collection<(A, B) -> R>
): List<R> {
    val results = mutableListOf<R>()
    for (a in setA) {
        for (b in setB) {
            for (f in functions) {
                results.add(f(a, b))
            }
        }
    }
    return results
}

/**
 * 循环数组
 */
class CircularArray<T>(private val array: Array<T>) {
    private val n = array.size
    private var index = 0
    private var head = 0
    fun init() {
        index = 0
    }

    fun next() {
        index = (index + 1) % n
    }
    fun get() = array[index]
    fun getByIdx(idx: Int) = array[(head + idx) % n]

    fun print() {
        for (i in 0 until n) {
            print("${getByIdx(i)} ")
        }
        println()
    }

    fun rotate() {
        head = (head - 1 + n) % n
        index = head
    }
}
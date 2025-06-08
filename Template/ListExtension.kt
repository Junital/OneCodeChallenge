package com.Junital.utils

/**
 * 构造List索引函数。
 */
operator fun <T> List<T>.get(idx: Int, fromRight: Boolean = false): T {
    return if (!fromRight) this[idx]
           else this[this.lastIndex - idx]
}

/**
 * 找到所有“比它右边所有元素都大”的元素索引。
 * 返回的索引列表是从左到右升序排列的。
 */
fun <T: Comparable<T>> List<T>.largerThanRight(): List<Int> {
    if (isEmpty()) return emptyList()
    // 先把最右边那个元素当做当前最大值
    var maxElement = last()
    val itEnd = lastIndex
    // 利用 buildList 构造一个 List<Int>
    val idxList = buildList<Int> {
        add(itEnd)

        // 从倒数第二个元素开始，向左遍历
        for (i in (0 until itEnd).reversed()) {
            val cur = this@largerThanRight[i]
            if (cur > maxElement) {
                add(i)
            }
            // 更新 maxElement：取二者更大者
            maxElement = maxOf(maxElement, cur)
        }
    }
    // 目前 idxList 中的索引顺序是从右向左（因为我们倒序遍历过），
    // 如果想要返回“从左到右”的自然顺序，需要再反转一下：
    return idxList.reversed()
}

/**
 * 返回第一个大于 value 的位置（若都 ≤ value 则返回 size）。
 */
fun <T : Comparable<T>> List<T>.upperBound(value: T): Int {
    // binarySearch 找到 value 时返回某个 idx；找不到时返回 insertionPoint = -idx-1
    val idx = this.binarySearch(value)
    return if (idx >= 0) {
        // 如果正好命中一个 value，还要往右跳过所有相等的元素
        var i = idx + 1
        while (i < size && this[i] == value) i++
        i
    } else {
        // 如果没命中，-idx-1 本身就是第一个 > value 的插入点
        -idx - 1
    }
}
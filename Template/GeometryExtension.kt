package com.Junital.utils

import kotlin.math.hypot
import kotlin.math.abs

// 二维点
data class Point(val x: Double, val y: Double) {
    /** 与另一个点的欧氏距离 */
    fun distanceTo(other: Point): Double =
        hypot(other.x - x, other.y - y)
}

/**
 * 计算点 P 到由 A、B 确定的**无限直线**的距离
 *
 * 公式：| (B−A) × (P−A) | / |B−A|
 * 其中二维叉积 (x1,y1)×(x2,y2) = x1*y2 – y1*x2
 */
fun Point.distanceToLine(a: Point, b: Point): Double {
    // 向量 AB 和 AP
    val abx = b.x - a.x
    val aby = b.y - a.y
    val apx = x   - a.x
    val apy = y   - a.y

    // 叉积的绝对值
    val cross = abs(abx * apy - aby * apx)
    // 线段 AB 的长度
    val abLen = hypot(abx, aby)
    return if (abLen == 0.0) {
        // A、B 重合时退化为点距离
        hypot(apx, apy)
    } else {
        cross / abLen
    }
}

data class Triangle(val a: Point, val b: Point, val c: Point) {
    /**
     * 三角形面积 = 底边 BC 的长度 * A 到直线 BC 的距离 / 2
     */
    fun area(): Double {
        // 高：顶点 A 到 BC 所在直线的距离
        val height = a.distanceToLine(b, c)
        // 底：BC 的长度
        val base   = b.distanceTo(c)
        return base * height / 2
    }

    /**
     * 三角形面积 = 叉积计算面积
     */
    fun area_opt(): Double {
        val abx = b.x - a.x
        val aby = b.y - a.y
        val acx = c.x - a.x
        val acy = c.y - a.y
        val cross = abs(abx*acy - aby*acx)
        return cross / 2
    }
}
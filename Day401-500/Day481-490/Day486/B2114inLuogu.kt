/*****************************************************************
 * 题目：配对碱基链
 * 描述：根据碱基互补情况，输出语气相匹配的字符串。
 * 思路：建立双向映射。
 * 对象：BiMap构建双向映射。
 * 注意：输入输出格式。
 ****************************************************************/

class BiMap<Type>{
    private val forwardMap = mutableMapOf<Type, Type>()
    private val reverseMap = mutableMapOf<Type, Type>()

    constructor()

    constructor(initList: List<Pair<Type, Type>>) {
        initList.forEach { (key, value) ->
            insert(key, value)
        }
    }

    /* 插入新元素 */
    fun insert(key: Type, value: Type) {
        if (forwardMap.containsKey(key) || reverseMap.containsKey(value)) {
            throw RuntimeException("Duplicate key or value.")
        }
        forwardMap[key] = value
        reverseMap[value] = key
    }

    /* 获取另一个元素 */
    fun getAnother(key: Type): Type {
        return forwardMap[key] ?: reverseMap[key]
            ?: throw RuntimeException("Key not found.")
    }

    fun erase(key: Type) {
        forwardMap[key]?.let {
            reverseMap.remove(it)
            forwardMap.remove(key)
        }
        reverseMap[key]?.let {
            forwardMap.remove(it)
            reverseMap.remove(key)
        }
    }

    fun entries(): Set<Map.Entry<Type, Type>> {
        return forwardMap.entries
    }
}

fun main(args: Array<String>) {
    val s = readLine()?: ""

    val pair = BiMap(listOf('A' to 'T', 'C' to 'G'))

    var ans = ""
    for (ch in s)
    {
        ans += pair.getAnother(ch)
        
    }
    println(ans)
}

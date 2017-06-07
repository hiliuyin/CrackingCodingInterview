/*题目描述
请实现一个算法，确定一个字符串的所有字符是否全都不同。这里我们要求不允许使用额外的存储结构。
给定一个string iniString，请返回一个bool值,True代表所有字符全都不同，False代表存在相同的字符。保证字符串中的字符为ASCII字符。字符串的长度小于等于3000。
测试样例：
"aeiou"
返回：True
"BarackObama"
返回：False
*/

/*
--------------method1-------
每个字符与后面的字符比较，时间复杂度T(n^2)

--------------method2--------
用一个数组存储，用字符的值作为数组的小标。

-------------method3----------
若允许修改字符串，可以对字符串排序，T(nlogn),然后在线性时间比较是否有重复字符
*/

class Different {
public:
    bool checkDifferent(string iniString) {
        if(iniString.empty()) return false;
        bool char_set[256];
        std::memset(char_set, 0, 256);
        
        for(auto&& str : iniString){
            if(char_set[str] == 1){
                return false;
            }
            char_set[str] = 1;
        }
        
        return true;
    }
};

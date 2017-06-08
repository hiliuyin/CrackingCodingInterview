/*
题目描述
假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。
测试样例：
"Hello world","worldhello "
返回：false
"waterbottle","erbottlewat"
返回：true
*/
/*
对于切割，令s1=xy=waterbottle; x=wat; y=erbottle，s2=yx=erbottlewat.
不论xy的切割点在哪，xy一定是xyxy的子串，即s2总是s1s1的子串。
*/
class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        if(s1.empty() || s1.size() != s2.size()) {
            return false;
        }
        
        s1 += s1;
        return s1.find(s2) != std::string::npos;
    }
};

/*
题目描述
给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
测试样例：
"This is nowcoder","is This nowcoder"
返回：true
"Here you are","Are you here"
返回：false
*/

/*
在比较前先确定两个字符串长度是否相同，如果不同，直接返回false。
*/

/*----------code1------------*/
/*排序两个字符串，然后比较其是否相等。*/
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        if(stringA.size() != stringB.size()) return false;
        
        std::sort(stringA.begin(), stringA.end());
        std::sort(stringB.begin(), stringB.end());
        
        return stringA.compare(stringB) == 0;
    }
};

/*--------code2--------*/

/*
题目描述
利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
给定一个string iniString为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
测试样例
"aabcccccaaa"
返回："a2b1c5a3"
"welcometonowcoderrrrr"
返回："welcometonowcoderrrrr"
*/

class Zipper {
public:
    string zipString(string iniString) {
        if(iniString.empty()){
            return "";
        }
        std::string result;
        char ch = iniString[0];
        int count = 1;
        for(int i = 1, iEnd = iniString.size(); i < iEnd; ++i){
            if(result.size() >= iniString.size()){ //减少时间复杂度
                return iniString;
            }
            if(ch == iniString[i]){
                ++count;
            }else{
                result += ch;
                result += std::to_string(count);
                ch = iniString[i];
                count = 1;
            }
        }
        result += ch;
        result += std::to_string(count);
        
        return (result.size() < iniString.size())? result: iniString;
    }
};

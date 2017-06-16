/*
题目描述
有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
测试样例：
0.625
返回：0.101
*/


/**********code1************/
class BinDecimal {
public:
    string printBin(double num) {
        if(num <= 0 || num >= 1){
            return "Error";
        }
        double frac = 0.5;
        std::string result("0.");
        while(num > 0){
            if(result.size() > 32){
                return "Error";
            }
            if(num >= frac){
                result.append("1");
                num -= frac;
            }else{
                result.append("0");
            }
            frac /= 2;
        }
        
        return result;
    }
};

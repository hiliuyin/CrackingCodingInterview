/*
题目描述
编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
给定两个整数int A，int B。请返回需要改变的数位个数。
测试样例：
10,5
返回：4
*/

/*
找出两个数之间的不同，只需要使用异或(XOR)操作即可。
所以转换为统计A^B中1的个数。

*/
//code1: 通过不断的对c进行移位，然后检查最低有效位，计算要多少次c才能变成0.
class Transform {
public:
    int calcCost(int A, int B) {
        int result = 0;
        int c = A ^ B;
        while(c != 0){
            result += c & 1;
            c >>= 1;
        }
        return result;
    }
};

//code2: 操作 c = c & (c-1)会清除c的最低有效位。
class Transform {
public:
    int calcCost(int A, int B) {
        int result = 0;
        int c = A ^ B;
        while(c != 0){
            ++result;
            c = c & (c-1);
        }
        return result;
    }
};

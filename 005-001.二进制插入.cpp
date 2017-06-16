/*
题目描述
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位,其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i-j+1。
测试样例：
1024，19，2，6
返回：1100
*/

/*
1)将n中从i-j之间的位清零
1.1）位置i之前的全部为1，其余为0:left = 0xffff <<(i+1);
1.2) 位置j之后全为1，其余为0:right = 1<<j - 1;
1.3) mask = left | right;
1.4) n = n & mask;
2）对m执行移位操作，与i和j之间的位对齐
3）合并m与n
*/
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
    //i之前的位均为1
    int left = 0xFFFF;
    left = left << (i+1);
    //j之后的均为1
    int right = 1;
    right = right << j;
    right -= 1;

    int mask = left | right;
    n = n & mask;
    m = m << j;
    return n|m;
    }
};

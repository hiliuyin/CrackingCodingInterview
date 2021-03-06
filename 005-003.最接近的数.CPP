/*
题目描述
有一个正整数，请找出其二进制表示中1的个数相同、且大小最接近的那两个数。(一个略大，一个略小)
给定正整数int x，请返回一个vector，代表所求的两个数（小的在前）。保证答案存在。
测试样例：
2
返回：[1,4]
*/

/*
方法一：位操作法：
获得下一个较大的数：
1）统计最右端非尾部0右边0的个数c0；
2）统计最右端非尾部0右边1的个数c1；  c1 = 5, c0 = 2
3）将最右端非尾部0->1，最右端非尾部0的位置p=c0+c1;
4) 将p右方的所有位清零
5) 回填c1-1个1至最右边

获得前一个较小的数：
1）计算c0和c1的值。c1是拖尾1的个数，c0是紧邻拖尾1的左边一连串的0的个数。
2）将最右边,非拖尾1变为0。其位置为p=c1+c0；
3）将p右边的所有位清零。
4）在紧邻p的右方插入c1+1个1.

获得下一个较大的数，举例如下：
2）统计最右端非尾部0右边1的个数c1；  c1 = 5, c0 = 2
|1 |1 |0 |1 |1|0|0|1|1|1|1|1|0|0|
|--|--|--|--|-|-|-|-|-|-|-|-|-|-|
|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
3）将最右端非尾部0->1，最右端非尾部0的位置p=c0+c1;翻转第7位为1
|1 |1 |0 |1 |1|0|1|1|1|1|1|1|0|0|
|--|--|--|--|-|-|-|-|-|-|-|-|-|-|
|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
4) 将p右方的所有位清零，
|1 |1 |0 |1 |1|0|1|0|0|0|0|0|0|0|
|--|--|--|--|-|-|-|-|-|-|-|-|-|-|
|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
5) 回填c1-1个1至最右边
|1 |1 |0 |1 |1|0|1|0|0|0|0|0|0|0|
|--|--|--|--|-|-|-|-|-|-|-|-|-|-|
|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
*/

/*****************code1************/
class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
		std::vector<int> vec;
    
        vec.emplace_back(getPre(x));
        vec.emplace_back(getNext(x));
        return vec;
    }
private:
    int getNext(int x){
        int c = x;
        int c0 = 0, c1 = 0;
        //统计最右边的0的个数
        while(c != 0 && (c & 1) == 0)
        {
            ++c0;
            c >>= 1;
        }
        //统计最右边1的个数
        while((c & 1) == 1){
            ++c1;
            c >>= 1;
        }
        //若 n == 11..1100...00,那么就没有更大的数字，且1的个数相同
        if(c1 + c0 == 31 || c1 + c0 == 0){
            return -1;
        }

        int p = c0 + c1; //最右边非拖尾的0的位置
        x |= ( 1 << p); //翻转最右边非拖尾的0的值，令其为1
        x &= ~((1 << p) - 1); //将p右方所有的位清零
        x |= (1 << (c1 - 1)) - 1; //在右方插入(c1-1)个1
        return x;
    }

    int getPre(int x){
        int c = x;
        int c0 = 0, c1 = 0;

        //最右边非拖尾1的个数
        while((c & 1)){
            ++c1;
            c >>= 1;
        }
        //最右边0的个数
        while(c != 0 && (c & 1) == 0){
            ++c0;
            c >>= 1;
        }

        int p = c1 + c0; //最右边非拖尾1的位置
        x &= (0xffff)<<(p+1); //将[p+1,0]清0

        int mask = (1 << (c1+1)) - 1; //(c1+1)个1
        x |= mask << (c0 -1);
        return x;
    }
};

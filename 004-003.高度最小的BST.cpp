/*
题目描述
对于一个元素各不相同且按升序排列的有序序列，请编写一个算法，创建一棵高度最小的二叉查找树。
给定一个有序序列int[] vals,请返回创建的二叉查找树的高度。
*/

/*
运用递归的方法实现。
1）将数组中间位置的元素插入树中
2) 将数组左半边元素插入左子树
3) 将数组右半元素插入右子树
4) 递归处理
*/
class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        if(vals.empty()){
        return 0;
    }
    return buildMinimalBST(vals, 0, vals.size()-1); 
    }
private:
    int buildMinimalBST(vector<int> vals, int start, int end) {
    if(vals.empty() || start > end){
        return 0;
    }
    
    int depth = 1;
    int mid = start + (end - start) / 2;
    return std::max(buildMinimalBST(vals, start, mid - 1), buildMinimalBST(vals, mid+1, end)) + 1;
}
};

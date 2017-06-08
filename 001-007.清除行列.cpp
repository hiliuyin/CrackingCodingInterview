/*
题目描述
请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
给定一个N阶方阵int[][](C++中为vector<vector><int>>)mat和矩阵的阶数n，请返回完成操作后的int[][]方阵(C++中为vector<vector><int>>)，保证n小于等于300，矩阵中的元素为int范围内。</int></vector></int></vector>
测试样例：
[[1,2,3],[0,1,2],[0,0,1]]
返回：[[0,0,3],[0,0,0],[0,0,0]]
*/

class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        if(mat.empty()) return mat;
        
        std::vector<int> cols;
        std::vector<int> rows;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    cols.emplace_back(i);
                    rows.emplace_back(j);
                }
            }
        }
        
        //set col to 0
        for(auto&& col : cols){
            for(int i = 0; i < n; ++i){
                mat[col][i] = 0;
            }
        }
        
        //set row to 0
        for(auto&& row : rows){
            for(int i = 0; i < n; ++i){
                mat[i][row] = 0;
            }
        }
        
        return mat;
    }
};

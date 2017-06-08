/*
题目描述
有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后的NxN矩阵,保证N小于等于500，图像元素小于等于256。
测试样例：
[[1,2,3],[4,5,6],[7,8,9]],3
返回：[[7,4,1],[8,5,2],[9,6,3]]
*/

//code1:
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    	if(mat.empty() || n < 1 || mat.size() != n) {
            return {};
        }

        for(int i = 0, iEnd = (n+1) / 2; i < iEnd; ++i){ //控制每一层
            for(int j = i, jEnd = n-1-i; j < jEnd; ++j){
                int tmp = mat[i][j]; //存储左上角

                mat[i][j] = mat[n-1-j][i]; //左下==>右上
                mat[n-1-j][i] = mat[n-1-i][n-1-j]; //右下==>左下
                mat[n-1-i][n-1-j] = mat[j][n-1-i]; //右上==>右下
                mat[j][n-1-i] = tmp;
            }
        }
        return mat;
    }
};


//code2: 先沿对角线交换，然后每一行翻转
class Transform {
public:
    vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    	if(mat.empty() || n < 1 || mat.size() != n) {
            return {};
        }

        for(int i = 0; i < n; ++i){ //控制每一层
            for(int j = 0; j < i; ++j){
                std::swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; ++i){
            std::reverse(mat[i].begin(), mat[i].end());
        }
        
        return mat;
    }
};

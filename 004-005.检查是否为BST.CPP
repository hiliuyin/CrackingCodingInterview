/*
题目描述
请实现一个函数，检查一棵二叉树是否为二叉查找树。
给定树的根结点指针TreeNode* root，请返回一个bool，代表该树是否为二叉查找树。
*/

/*
**************method1:
中序遍历该树并将结果保存在数组中，最后对数组进行判断，看数组是否为有序

**************method2:
在方法1中，需要保存所有元素，其实并不需要，只需要记录数组在逻辑上的尾部last_val,然后拿该值与后面的元素比较，root->val<=last_val:返回false；
否则令last_val=root->val，并递归判断右子树

***********method3:
确切的说，成为二叉查找树的条件是：所有左边的节点必须小于或等于当前节点，而当前节点必须小于右边所有节点。
利用这一点，可以通过自上而下传递最小和最大值来解决这个问题，在迭代遍历树的过程中，用逐渐变窄的范围检查各个节点。
首先从(min=INT_MIN, max=INT_MAX)这个范围开始。根节点落在其中。然后处理左子树，检查这些节点是否落在(min=INT_MIN, max=root->val),然后再
处理右子树，检查这些节点是否落在(min=root->val, max=INT_MAX)。
依次遍历整棵树。进入左子树时更新max，进入右子树时更新min，只要有任何一个节点不能通过检查，就返回false。
*/
//code2: 最小/最大法
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Checker {
public:
    bool checkBST(TreeNode* root) {
		if(root == nullptr){
            return true;
        }
        int last_val = INT_MIN;
        
        std::function<bool(TreeNode*, int&)>
        checkBSTProxy = [&](TreeNode* root, int& last_val)->bool{
            if(root == nullptr){
                return true;
            }
            //递归检查左子树
            if(!checkBSTProxy(root->left, last_val)){
                return false;
            }
            //检查当前节点
            if(root->val <= last_val){
                return false;
            }
            last_val = root->val;
            //递归检查右子树
            return checkBSTProxy(root->right, last_val);
        };
       
        return checkBSTProxy(root, last_val);
    }
};


//Code3:
class Checker {
public:
    bool checkBST(TreeNode* root) {
		if(root == nullptr){
            return true;
        }
        int last_val = INT_MIN;
        
        std::function<bool(TreeNode*, int, int)>
        checkBSTProxy = [&](TreeNode* root, int minVal, int maxVal)->bool{
            if(root == nullptr){
                return true;
            }
            if(root->val <= minVal || root->val >= maxVal){
                return false;
            }
            return checkBSTProxy(root->left, minVal, root->val)&& checkBSTProxy(root->right, root->val, maxVal);
        };
        
        return checkBSTProxy(root, INT_MIN, INT_MAX);
    }
};

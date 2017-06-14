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
*/

//code2:
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

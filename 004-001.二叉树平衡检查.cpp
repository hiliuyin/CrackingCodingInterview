/*
题目描述
实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class Balance {
public:
    bool isBalance(TreeNode* root) {
	   std::function<bool(TreeNode*, int&)>
	   isBalanceProxy= [&](TreeNode* root, int& height)->bool{ //每次记录二叉树的深度。从下到上判断二叉树
			if(root == nullptr){
				height = 0;
				return true;
			}
			int leftHeight;
			auto bLeft = isBalanceProxy(root->left, leftHeight);
			if(!bLeft){
				return false;
			}
			int rightHeight;
			auto bRight = isBalanceProxy(root->right, rightHeight);
			if(!bRight){
				return false;
			}
			if(std::abs(leftHeight - rightHeight) <= 1){
				height = std::max(leftHeight, rightHeight) + 1;
				return true;
			}

			return false;
	   };

		int height = 0;
	   return isBalanceProxy(root, height);
    }
};

/*
题目描述
请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。
*/

/*
***************method1*************
本题与其他寻找中序遍历的后继的题目不同，该题没有指向父节点的指针。所以按照非递归实现中序遍历的方法，在遍历过程中先找到要找后继节点的节点，
然后根据该节点是否有右子树来找它的后继节点。如果有右子树，返回右子树的最左节点；否则，返回栈顶的值。 如果没找到要找后继节点的值，按照中序遍历的步骤操作。
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


/***Code1:*/
class Successor {
public:
    int findSucc(TreeNode* root, int p) {
    if(root == nullptr){
        return -1;
    }
    
    std::stack<TreeNode*> s;
    s.emplace(root);
    TreeNode* pCur = root->left;
    while(!s.empty() || pCur != nullptr){
        if(pCur != nullptr && pCur->val == p){//找到要返回下一节点的节点
            if(pCur->right != nullptr){ //有右子树，返回右子树的最左节点
                auto tmp = pCur->right;
                while(tmp->left != nullptr){
                    tmp = tmp->left;
                }
                
                return tmp->val;
            }else{//没有右子节点，返回栈顶的值
                if(!s.empty()){
                    return s.top()->val;
                }else{
                    return -1;
                }
            }
        }else{
            if(pCur != nullptr){
                s.emplace(pCur);
                pCur = pCur->left;
            }else{
                pCur = s.top()->right;
                s.pop();
            }
        }
    }
    
    return -1;
    }
};

/***Code2*/
class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        if(root == nullptr){
            return -1;
        }
        
        std::function<int(TreeNode*, int, bool&)>
        findSuccProxy = [&](TreeNode* root, int p, bool& target)->int{
            if(root == nullptr){
                return -1;
            }
            
            int left = findSuccProxy(root->left, p, target);
            if(left != -1){ return left; }
            if(target){ //一定要放在下一个判断前
                return root->val;
            }
            if(root->val == p){
                target = true;
            }            
            return findSuccProxy(root->right, p, target);
        };
        
        bool target = false;
        return findSuccProxy(root, p, target);
    }
};

/*
题目描述
对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，代表该深度上所有结点的值，请按树上从左往右的顺序链接，
保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。
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

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

/* code1:
广度优先遍历实现
*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if(root == nullptr || dep < 0){
            return nullptr;
        }
        if(dep == 1){
            return new ListNode(root->val);
        }
        int cur = 1;
        ListNode head(0);
        ListNode* pre = &head;
        std::queue<TreeNode*> que;
        que.emplace(root);
        while(!que.empty()){
            for(int i = 0, iEnd = que.size(); i < iEnd; ++i){
                auto tmp = que.front();
                que.pop();
                if(tmp->left != nullptr){
                    que.emplace(tmp->left);
                }
                if(tmp->right != nullptr){
                    que.emplace(tmp->right);
                }
            }
            ++cur;
            if(cur == dep){
                break;
            }
        }
        
        while(!que.empty()){
            pre->next = new ListNode(que.front()->val);
            que.pop();
            pre = pre->next;
        }
        
        return head.next;
    }
};

/* code 2:
先序遍历
*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if(root == nullptr || dep < 0){
            return nullptr;
        }
        if(dep == 1){
            return new ListNode(root->val);
        }
        
        std::vector<int> vec;
        getTreeLevelProxy(vec, root, 1, dep);
        ListNode result(0);
        ListNode* pre = &result;
        for(auto&& val : vec){
            pre->next = new ListNode(val);
            pre = pre->next;
        }
        return result.next;
    }
private:
    void getTreeLevelProxy(std::vector<int>& vec, TreeNode* root, int level, int dep){
        if(root == nullptr || level > dep){
            return ;
        }
        
        if(level == dep){
            vec.emplace_back(root->val);
        }
        else{
            if(root->left != nullptr){
                getTreeLevelProxy(vec, root->left, level + 1, dep);
            }
            if(root->right != nullptr){
                getTreeLevelProxy(vec, root->right, level + 1, dep);
            }
        }
    }
};

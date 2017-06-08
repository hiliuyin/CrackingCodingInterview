/*
题目描述
有两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表的首部。编写函数对这两个整数求和，并用链表形式返回结果。
给定两个链表ListNode* A，ListNode* B，请返回A+B的结果(ListNode*)。
测试样例：
{1,2,3},{3,2,1}
返回：{4,4,4}
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    
    ListNode result(0);
    ListNode* p = &result;
    int carry = 0;
    
    while(a != nullptr && b != nullptr){
        int val = a->val +b->val +carry;
        p->next = new ListNode(val % 10);
        p = p->next;
        carry = val / 10;
        a = a->next;
        b = b->next;
    }
    while(a != nullptr ){
        int val = a->val +carry;
        p->next = new ListNode(val);
        p = p->next;
        carry = val / 10;
        a = a->next;
    }
    while(b != nullptr){
        int val = b->val +carry;
        p->next = new ListNode(val % 10);
        p = p->next;
        carry = val / 10;
        b = b->next;
    }
    
    if(carry > 0){   //不要忘记
        p->next = new ListNode(carry);
    }
    return result.next;
    }
};

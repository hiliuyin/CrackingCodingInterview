/*
题目描述
编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。注意：分割以后保持原来的数据顺序不变。
*/

//从前向后访问每个元素，与x判断并保存。维护两个链表。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        ListNode p1(0);
        ListNode p2(0);
        ListNode* pLess = &p1;
        ListNode* pBig = &p2;
        
        while(pHead != nullptr){
            if(pHead->val < x){
                pLess->next = pHead;
                pLess = pLess->next;
            }else{
                pBig->next = pHead;
                pBig = pBig->next;
            }
            pHead = pHead->next;
        }
        pBig->next = nullptr;
        pLess->next = p2.next;
        return p1.next;
    }
};

//上述方法中，创建了2个头节点。可以将链表逆序插入新的两个链表中.
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        ListNode* pLess = nullptr;
        ListNode* pBig = nullptr;
        while(pHead != nullptr){
            auto pNext = pHead->next;
            if(pHead->val < x){
                pHead->next = pLess;
                pLess = pHead;
            }else{
                pHead->next = pBig;
                pBig = pHead;
            }
            pHead = pNext;
        }
        
        pLess = reverseList(pLess);
        pBig = reverseList(pBig);
        
        if(pBig == nullptr){
            return pLess;
        }
        if(pLess == nullptr){
            return pBig;
        }
        
        pHead = pLess;
        while(pLess->next != nullptr){
            pLess = pLess->next;
        }
        pLess->next = pBig;
        return pHead;
    }
    
private:
    ListNode* reverseList(ListNode* pHead){
        if(pHead == nullptr || pHead->next == nullptr){
            return pHead;
        }
        
        ListNode* pResult = nullptr;
        while(pHead != nullptr){
            auto pNext = pHead->next;
            pHead->next = pResult;
            pResult = pHead;
            pHead = pNext;
        }
        
        return pResult;
    }
};

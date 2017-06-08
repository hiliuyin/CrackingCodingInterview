/*
假设数位是正序排放的。
*/

/*
method1:翻转2个链表，然后用002-005-001的方法
method2:用递归从后向前加每一个数位
*/
int ListLen(ListNode* pHead){
    if(pHead == nullptr){
        return 0;
    }
    
    int result = 0;
    while(pHead != nullptr) {
        ++result;
        pHead = pHead->next;
    }
    
    return result;
}

ListNode* AddZeroToList(ListNode* pHead, int len){
    if(len <= 0 || pHead == nullptr){
        return pHead;
    }
    for(int i = 0; i < len; ++i){
        auto node = new ListNode(0);
        node->next = pHead;
        pHead = node;
    }
    return pHead;
}

ListNode* plusABProxy(ListNode* a, ListNode* b, int& carry){
    if(a == nullptr || b == nullptr){
        return nullptr;
    }
    auto pNext = plusABProxy(a->next, b->next, carry);
    int tmp = a->val + b->val + carry;
    auto result = new ListNode(tmp % 10);
    result->next = pNext;
    carry = tmp / 10;
    
    return result;
}

ListNode* plusAB(ListNode* a, ListNode* b) {
    if(a == nullptr) return b;
    if(b == nullptr) return a;
    
    //insert 0 for the short list
    int lenA = ListLen(a);
    int lenB = ListLen(b);
    a = AddZeroToList(a, lenB-lenA);
    b = AddZeroToList(b, lenA-lenB);
    
    //Add the node
    int carry = 0;
    
    auto result = plusABProxy(a, b, carry);
   
    if(carry > 0){
        auto tmp = new ListNode(carry);
        tmp->next = result;
        result = tmp;
    }
    
    return result;
}


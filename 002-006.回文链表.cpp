/*
题目描述
请编写一个函数，检查链表是否为回文。
给定一个链表ListNode* pHead，请返回一个bool，代表链表是否为回文。
测试样例：
{1,2,3,2,1}
返回：true
{1,2,3,2,3}
返回：false
*/

/*
翻转前半部分代码，然后拿翻转链表和原链表的后半部分比较。
注意链表长度为奇数的情况
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        if(pHead == nullptr || pHead->next == nullptr){
            return false;
        }
        ListNode* reverseList = nullptr;
        auto pFast = pHead;
        auto pSlow = pHead;
        while(pFast != nullptr && pFast->next != nullptr){
            auto tmp = new ListNode(pSlow->val);
            tmp->next = reverseList;
            reverseList = tmp;

            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr){
                pFast = pFast->next;
            }
        }

        if(pFast != nullptr){ //链表的长度为奇数
            pSlow = pSlow->next;
        }

        //compare the two list
        while(pSlow != nullptr && reverseList != nullptr){
            if(pSlow->val != reverseList->val){
                return false;
            }
            pSlow = pSlow->next;
            reverseList = reverseList->next;
        }

        return true;
    }
};

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);      // 虚拟头节点
    ListNode* tail = &dummy; // tail 一开始指向 dummy

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;   // 把 list1 当前节点接到 tail 后面
            list1 = list1->next;  // list1 往前走
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;  // tail 往后移一步，变成新链表的末尾
    }
    if (list1 == nullptr){
        tail->next = list2;
    }
    if (list2 == nullptr){
        tail->next = list1;
    }
    return dummy.next;
} 
};
// @lc code=end


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
    ListNode* reverseList(ListNode* head) {
        ListNode *node;
        if (head != nullptr) node = head;
        else return nullptr;
        ListNode *pre_node = nullptr,*next_node = nullptr,*node_n = nullptr;
        while (node->next != nullptr){
           cout<<node->val; 
            node_n = node->next;
            //反转node和node_n的next,以node node_n为基本单位迭代进行
            node->next = pre_node;
            //向后迭代，注意边界
            if (node_n->next != nullptr) {
                next_node = node_n->next;
                node_n->next = node;
                pre_node = node_n;
                node = next_node;
            }            
            else {
                node_n->next = node;
                return node_n;
            }
        }
        node->next = pre_node;
        return node;
    }
};
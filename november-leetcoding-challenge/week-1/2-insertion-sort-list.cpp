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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode* sorted = new ListNode(head->val);
        ListNode* pointer = head->next;
        ListNode* sorted_pointer = sorted;
        
        
        while (pointer != nullptr) {
            
            ListNode* newNode = new ListNode(pointer->val, sorted_pointer);
            sorted_pointer = newNode;
            sorted = newNode;
            
            while (sorted_pointer->next != nullptr && sorted_pointer->next->val < sorted_pointer->val) {
                int temp = sorted_pointer->val;
                sorted_pointer->val = sorted_pointer->next->val;
                sorted_pointer->next->val = temp;
                
                sorted_pointer = sorted_pointer->next;
            }
            
            
            
            pointer = pointer->next;
            sorted_pointer = sorted;
        }
        
        return sorted;
    }
};
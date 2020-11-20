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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> p1, p2;
        while (l1) {
            p1.push(l1);
            l1 = l1->next;
        }
        
        while (l2) {
            p2.push(l2);
            l2 = l2->next;
        }
        ListNode *n1, *n2, *begin;
        int carry = 0;
        while (!p1.empty() && !p2.empty()) {
            n1 = p1.top();
            n2 = p2.top();
            p1.pop();
            p2.pop();
            
            n1->val += n2->val + carry;
            carry = n1->val/10;
            n1->val = n1->val%10;
            n2->val = n1->val;
        }
        
        begin = n1;
        
        while (!p1.empty()) {
            n1 = p1.top();
            p1.pop();
            
            n1->val += carry;
            carry = n1->val / 10;
            n1->val = n1->val%10;
            
            begin = n1;
        }
        
        while (!p2.empty()) {
            n2 = p2.top();
            p2.pop();
            
            n2->val += carry;
            carry = n2->val / 10;
            n2->val = n2->val%10;
            
            begin = n2;
        }
        
        if (carry) {
            begin = new ListNode(carry, begin); 
        }
        
        return begin;
    }
};
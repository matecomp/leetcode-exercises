/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/


class Solution {
public:
    Node* foward(Node* node) {
        if (!node) return nullptr;
        
        Node* cur_node = node;
        Node* final_node;
        while (cur_node) {
            if (cur_node->child) {
                Node* next = cur_node->next;
               
                cur_node->next = cur_node->child;
                cur_node->child->prev = cur_node;
                
                Node* prev = foward(cur_node->child);
                prev->next = next;
                if (next) next->prev = prev;
                
                cur_node->child = nullptr;
                cur_node = prev;
            }
            final_node = cur_node;
            cur_node = cur_node->next;
        }
        
        return final_node;
    }

    Node* flatten(Node* head) {
        foward(head);
        return head;
    }
};
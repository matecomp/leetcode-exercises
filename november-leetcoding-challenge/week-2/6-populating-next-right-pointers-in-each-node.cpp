/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void updateQueue(queue<Node*> &q, Node* node) {
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        return;
    }
    
    Node* getNode(queue<Node*> &q) {
        Node* node = q.front();
        q.pop();
        
        return node;
    }

    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int nodes = q.size();
            
            Node* prev = getNode(q);
            updateQueue(q, prev);
            
            for (int i=1; i<nodes; i++) {
                Node* cur = getNode(q);
                updateQueue(q, cur);
                
                prev->next = cur;
                prev = cur;
            }
        }
        
        return root;
    }
};
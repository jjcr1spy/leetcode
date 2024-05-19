/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <unordered_map>

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        Node * iter = head;

        std::unordered_map<Node *, Node *> map;

        while (iter) {
            map[iter] = new Node(iter->val);
            iter = iter->next;
        }

        iter = head;
        while (iter) {
            map[iter]->next = map[iter->next];
            map[iter]->random = map[iter->random];
        
            iter = iter->next;
        }

        return map[head];
    }
};
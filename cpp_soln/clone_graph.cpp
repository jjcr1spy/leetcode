#include <vector>
#include <queue>
#include <unordered_map>

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    std::unordered_map<Node *, Node *> m;

    Node * cloneGraph(Node * node) {
        if (!node) return nullptr;
        
        std::queue<Node *> q;
        q.push(node);

        Node * clone = new Node(node->val);
        m[node] = clone;

        while (!q.empty()) {
            Node * n = q.front();
        
            for (int i = 0; i < n->neighbors.size(); ++i) {
                Node * neighbor = n->neighbors[i];

                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                m[n]->neighbors.push_back(m[neighbor]);                 
            }

            q.pop();
        }

        return clone;
    }
};
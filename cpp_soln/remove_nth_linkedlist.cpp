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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        
        ListNode * l = head;
        ListNode * r = head;

        while (n--) {
            r = r->next;
        }
        
        if (!r) { // then first elem in ll should be removed
            return head->next;
        }

        while (r->next) {
            r = r->next;
            l = l->next;
        }
        
        l->next = l->next->next;
    
        return head;
    }
};
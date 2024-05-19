#include <vector>

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
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // solution similiar to merge sort, we will merge each list and its neighbor
        // if there is not even number of lists we will merge lists.size() - 1 LL at end
        int k = lists.size();

        if (k == 0) return nullptr;
        if (k == 1) return lists[0];

        bool isOdd = k % 2 != 0 ? true : false; // need to account for edge case 

        while (k > 1) {
            for (int i = 0; i < k / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[k - i - 1]);
            }

            k = (k + 1) / 2;
        }

        return lists[0];
    }

    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode * dumb = new ListNode(), * curr = dumb;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;     
            }   

            curr = curr->next;        
        }
        
        if (l1) curr->next = l1; 
        else if (l2) curr->next = l2; 
        
        ListNode * ret = dumb->next;
        delete dumb;

        return ret;
    }
};
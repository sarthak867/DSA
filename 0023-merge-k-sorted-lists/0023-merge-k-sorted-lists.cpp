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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        // Step 1: collect all values
        for (auto head : lists) {
            while (head) {
                v.push_back(head->val);
                head = head->next;
            }
        }

        // Step 2: if no elements
        if (v.size() == 0) return NULL;

        // Step 3: sort
        sort(v.begin(), v.end());

        // Step 4: create new linked list
        ListNode* head = new ListNode(v[0]);
        ListNode* curr = head;

        for (int i = 1; i < v.size(); i++) {
            curr->next = new ListNode(v[i]);
            curr = curr->next;
        }

        return head;
    }
};

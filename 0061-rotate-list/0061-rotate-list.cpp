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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: Copy list values into vector
        vector<int> num;
        for (ListNode* temp = head; temp; temp = temp->next)
        num.push_back(temp->val);

        int n = num.size();
        k %= n;
        k = n-k;
        if (k == 0)
            return head;

        reverse(num.begin(), num.begin() + k);
        reverse(num.begin() + k, num.end());

        // Copy values back to list
        ListNode* temp = head;
        int i = n-1;
        while (temp) {
            temp->val = num[i--];
            temp = temp->next;
        }

        return head;
    }
};
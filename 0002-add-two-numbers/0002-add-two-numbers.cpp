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
        ListNode* head = l1;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) sum += l1->val;
            if (l2) sum += l2->val;

            carry = sum / 10;
            sum = sum % 10;

            l1->val = sum;

            // agar l1 khatam ho raha h aur aage data baki h
            if (!l1->next && (l2 && l2->next || carry)) {
                l1->next = new ListNode(0);
            }

            l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode *a, struct ListNode *b){
    if(!a) return b;
    if(!b) return a;
    if(a->val < b->val){
        a->next = merge(a->next,b);
        return a;
    }else{
        b->next = merge(a, b->next);
        return b;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int sz) {
    if(sz==0) return NULL;
    while(sz>1){
        int ns =0;
        for(int i=0;i <sz; i+=2){
            if(i+1<sz) lists[ns++] = merge(lists[i],lists[i+1]);
            else lists[ns++] = lists[i];
        }
        sz = ns;
    }
    return lists[0];
}
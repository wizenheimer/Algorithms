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
        ListNode *trail = head, *lead = head;
        for(int i = 1; i <= n; i++)
            lead = lead->next;
        if(lead == NULL)
            return head->next;
        while(lead->next != NULL) {
            lead = lead->next;
            trail = trail->next;
        }
        
        trail->next = trail->next->next;     
        
        return head;        
    }
};
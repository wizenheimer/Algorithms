/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* middleNode(ListNode *head) {
            ListNode *bar = head;
            ListNode *foo = head;
            while(bar != NULL && bar->next != NULL) {
                bar = bar->next->next;
                foo = foo->next;
            }
            return foo;
        }
};
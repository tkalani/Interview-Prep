/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *head=A;
    
    while(head!=NULL){
        int temp=head->val;
        ListNode* first = head;
        while(first->next!=NULL && first->next->val==temp){
            first = first->next;
        }
        head->next = first->next;
        head=head->next;
    }
    return A;
}

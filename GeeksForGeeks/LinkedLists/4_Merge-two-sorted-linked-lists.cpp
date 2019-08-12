/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
        
    ListNode *C = new ListNode(0);
    ListNode *head=C;
    
    while(A!=NULL && B!=NULL)
    {
        if(A->val <= B->val)
        {
            C->next = A;
            A = A->next;
        }
        else if(A->val > B->val)
        {
            C->next = B;
            B = B->next;
        }
        C = C->next;
    }
    
    while(A!=NULL)
    {
        C->next = A;
        A = A->next;
        C = C->next;
    }
    
    while(B!=NULL)
    {
        C->next = B;
        B = B->next;
        C = C->next;
    }
    return head->next;
}

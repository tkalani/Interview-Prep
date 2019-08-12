/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *temp=A;
    int length=0;
    while(temp)
    {
        length++;
        temp = temp->next;
    }
    
    if(B>=length){
        ListNode *x = A;
        A = A->next;
        free(x);
        return A;
    }
    int node_index = length-B;
    int i=1;
    
    temp=A;
    while(i<node_index){
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
    return A;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int length=0;
    ListNode *temp=A;
    while(temp){
        length++;
        temp = temp->next;
    }
    B = B%length;
    if(B==0)
        return A;
    else
    {
        int start_index = length-B-1;
        int i=0;
        ListNode *temp=A;
        ListNode *head=A;
        while(i<start_index){
            i++;
            temp = temp->next;
        }
        A = temp->next;
        temp->next=NULL;
        
        temp = A;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head;
    }
    return A;
}

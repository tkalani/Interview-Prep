ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *temp=A;
    while(temp!=NULL&&temp->next!=NULL){
        int t=temp->val;
        temp->val=temp->next->val;
        temp->next->val=t;
        
        temp=temp->next->next;
    }
    return A;
}
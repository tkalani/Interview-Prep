/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* final_list = new ListNode(0);
    ListNode *head = final_list;
    
    priority_queue<int, vector<int>, greater<int> > heap;
    
    for(int i=0; i<A.size(); i++)
    {
        ListNode *temp=A[i];
        while(temp)
        {
            heap.push(temp->val);
            temp = temp->next;
        }
    }
    
    while(!heap.empty())
    {
        int temp = heap.top();
        heap.pop();
        
        final_list->next = new ListNode(temp);
        final_list = final_list->next;
    }
    return head->next;
    
}

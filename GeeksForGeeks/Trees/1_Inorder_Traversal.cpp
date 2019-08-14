/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode *> s;
    TreeNode* curr = A;
    vector<int> ans;
    
    while(curr || s.empty()==false)
    {
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        
        if(!s.empty())
        {
            curr = s.top();
            ans.push_back(curr->val);
            s.pop();
        }
        
        curr = curr->right;
    }
    
    return ans;
}

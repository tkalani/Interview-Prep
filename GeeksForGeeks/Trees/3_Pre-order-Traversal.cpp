/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> ans;
    
    TreeNode* curr = A;
    s.push(curr);
    
    while(!s.empty())
    {
        curr = s.top();
        s.pop();
        ans.push_back(curr->val);
        
        if(curr->right)
            s.push(curr->right);
        if(curr->left)
            s.push(curr->left);
    }
    return ans;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    
    TreeNode* curr = A;
    
    vector<int> ans;
    
    s1.push(curr);
    while(!s1.empty())
    {
        TreeNode* curr = s1.top();
        s2.push(curr);
        s1.pop();
        
        if(curr->left)
            s1.push(curr->left);
        if(curr->right)
            s1.push(curr->right);
    }
    
    while(!s2.empty()){
        TreeNode* curr = s2.top();
        ans.push_back(curr->val);
        s2.pop();
    }
    
    return ans;
}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    stack<TreeNode*> s1, s2;
    vector<int> v1, v2;
    
    s1.push(A);
    s2.push(B);
    
    if(!A && !B)
        return 1;
    else if(A && !B)
        return 0;
    else if(!A && B)
        return 0;
    
    while(!s1.empty())
    {
        TreeNode* curr = s1.top();
        v1.push_back(curr->val);
        s1.pop();
        
        if(curr->right)
            s1.push(curr->right);
        if(curr->left)
            s1.push(curr->left);
    }
    
    while(!s2.empty())
    {
        TreeNode* curr = s2.top();
        v2.push_back(curr->val);
        s2.pop();
        
        if(curr->right)
            s2.push(curr->right);
        if(curr->left)
            s2.push(curr->left);
    }
    
    if(v1.size() != v2.size())
        return 0;
    else
    {
        for(int i=0; i<v1.size(); i++)
            if(v1[i] != v2[i])
                return 0;
        return 1;
    }
}

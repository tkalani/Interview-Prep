/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> findIfValid(TreeNode* A)
{
    vector<int> ans;
    stack<TreeNode*> s;
    
    TreeNode* curr = A;
    
    while(curr || !s.empty())
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

int Solution::isValidBST(TreeNode* A) {
    vector<int> v = findIfValid(A);
    
    for(int i=1; i<v.size(); i++)
    {
        if(v[i]<=v[i-1])
            return 0;
    }
    return 1;
}

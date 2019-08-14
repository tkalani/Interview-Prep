/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int findDepth(TreeNode* A)
{
    queue<pair<TreeNode*, int> > q;
    
    q.push(make_pair(A, 1));
    
    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        q.pop();
        
        if(!p.first->left && !p.first->right)
            return p.second;
        
        if(p.first->left)
            q.push(make_pair(p.first->left, p.second+1));
        if(p.first->right)
            q.push(make_pair(p.first->right, p.second+1));
    }
}

int Solution::minDepth(TreeNode* A) {
    return findDepth(A);
}

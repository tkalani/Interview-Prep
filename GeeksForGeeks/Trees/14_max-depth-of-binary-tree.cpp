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
    if(!A)
        return 0;
    
    return 1+max(findDepth(A->left), findDepth(A->right));
}

int Solution::maxDepth(TreeNode* A) {
    return findDepth(A);
}

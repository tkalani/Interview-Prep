/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findPath(TreeNode* A, int B)
{
    if(!A)
        return B==0;
    
    if(B-A->val==0 && !A->left && !A->right)
        return 1;
    
    int left=0, right=0;
    if(A->left)
        left = findPath(A->left, B-A->val);
    if(A->right)
        right = findPath(A->right, B-A->val);
        
    return right||left;
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return findPath(A, B);
}

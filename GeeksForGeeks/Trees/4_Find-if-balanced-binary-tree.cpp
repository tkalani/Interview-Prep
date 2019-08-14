/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int calcHeight(TreeNode* A)
{
    if(!A)
        return 0;
    
    int lh = calcHeight(A->left);
    int rh = calcHeight(A->right);
    
    return 1+max(lh, rh);
}

int findIfBalanced(TreeNode* A)
{
    if(!A)
        return 1;
        
    int left_h = calcHeight(A->left);
    int right_h = calcHeight(A->right);
    
    if(abs(left_h-right_h)<=1 && findIfBalanced(A->left) && findIfBalanced(A->right))
        return 1;
    return 0;
}
 
int Solution::isBalanced(TreeNode* A) {
    return findIfBalanced(A);
}

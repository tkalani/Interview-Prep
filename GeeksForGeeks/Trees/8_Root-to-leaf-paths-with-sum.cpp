/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPaths(TreeNode* A, int B, vector<vector<int> > &ans, vector<int> &subseq, int sum)
{
    if(!A)
        return;
        
    sum += A->val;
    subseq.push_back(A->val);
    
    if(B==sum && !A->left && !A->right)
        ans.push_back(subseq);
        
    if(A->left)
    {
        findPaths(A->left, B, ans, subseq, sum);
    }
    if(A->right)
    {
        findPaths(A->right, B, ans, subseq, sum);
    }
    
    subseq.pop_back();
        
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    vector<int> subseq;
    
    // subseq.push_back(A->val);
    int sum= 0;
    findPaths(A, B, ans, subseq, sum);
    
    return ans;
}

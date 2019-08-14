/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void printTraversal(TreeNode* A, vector<vector<int> > &ans)
{
    stack<TreeNode *> s1, s2;
    
    s1.push(A);
    
    while(!s1.empty() || !s2.empty())
    {
        vector<int> seq1;
        while(!s1.empty())
        {
            TreeNode* parent = s1.top();
            s1.pop();
            seq1.push_back(parent->val);
            
            if(parent->left)
                s2.push(parent->left);
            if(parent->right)
                s2.push(parent->right);
        }
        if(seq1.size()>0)
            ans.push_back(seq1);
        
        vector<int> seq2;
        while(!s2.empty())
        {
            TreeNode* parent = s2.top();
            s2.pop();
            seq2.push_back(parent->val);
            
            if(parent->right)
                s1.push(parent->right);
            if(parent->left)
                s1.push(parent->left);
        }
        if(seq2.size()>0)
            ans.push_back(seq2);
    }
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    printTraversal(A, ans);
    
    return ans;
}

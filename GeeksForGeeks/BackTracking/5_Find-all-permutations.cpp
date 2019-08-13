void findPerm(vector<int> &A, vector<vector<int> > &ans, int start)
{
    if(start==A.size())
        ans.push_back(A);
        
    for(int i=start; i<A.size(); i++)
    {
        swap(A[start], A[i]);
        findPerm(A, ans, start+1);
        swap(A[start], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> perm;
    
    sort(A.begin(), A.end());
    findPerm(A, ans, 0);
    sort(ans.begin(), ans.end());
    
    return ans;
}

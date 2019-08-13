void findSubsets(vector<int>&A, vector<vector<int> >&ans, vector<int>&subset, int start){
    ans.push_back(subset);
    for(int i=start; i<A.size(); i++)
    {
        subset.push_back(A[i]);
        findSubsets(A, ans, subset, i+1);
        subset.pop_back();
    }
    return;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> subset;
    
    sort(A.begin(), A.end());
    findSubsets(A, ans, subset, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

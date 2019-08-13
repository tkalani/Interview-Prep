void backtracking(int start, vector<int>& row, int sum, vector<vector<int> >& res, vector<int>& A, int B)
{
    if (sum >= B)
    {
        if (sum==B)
            res.push_back(row);
        return;
    }
    
    if (start == A.size())
        return;
        
    row.emplace_back(A[start]);
    sum += A[start];
    backtracking(start, row, sum, res, A, B);
    sum -= row[row.size()-1];
    row.pop_back();
    backtracking(start+1, row, sum, res, A, B);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    vector<int> row, a;
    
    sort(A.begin(), A.end());
    
    a.push_back(A[0]);
    for (int i = 1; i<A.size(); ++i)
        if (A[i-1] != A[i])
            a.push_back(A[i]);
    
    backtracking(0, row, 0, res, a, B);
    return res;
}

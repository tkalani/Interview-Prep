void removeDuplicates(vector<int> &A)
{
    vector<int>::iterator ip;
    ip = std::unique(A.begin(), A.end());
    A.resize(std::distance(A.begin(), ip));
}

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
    backtracking(start+1, row, sum, res, A, B);
    sum -= row[row.size()-1];
    row.pop_back();
    
    int endIndex = 0;                       // Refined memory saving way to avoid repeated subsets.
    for (endIndex = start+1; endIndex < A.size() && A[endIndex]==A[start]; ++endIndex)
        ++start;
        
    backtracking(start+1, row, sum, res, A, B);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int> > res;
    vector<int> row;
    
    sort(A.begin(), A.end());
    // removeDuplicates(A);
    backtracking(0, row, 0, res, A, B);
    sort(res.begin(), res.end());
    return res;
}

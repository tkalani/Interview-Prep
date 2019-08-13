void findSubSeq(vector<vector<int> >&ans, vector<int> subseq, int A, int B, int start)
{
    if(subseq.size()==B)
        ans.push_back(subseq);
    if(start==A)
        return;
    for(int i=start; i<A; i++)
    {
        subseq.push_back(i+1);
        findSubSeq(ans, subseq, A, B, i+1);
        subseq.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int> > ans;
    vector<int> subseq;
    
    findSubSeq(ans, subseq, A, B, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

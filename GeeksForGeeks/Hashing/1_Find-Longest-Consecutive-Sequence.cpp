int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> s;
    int max_len=1;
    for(int i=0; i<A.size(); i++)
        s.insert(A[i]);
        
    for(int i=0; i<A.size(); i++)
    {
        if(s.find(A[i]-1)==s.end())
        {
            int start=A[i];
            while(s.find(start+1)!=s.end())
                start+=1;
            int length=start-A[i]+1;
            max_len = max(max_len, length);
        }
    }
    return max_len;
}

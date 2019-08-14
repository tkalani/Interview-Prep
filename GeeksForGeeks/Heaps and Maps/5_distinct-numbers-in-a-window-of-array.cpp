vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int, int> m;
    
    vector<int> ans;
    int dist_count=0;
    
    for(int i=0; i<B; i++)
    {
        if(m[A[i]]==0)
            dist_count++;
        m[A[i]] += 1;
    }
    
    ans.push_back(dist_count);
    
    for(int i=1; i<A.size()-B+1; i++)
    {
        if(m[A[i-1]]==1)
            dist_count--;
        m[A[i-1]] -= 1;
            
        if(m[A[i+B-1]]==0)
            dist_count++;
        m[A[i+B-1]] += 1;
        
        ans.push_back(dist_count);
    }
    return ans;
}

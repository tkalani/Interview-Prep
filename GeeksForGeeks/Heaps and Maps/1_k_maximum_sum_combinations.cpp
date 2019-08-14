vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    priority_queue<pair<int, pair<int, int> > > heap;
    set<pair<int, int> > myset;
    
    vector<int> ans;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    heap.push(make_pair(A[n-1]+B[n-1], make_pair(n-1, n-1)));
    myset.insert(make_pair(n-1, n-1));
    // ans.push_back(A[n-1]+B[n-1]);
    
    int count=0;
    while(count<n)
    {
        pair<int, pair<int, int> > temp = heap.top();
        heap.pop();
        
        ans.push_back(temp.first);
        int i, j;
        i = temp.second.first;
        j = temp.second.second;
        
        int sum=A[i-1]+B[j];
        
        if(myset.find(make_pair(i-1, j)) == myset.end()){
            heap.push(make_pair(sum, make_pair(i-1, j)));
            myset.insert(make_pair(i-1, j));
        }
        
        sum=A[i]+B[j-1];
        if(myset.find(make_pair(i, j-1)) == myset.end()){
            heap.push(make_pair(sum, make_pair(i, j-1)));
            myset.insert(make_pair(i, j-1));
        }
        count++;
    }
    return ans;
}

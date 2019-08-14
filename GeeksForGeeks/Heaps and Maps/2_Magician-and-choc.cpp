int Solution::nchoc(int A, vector<int> &B) {
    priority_queue<int> heap;
    int mod = 1000000007;
    
    for(int i=0; i<B.size(); i++)
        heap.push(B[i]);
    
    int count=0;
    int choc=0;
    while(count<A)
    {
        count++;
        int temp = heap.top();
        heap.pop();
        
        choc = (choc+(temp%mod))%mod;
        heap.push(temp/2);
    }
    return choc%1000000007;
}

vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int> s;
    vector<int> v;
    
    for(int i=A.size()-1; i>=0; i--)
    {
        if(s.empty())
        {
            v.push_back(-1);
            s.push(A[i]);
        }
        else
        {
            if(A[i]<s.top())
            {
                v.push_back(s.top());
                s.push(A[i]);
            }
            else
            {
                while(!s.empty() && s.top()<=A[i])
                    s.pop();
                
                if(!s.empty())
                    v.push_back(s.top());
                else
                    v.push_back(-1);
                    
                s.push(A[i]);
            }
        }
    }
    
    for(int i=0; i<v.size()/2; i++)
    {
        int temp=v[i];
        v[i] = v[v.size()-1-i];
        v[v.size()-1-i] = temp;
    }
    return v;
}

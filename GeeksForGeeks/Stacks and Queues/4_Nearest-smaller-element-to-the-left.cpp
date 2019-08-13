vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> v;
    if(A.size()==1)
    {
        v.push_back(-1);
    }
    else
    {
        for(int i=0; i<A.size(); i++)
        {
            if(s.empty())
                v.push_back(-1);
            else
            {
                while(!s.empty() && s.top()>=A[i])
                    s.pop();
                if(s.empty())
                    v.push_back(-1);
                else
                    v.push_back(s.top());
            }
            s.push(A[i]);
        }
    }
    return v;
}

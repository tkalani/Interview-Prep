int Solution::isValid(string A) {
    stack<char> s;
    for(int i=0; i<A.length(); i++)
    {
        if(A[i]=='(' || A[i]=='{' || A[i]=='[')
            s.push(A[i]);
        else if(A[i]=='}')
        {
            if(s.empty())
                return 0;
            if(s.top()!='{')
                return 0;
            s.pop();
        }
        else if(A[i]==')')
        {
            if(s.empty())
                return 0;
            if(s.top()!='(')
                return 0;
            s.pop();
        }
        else if(A[i]==']')
        {
            if(s.empty())
                return 0;
            if(s.top()!='[')
                return 0;
            s.pop();
        }
    }
    if(s.empty())
        return 1;
    else
        return 0;
}

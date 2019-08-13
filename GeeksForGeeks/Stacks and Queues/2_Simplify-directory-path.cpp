string Solution::simplifyPath(string A) {
    string ans="/";
    stack<string> s;
    
    for(int i=0; i<A.length(); i++)
    {
        string dir="";
        while(A[i]=='/')
            i++;
        
        while(i<A.length() && A[i]!='/'){
            dir += A[i];
            i++;
        }
        
        if(dir==".")
            continue;
        else if(dir==".."){
            if(!s.empty())
                s.pop();
        }
        else
            s.push(dir);
    }
    
    stack<string> s1;
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }
    
    while(!s1.empty()){
        if(s1.size()!=1){
            ans += s1.top()+"/";
        }
        else{
            ans += s1.top();
        }
        s1.pop();
    }
    
    
    return ans;
}

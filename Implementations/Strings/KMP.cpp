//Calculate prefix function in O(n)
//pi[i] = max k such that s[0,k-1] = s[i-k+1,i] for k from 0 to i

vi prefix(string s){
    int n = (int)s.length();
    vi pi(n,0);
    FOR(i,1,n){
        int cur = pi[i-1];
        while (cur > 0 && s[i] != s[cur]){
            cur = pi[cur-1];
        }
        if (s[i] == s[cur]) cur++;
        pi[i] = cur;
    }
    return pi;
}




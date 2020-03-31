//Find all occurences of pattern s in text t in O(s+t) using hashing

const int p = 31;
const int m = 1e9 + 9;

vi rabin_karp(string const& s, string const& t) {
    int S = s.size(), T = t.size();

    vector<ll> p_pow(max(S,T), 0);
    p_pow[0] = 1;
    FOR(i,1,max(S,T)) p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(T+1,0);
    ll h_s = 0;
    F0R(i,T) h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    F0R(i,S) h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vi occurences;
    //check this
    for (int i = 0; i + S - 1 < T; i++){
        ll cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_po[i] % m){
            occurences.pb(i);
        }
    }

    return occurences;
}

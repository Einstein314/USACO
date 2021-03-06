const ll mod = 1e9 + 7;

ll mpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if (b&1) ans = ans*a % mod;
        b>>=1, a=a*a%mod;
    }
    return ans;
}

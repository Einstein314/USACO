//From cp-algorithms.com, Check: CF 1113F 
//https://cp-algorithms.com/combinatorics/binomial-coefficients.html

//Float implementation
int nCk (int n, int k){
    double res = 1;
    for (int i = 1; i <= k; i++){
        res *= (n - k + i)/i;
    }
    return (int) (res + 0.01);
}


//Pascal
const int maxn = 1e5;
int C[maxn+1][maxn+1];
C[0][0] = 1 ;
for (int n = 1; n <= maxn; n++){
  C[n][0] = 1, C[n][n] = 1;
  for (int k = 1; k < n; k++){
      C[n][k] = C[n-1][k] + C[n-1][k-1];
  }
}

//Precompute coefficients with inverse 
const ll MOD = 1e9 + 7;
const ll MXN = 1e6;
ll fact[MXN + 1], inv[MXN + 1], finv[MXN + 1];

ll bc(ll n, ll k){
	return ((fact[n] * finv[k] % MOD) % MOD * finv[n-k] % MOD) % MOD;
}

fact[0] = 1;
FOR(i, 1, MXN+1){
		fact[i] = fact[i-1] * i % MOD;
}
inv[1] = 1;
FOR(i, 2, MXN+1){
		inv[i] = (MOD - (MOD/i) * inv[MOD % i] % MOD) % MOD;
}
finv[0] = 1;
finv[1] = 1;
FOR(i, 2, MXN+1){
		finv[i] = finv[i-1] * inv[i] % MOD;
}

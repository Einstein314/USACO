//From cp-algorithms.com, Check: CF 1113F
//https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num

//With Euclidean Algorithm
int x,y;
int g = extended_euclidean(a, m, x, y);
if (g != -1) cout << "No sol";
else {
    x = (x % m + m) % m;
    cout << x;
}

//Can compute in O(log m) because a^(phi(m) - 1) == a^(-1) mod m

//Precomputation for prime modulus 
inv[1] = 1;
//Note: change the upper bound of for loop for large m
//Prove using m mod i = m - (m/i) * i; (Take mod m both sides) 
for (int i = 2; i < m; i++){
    inv[i] = (m - (m/i) * inv[m % i] % m) % m;
}


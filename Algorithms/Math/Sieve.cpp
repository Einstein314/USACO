//From Guide to Competitive Programming, Check: CF 1176D 

int sieve[2751000];
void initsieve(){
	FOR(i, 2, 2751000){
		if (sieve[i]) continue;
		for (int u = 2*i; u <= 2751000; u+=i) sieve[u] = 1;
	}
}

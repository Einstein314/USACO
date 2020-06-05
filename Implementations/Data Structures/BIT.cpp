//1-indexed
//Check: https://codeforces.com/contest/1354/problem/D

int BIT[MX], n;
//Use ll? modify for RMQ?

//sum[1,k]
int query(int k){
	int sum = 0;
	for(;k > 0; k -= k & -k) sum += BIT[k];
	return sum;
}

//arr[k] += x
void update(int k, int x){
	for(;k <= n; k += k&-k) BIT[k] += x;
}

//sum[l,r]
int rquery(int l, int r){
	return query(r) - query(l-1);
}

//finds (target)th largest value when used as multiset
//lower_bound on prefix sum array of BIT
int findInd(int target){
	int sum = 0, pos = 0, LOGN = 21;

	F0Rd(i,LOGN){
        //<= or <
		if (pos + (1<<i) <= n && sum + BIT[pos + (1<<i)] < target){
			pos += (1 << i);
			sum += BIT[pos];
		}
	}

	return pos + 1;

}

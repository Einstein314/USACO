//1-indexed
//Check: https://codeforces.com/contest/1354/problem/D
int BIT[MX];

//sum[1,k]
int query(int k){
    int sum = 0;
    for(;k >0;k -= k & -k) sum += BIT[k];
    return sum;
}

//arr[k] += x
void update(int k, int x){
    for(;k<= n; k+= k & -k) BIT[k] += x;
}

//sum[l,r]
int rquery(int l, int r){
    return BIT[r] - BIT[l-1];
}


//find ind(th) largest element using BIT as ordered set
int findind(int ind){
    int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi)/2;
        if (query(mid) >= ind){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

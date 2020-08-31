// cp-algo and cs handbook and benq
// tested on CSES 

const int MX = 2e5 + 5;
int n, a[MX], t[4 * MX];

int comb (int x, int y) {
    return min(x,y);
}

void pull(int p) {
    t[p] = comb(t[2*p],t[2*p+1]);
}

void build(int p = 1, int l = 0, int r = n-1) {
    if (l == r) {
        t[p] = a[l];
    }
    else {
        int m = l + (r - l) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        pull(p);
    }
}

// update t[i] = v
void update(int i, int v, int p = 1, int l = 0, int r = n-1) {
    if (l == r) {
        t[p] = v;
    }
    else {
        int m = l + (r - l) / 2;
        if (l <= i && i <= m) {
            update(i,v,2*p,l,m);
        }
        else{
            update(i,v,2*p+1,m+1,r);
        }
        pull(p);
    }
}

// query [x,y]
int query(int x, int y, int p = 1, int l = 0, int r = n-1) {
    if (l > y || x > r) return INF;
    if (x <= l && r <= y) return t[p];
    int m = l + (r - l) / 2;
    return comb(query(x,y,2*p,l,m),query(x,y,2*p+1,m+1,r));
}

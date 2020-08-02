class ELE{
    public:
        int ex1, ex2;
    ELE(int _ex1, int _ex2) : ex1(_ex1), ex2(_ex2) {}
    ELE() : ex1(0), ex2(0) {}
};

ELE operator+(const ELE L, const ELE R){
    //make sure ID is identity
    if (!L.ex1 && !L.ex2) return R;
    if (!R.ex1 && !R.ex2) return L;
    int ex3 = L.ex1 + R.ex1, ex4 = L.ex2 * R.ex2;
    return ELE(ex3, ex4);
}

//credit @Benq
template<class T> struct Seg{
    const T ID = T();
    T comb (T a, T b){
        return a + b;
    }
    int n; vector<T> seg;

    void init(int _n){
        n = _n;
        seg.assign(2*n, ID);
    }

    void pull(int p){
        seg[p] = comb(seg[2*p], seg[2*p+1]);
    }

    void upd(int p, T val){
        seg[p+=n] = val;
        for (p/=2;p;p/=2) pull(p);
    }

    T query(int l, int r){
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2){
            if (l & 1) ra = comb(ra, seg[l++]);
            if (r & 1) rb = comb(seg[--r], rb);
        }
        return comb(ra, rb);
    }
};

Seg<ELE> st;

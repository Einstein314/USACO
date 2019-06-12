//From bqi343, Check: CF 1182E 

ll n, f1, f2, f3, c, rec;

const ll mod = 1e9 + 7;
const ll tmpx = mod - 1;

template<class T> struct Mat {
    T** d;
    int a, b;
    
    Mat() { a = b = 0; }
    Mat(int _a, int _b) : a(_a), b(_b) {
        d = new T*[a];
        F0R(i,a) {
            d[i] = new T[b];
            F0R(j,b) d[i][j] = 0;
        }
    }
    Mat (const vector<vector<T>>& v) : Mat(sz(v),sz(v[0])) {
        F0R(i,a) F0R(j,b) d[i][j] = v[i][j];
    }

    operator vector<vector<T>> () {
        auto ret = vector<vector<T>>(a,vector<T>(b));
        F0R(i,a) F0R(j,b) ret[i][j] = d[i][j];
        return ret;
    }
    friend void pr(const Mat& m) {
        Mat M(m); pr(vector<vector<T>>(M));
    }
    
    Mat operator+(const Mat& m) {
        assert(a == m.a && b == m.b);
        Mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = d[i][j]+m.d[i][j];
        return r;
    }
    Mat operator-(const Mat& m) {
        assert(a == m.a && b == m.b);
        Mat r(a,b);
        F0R(i,a) F0R(j,b) r.d[i][j] = d[i][j]-m.d[i][j];
        return r;
    }
    Mat operator*(const Mat& m) {
        assert(b == m.a);
        Mat r(a,m.b);
        F0R(i,a) F0R(j,b) F0R(k,m.b) r.d[i][k] += d[i][j]*m.d[j][k];
        return r;
    }
    
    Mat& operator+=(const Mat& m) { return *this = (*this)+m; }
    Mat& operator-=(const Mat& m) { return *this = (*this)-m; }
    Mat& operator*=(const Mat& m) { return *this = (*this)*m; }

    friend Mat exp(Mat m, ll p) {
        Mat r(m.a,m.a); assert(m.a == m.b);
        F0R(i,m.a) r.d[i][i] = 1;
        for (; p; p /= 2, m *= m) if (p&1) r *= m;
        return r;
    }
};


int main(){
    Mat<ll> m1({{0,1,0},{0,0,1},{1,1,1}});
    Mat<ll> ta1({{1},{0},{0}});
    Mat<ll> ta2({{0},{1},{0}});
    Mat<ll> ta3({{0},{0},{1}});
    return 0;
}

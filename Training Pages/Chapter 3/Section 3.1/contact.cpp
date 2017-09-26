///*
//ID: konwoo.1
//PROG: contact
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
////#include "kimko_stdc++.h"
//
//using namespace std;
//
//typedef long long ll;
//typedef vector<int> vi;
//typedef pair<int, int> pii;
//
//#define FOR(i, a, b) for (int i=a; i<b; i++)
//#define F0R(i, a) for (int i=0; i<a; i++)
//#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
//#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
//
//#define mp make_pair
//#define pb push_back
//#define f first
//#define s second
//#define lb lower_bound
//#define ub upper_bound
//
//const int MOD = 1000000007;
//double PI = 4*atan(1);
//
//#define MAXBITS 12
//#define MAXSEQ (1<<(MAXBITS+1))
//
//typedef struct Seq Seq;
//struct Seq {
//    unsigned bits;
//    int count;
//};
//
//Seq seq[MAXSEQ];
//
///* increment the count for the n-bit sequence "bits" */
//void addseq(unsigned bits, int n)
//{
//    bits &= (1<<n)-1;
//    bits |= 1<<n;
//    assert(seq[bits].bits == bits);
//    seq[bits].count++;
//}
//
///* print the bit sequence, decoding the 1<<n stuff */
///* recurse to print the bits most significant bit first */
//void printbits(FILE *fout, unsigned bits)
//{
//    assert(bits >= 1);
//    if(bits == 1)	/* zero-bit sequence */
//        return;
//
//    printbits(fout, bits>>1);
//    fprintf(fout, "%d", bits&1);
//}
//
//int seqcmp(const void *va, const void *vb)
//{
//    Seq *a, *b;
//
//    a = (Seq*)va;
//    b = (Seq*)vb;
//
//    /* big counts first */
//    if(a->count < b->count)
//        return 1;
//    if(a->count > b->count)
//        return -1;
//
//    /* same count: small numbers first */
//    if(a->bits < b->bits)
//        return -1;
//    if(a->bits > b->bits)
//        return 1;
//
//    return 0;
//}
//
//int main(void)
//{
//    FILE *fin, *fout;
//    int i, a, b, n, nbit, c, j, k;
//    unsigned bit;
//    char *sep;
//
//    fin = fopen("contact.in", "r");
//    fout = fopen("contact.out", "w");
//    assert(fin != NULL && fout != NULL);
//
//    nbit = 0;
//    bit = 0;
//
//    for(i=0; i<=MAXBITS; i++)
//        for(j=0; j<(1<<i); j++)
//            seq[(1<<i) | j].bits = (1<<i) | j;
//
//    fscanf(fin, "%d %d %d", &a, &b, &n);
//
//    while((c = getc(fin)) != EOF) {
//        if(c != '0' && c != '1')
//            continue;
//
//        bit <<= 1;
//        if(c == '1')
//            bit |= 1;
//
//        if(nbit < b)
//            nbit++;
//
//        for(i=a; i<=nbit; i++)
//            addseq(bit, i);
//    }
//
//    qsort(seq, MAXSEQ, sizeof(Seq), seqcmp);
//
//    /* print top n frequencies for number of bits between a and b */
//    j = 0;
//    for(i=0; i<n && j < MAXSEQ; i++) {
//        if(seq[j].count == 0)
//            break;
//
//        c = seq[j].count;
//        fprintf(fout, "%d\n", c);
//
//        /* print all entries with frequency c */
//        sep = "";
//        for(k=0; seq[j].count == c; j++, k++) {
//            fprintf(fout, sep);
//            printbits(fout, seq[j].bits);
//            if(k%6 == 5)
//                sep = "\n";
//            else
//                sep = " ";
//        }
//        fprintf(fout, "\n");
//    }
//
//    exit(0);
//}

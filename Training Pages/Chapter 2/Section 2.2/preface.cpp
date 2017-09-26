///*
//ID: konwoo.1
//PROG: preface
//LANG: C++11
//*/
//
//#include "bits/stdc++.h"
//
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
//int N;
//const int MAX = 3501;
//int dpcheck[MAX], dparr[MAX][7];
//pair<string, int> sol[7];
//
//
//void dp(int x){
//        if (x - 1000 >= 0){
//            dparr[x][6]++;
//            sol[6].s++;
//            if (dpcheck[x-1000] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-1000][i];
//                    dparr[x][i]+=dparr[x-1000][i];
//                }
//            }
//            else{
//                dp(x - 1000);
//            }
//        }
//        else if (x - 900 >= 0){
//            dparr[x][6]++;
//            dparr[x][4]++;
//            sol[6].s++;
//            sol[4].s++;
//            if (dpcheck[x-900] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-900][i];
//                    dparr[x][i]+=dparr[x-900][i];
//                }
//            }
//            else{
//                dp(x-900);
//            }
//        }
//        else if (x - 500 >= 0){
//            dparr[x][5]++;
//            sol[5].s++;
//            if (dpcheck[x-500] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-500][i];
//                    dparr[x][i]+=dparr[x-500][i];
//                }
//            }
//            else{
//                dp(x - 500);
//            }
//        }
//        else if (x - 400 >= 0){
//            dparr[x][4]++;
//            dparr[x][5]++;
//            sol[4].s++;
//            sol[5].s++;
//            if (dpcheck[x-400] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-400][i];
//                    dparr[x][i]+=dparr[x-400][i];
//                }
//            }
//            else{
//                dp(x - 400);
//            }
//        }
//        else if (x - 100 >= 0){
//            dparr[x][4]++;
//            sol[4].s++;
//            if (dpcheck[x-100] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-100][i];
//                    dparr[x][i]+=dparr[x-100][i];
//                }
//            }
//            else{
//                dp(x - 100);
//            }
//        }
//        else if (x - 90 >= 0){
//            dparr[x][4]++;
//            dparr[x][2]++;
//            sol[4].s++;
//            sol[2].s++;
//            if (dpcheck[x-90] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-90][i];
//                    dparr[x][i]+=dparr[x-90][i];
//                }
//            }
//            else{
//                dp(x - 90);
//            }
//        }
//        else if (x - 50 >= 0){
//            dparr[x][3]++;
//            sol[3].s++;
//            if (dpcheck[x-50] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-50][i];
//                    dparr[x][i]+=dparr[x-50][i];
//                }
//            }
//            else{
//                dp(x - 50);
//            }
//        }
//        else if (x - 40 >= 0){
//            dparr[x][2]++;
//            dparr[x][3]++;
//            sol[2].s++;
//            sol[3].s++;
//            if (dpcheck[x-40] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-40][i];
//                    dparr[x][i]+=dparr[x-40][i];
//                }
//            }
//            else{
//                dp(x - 90);
//            };
//        }
//        else if (x - 10 >= 0){
//            dparr[x][2]++;
//            sol[2].s++;
//            if (dpcheck[x-10] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-10][i];
//                    dparr[x][i]+=dparr[x-10][i];
//                }
//            }
//            else{
//                dp(x - 10);
//            }
//        }
//        else if (x - 9 >= 0){
//            dparr[x][0]++;
//            dparr[x][2]++;
//            sol[0].s++;
//            sol[2].s++;
//            if (dpcheck[x-9] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-9][i];
//                    dparr[x][i]+=dparr[x-9][i];
//                }
//            }
//            else{
//                dp(x - 9);
//            }
//        }
//        else if (x - 5 >= 0){
//            dparr[x][1]++;
//            sol[1].s++;
//            if (dpcheck[x-5] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-5][i];
//                    dparr[x][i]+=dparr[x-5][i];
//                }
//            }
//            else{
//                dp(x - 5);
//            }
//        }
//        else if (x - 4 >= 0){
//            dparr[x][0]++;
//            dparr[x][1]++;
//            sol[0].s++;
//            sol[1].s++;
//            if (dpcheck[x-4] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-4][i];
//                    dparr[x][i]+=dparr[x-4][i];
//                }
//            }
//            else{
//                dp(x - 4);
//            }
//        }
//        else if (x - 1 >= 0){
//            dparr[x][0]++;
//            sol[0].s++;
//            if (dpcheck[x-1] == 1){
//                F0R(i, 7){
//                    sol[i].s += dparr[x-1][i];
//                    dparr[x][i]+=dparr[x-1][i];
//                }
//            }
//            else{
//                dp(x - 1);
//            }
//        }
//        dpcheck[x] = 1;
//}
//
//
//int main() {
//    ifstream fin("preface.in");
//    ofstream fout("preface.out");
//    fin >> N;
//
//    string tempo[7] = {"I", "V", "X", "L", "C", "D", "M"};
//    F0R(i , 7){
//        sol[i].f = tempo[i];
//    }
//
//    FOR(i, 1, N+1){
//        dp(i);
//    }
//
//    F0R(i, 7){
//        if (sol[i].s != 0){
//            fout << sol[i]. f << " " << sol[i].s << "\n";
//        }
//    }
//    return 0;
//}
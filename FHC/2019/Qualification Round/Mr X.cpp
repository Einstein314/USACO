#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define FOR(i,a,b) for (int i = a; i < b; i++)
#define F0R(i,a) for (int i = 0; i < a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i>=0; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define f first
#define s second 
#define newl '\n'
#define mp make_pair



int T;
string E, E1, E0;


string inftopos(string str){
	string ans = "";
	stack<char> st;
	int n = str.length();
	F0R(j,n){
		if (str[j] == '(') st.push('(');
		else if (str[j] == ')'){
			while (!st.empty() && st.top() != '('){
				char c = st.top();
				st.pop();
				ans += c;
			}
			if (!st.empty() && st.top() == '('){
				st.pop();
			}
		}
		else if (str[j] == '1' || str[j] == '0') ans += str[j];
		else{
			st.push(str[j]);
		}
	}
	return ans;
}

int cval(string x){
	stack<int> st;
	F0R(j, sz(x)){
		if (x[j] == '0' || x[j] == '1') st.push(x[j] - '0'); 
		else{
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			if (x[j] == '&'){
				val1 &= val2; 
				st.push(val1);
			}
			else if (x[j] == '|'){
				val1 |= val2;
				st.push(val1);
			}
			else if (x[j] == '^'){
				val1 ^= val2;
				st.push(val1);
			}
		}
	}
	return st.top();
}



int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

	ifstream cin("/Users/konwoo/input.txt");
	ofstream cout("/Users/konwoo/output.txt");


	cin >> T;
	F0R(i,T){
		cin >> E;
		int len = E.length();
		E1 = E;
		E0 = E;
		F0R(j,len){
			if (E[j] == 'x'){
				E1[j] = '1';
				E0[j] = '0';
			}
			else if (E[j] == 'X'){
				E1[j] = '0';
				E0[j] = '1';
			}
			else{
				E1[j] = E[j];
				E0[j] = E[j];
			}
		}
		string newst1 = inftopos(E1);
		string newst0 = inftopos(E0);
		cout << "Case #" << i+1 << ": ";
		if (cval(newst1) == cval(newst0)){
			cout << 0;
		}
		else{
			cout << 1;
		}
		if (i != T-1) cout << newl;
	}













    return 0;
}

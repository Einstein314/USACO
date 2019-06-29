//From https://cp-algorithms.com/data_structures/disjoint_set_union.html, Check: CSES Building Roads

const int MX = 2e5 + 1;
int parent[MX], sz[MX];

void make_set(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find_set(int v){
	if (v == parent[v]) return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
	a = find_set(a), b = find_set(b);
	if (a != b){
		if (sz[a] < sz[b]) swap(a,b);
		parent[b] = a;
		sz[a] += sz[b];
	}
}
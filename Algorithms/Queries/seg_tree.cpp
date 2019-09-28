struct Tree{
	Tree* pl, pr;
	int nl = 0, nr = 0, val = 0;

	void updateVal(){
		val = pl->val + pr->val;
	}

	void Tree(int l, int r, int A[]){
		nl = l; nr = r;
		if (nl  + 1 == nr){
			val = A[nl];
			return;
		}
		pl = new Tree(l, (l + r) >> 1, A);
		pr = new Tree((l + r) >> 1, r, A);
		updateVal();
	}

	void modify(int p, int x){
		if (nr <= p || nl > p) return;
		if (nl + 1 == nr){
			A[nl] = x;
		}
		pl->modify(p,x);
		pr->modify(p,x);
		updateVal();
	}

	int query(int l, int r){
		//Check which value you return;
		if (nr <= l || nl > r) return 0;
		if (l <= nl && r >= nr) return val;
		return pl->query(l,r) + pr->query(l,r);
	}
};

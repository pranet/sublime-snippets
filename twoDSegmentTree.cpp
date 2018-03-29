<snippet>
	<content><![CDATA[
namespace SegmentTree {
	typedef struct Node* pnode;
	pnode null;
	struct Node {
		int cnt;
		pnode l;
		pnode r;
	};
	void seed() {
		null = new Node();
		null->cnt = 0;
		null->l = null;
		null->r = null;
	}
	void pointUpdate(pnode &u, int x, int v, int l = 1, int r = 1e9) {
		if (u == null) {
			u = new Node({0, null, null});
		}
		u->cnt += v;
		if (l != r) {
			int m = (l + r) / 2;
			if (x <= m) {
				pointUpdate(u->l, x, v, l, m);				
			}
			else {
				pointUpdate(u->r, x, v, m + 1, r);				
			}
		}
	}
	int query(pnode &u, int x, int y, int l = 1, int r = 1e9) {
		if (u == null or x > r or y < l) {
			return 0;
		}
		if (x <= l and r <= y) {
			return u->cnt;
		}
		int m = (l + r) / 2;
		return query(u->l, x, y, l, m) + query(u->r, x, y, m + 1, r);
	}
};
namespace SegmentTreeOuter {
	typedef struct Node* pnode;
	pnode null;
	struct Node {
		SegmentTree::pnode inner;
		pnode l;
		pnode r;
	};
	void seed() {
		SegmentTree::seed();
		null = new Node();
		null->inner = SegmentTree::null;
		null->l = null;
		null->r = null;
	}
	void pointUpdate(pnode &u, int x, int y, int v, int l = 1, int r = 1e9) {
		if (u == null) {
			u = new Node({SegmentTree::null, null, null});			
		}
		SegmentTree::pointUpdate(u->inner, y, v);
		if (l != r) {
			int m = (l + r) / 2;
			if (x <= m) {
				pointUpdate(u->l, x, y, v, l, m);            
			}
			else {
				pointUpdate(u->r, x, y, v, m + 1, r);                
			}
		}
	}
	int query(pnode &u, int x1, int x2, int y1, int y2, int l = 1, int r = 1e9) {
		if (u == null or x1 > r or x2 < l) {
			return 0;
		}
		if (x1 <= l and r <= x2) {
			return SegmentTree::query(u->inner, y1, y2);
		}
		int m = (l + r) / 2;
		return query(u->l, x1, x2, y1, y2, l, m) + query(u->r, x1, x2, y1, y2, m + 1, r);
	}
};
]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<!-- <tabTrigger>hello</tabTrigger> -->
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<!-- <scope>source.python</scope> -->
</snippet>

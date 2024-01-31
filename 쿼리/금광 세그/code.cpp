struct rng {
	int le = 0, all = 0, ri = 0, tot = 0;
};
const int Z = 131072;
rng tree[Z * 2];

rng merge(rng& r1, rng& r2) {
	rng ret;
	ret.le = max(r1.le, r1.tot + r2.le);
	ret.ri = max(r2.ri, r2.tot + r1.ri);
	ret.tot = r1.tot + r2.tot;
	ret.all = max(max(r1.all, r2.all), r1.ri + r2.le);
	return ret;
}
void renew(int a, int now, int s, int e, int k) {
	if (s == e) {
		tree[a] = { k, k, k, k };
		return;
	}
	int m = (s + e) / 2;

	if (a <= m) renew(a, now * 2, s, m, k);
	else renew(a, now * 2 + 1, m + 1, e, k);
	tree[now] = merge(tree[now * 2], tree[now * 2 + 1]);
}
rng sum(int a, int b, int now, int s, int e) {
	if (a <= s && e <= b) return tree[now];
	int m = (s + e) / 2;

	rng ret;
	if (a <= m) ret = sum(a, b, now * 2, s, m);
	if (m < b) {
		rng tmp = sum(a, b, now * 2 + 1, m + 1, e);
		if (a <= m) ret = merge(ret, tmp);
		else ret = tmp;
	}
	return ret;
}

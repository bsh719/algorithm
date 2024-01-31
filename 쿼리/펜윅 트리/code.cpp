int sum(int k) {
	int ret = 0;
	while (k >= 1) {
		ret += tree[k];
		k -= k & -k;
	}
	return ret;
}
void add(int k, int x) {
	while (k <= n) {
		tree[k] += x;
		k += k & -k;
	}
}

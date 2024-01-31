int sum(int a, int b) {
	int ret = 0;

	while (a <= b) {
		if (a & 1) ret += tree[a++];
		if (b % 2 == 0) ret += tree[b--];

		a /= 2; b /= 2;
	}
	return ret;
}

void add(int k, int x) {
	tree[k] += x;
	for (; k >= 1; k /= 2)
		tree[k] = tree[k * 2] + tree[k * 2 + 1];
}

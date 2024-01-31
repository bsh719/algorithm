const int S = 1048576; // h -> 20
ll tree[S * 2], lazy[S * 2];

void renew(int i, int h) {
	tree[i * 2] += lazy[i] << (h - 1);
	tree[i * 2 + 1] += lazy[i] << (h - 1);
	lazy[i * 2] += lazy[i];
	lazy[i * 2 + 1] += lazy[i];
	lazy[i] = 0;
}
void push(int a, int b, int i, int h, int v) {
	if (a <= (i << h) && ((i + 1) << h) - 1 <= b) {
		tree[i] += (ll)v << h;
		lazy[i] += v;
		return;
	}
	renew(i, h);
	int m = ((i * 2 + 1) << (h - 1)) - 1;

	if (a <= m) push(a, b, i * 2, h - 1, v);
	if (m < b) push(a, b, i * 2 + 1, h - 1, v);
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
}
ll sum(int a, int b, int i, int h) {
	if (a <= (i << h) && ((i + 1) << h) - 1 <= b)
		return tree[i];

	renew(i, h);
	int m = ((i * 2 + 1) << (h - 1)) - 1;
	ll ret = 0;

	if (a <= m) ret += sum(a, b, i * 2, h - 1);
	if (m < b) ret += sum(a, b, i * 2 + 1, h - 1);
	return ret;
}

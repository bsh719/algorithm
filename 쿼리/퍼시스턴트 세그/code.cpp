int root[100001];
int PST[2262144], lidx[2262144], ridx[2262144];
int last_idx = 262144;

void add(int x, int now, int pre, int le, int ri) {
	if (le == ri) {
		PST[now] = PST[pre] + 1;
		return;
	}
	int m = (le + ri) / 2;

	if (x <= m) {
		lidx[now] = ++last_idx;
		ridx[now] = ridx[pre];
		add(x, lidx[now], lidx[pre], le, m);
	}
	else {
		lidx[now] = lidx[pre];
		ridx[now] = ++last_idx;
		add(x, ridx[now], ridx[pre], m + 1, ri);
	}
	PST[now] = PST[lidx[now]] + PST[ridx[now]];
}

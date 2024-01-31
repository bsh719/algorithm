vector<pair<int, int>> adj[200001];
int depth[200001];
int par[200001][18], best[200001][18];

void make(int a, int dfsn) {
	depth[a] = dfsn;
	int sz = adj[a].size();

	for (int i = 0; i < sz; i++) {
		int b = adj[a][i].first, w = adj[a][i].second;
		if (depth[b] != 0) continue;

		par[b][0] = a;
		best[b][0] = w;
		int k = 1;

		while ((1 << k) <= dfsn) {
			par[b][k] = par[par[b][k - 1]][k - 1];
			best[b][k] = max(best[b][k - 1], best[par[b][k - 1]][k - 1]);
			k++;
		}
		make(b, dfsn + 1);
	}
}

int LCA(int a, int b) {
	if (a == b) return 0;
	if (par[a][0] == par[b][0])
		return max(best[a][0], best[b][0]);

	int k = 17;

	while (1) {
		if (par[a][k] == par[b][k]) k--;
		else {
			int tmp = max(best[a][k], best[b][k]);
			tmp = max(tmp, LCA(par[a][k], par[b][k]));
			return tmp;
		}
	}
}

int main() {
	while () {
		int d = depth[a] - depth[b];
		if (d < 0) {
			d = -d;
			int t = a; a = b; b = t;
		}
		int k = 0;
		int tmp = 0;

		while (d > 0) {
			if (d & 1) {
				tmp = max(tmp, best[a][k]);
				a = par[a][k];
			}
			k++; d >>= 1;
		}
		tmp = max(tmp, LCA(a, b));
	}
}

int S, E;
const int Z = 502;
vector<int> link[Z];
int INF = 1e9;
int c[Z][Z], f[Z][Z];
int lev[Z], last[Z];

bool bfs() {
	fill_n(lev, Z, -1);
	lev[S] = 0;
	queue<int> q; q.push(S);

	while (!q.empty()) {
		int a = q.front(); q.pop();

		for (int b : link[a]) {
			if (lev[b] == -1 && c[a][b] > f[a][b]) {
				q.push(b);
				lev[b] = lev[a] + 1;
			}
		}
	}
	return lev[E] != -1;
}

int dfs(int now, int end, int flow) {
	if (now == end) return flow;

	for (int i = last[now]; i < link[now].size(); i++) {
		last[now] = i;
		int nex = link[now][i];

		if (lev[nex] == lev[now] + 1 && c[now][nex] > f[now][nex]) {
			int t = dfs(nex, end, min(flow, c[now][nex] - f[now][nex]));

			if (t > 0) {
				f[now][nex] += t;
				f[nex][now] -= t;
				return t;
			}
		}
	}
	return 0;
}

int main() {
	int tot = 0;
	while (bfs()) {
		fill_n(last, Z, 0);

		while (1) {
			int t = dfs(S, E, INF);
			if (t == 0) break;
			tot += t;
		}
	}
	cout << tot << '\n';
}

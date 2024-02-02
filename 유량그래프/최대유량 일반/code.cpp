int c[302][302], f[302][302];
vector<int> adj[302];
int pre[302];

int main() {
	int total = 0;
	while (1) {
		fill_n(pre, 302, -1);
		queue<int> q; q.push(S); pre[S] = -10;

		while (!q.empty() && pre[E] == -1) {
			int a = q.front(); q.pop();

			for (int b : adj[a]) {
				if (c[a][b] > f[a][b] && pre[b] == -1) {
					pre[b] = a;
					q.push(b);
					if (i == E) break;
				}
			}
		}
		if (pre[E] == -1) break;
		int fl = 1000000;

		for (int i = E; i != S; i = pre[i])
			fl = min(fl, c[pre[i]][i] - f[pre[i]][i]);

		for (int i = E; i != S; i = pre[i]) {
			f[pre[i]][i] += fl;
			f[i][pre[i]] -= fl;
		}
		total += fl;
	}
}

// 일반 (간선구조체로도 가능, 디닉으로는 불가능)
int S, E;
const int Z = 602;
vector<int> link[Z];
int pre[Z], dist[Z];
bool inQ[Z];
int c[Z][Z], f[Z][Z], d[Z][Z];

int main() {
	int val = 0, tot = 0;
	while (1) {
		fill_n(dist, Z, 1000000000);

		queue<int> q; q.push(S);
		inQ[S] = 1; dist[S] = 0;

		// SPFA
		while (!q.empty()) {
			int a = q.front(); q.pop();
			inQ[a] = 0;

			for (int b : link[a]) {
				if (c[a][b] > f[a][b] && dist[b] > dist[a] + d[a][b]) {
					dist[b] = dist[a] + d[a][b];
					pre[b] = a;

					if (!inQ[b]) {
						inQ[b] = 1;
						q.push(b);
					}
				}
			}
		}
		if (pre[E] == -1) break;
		if (dist[E] >= 0) break; // 최소비용 우선일때만
		val -= dist[E];

		int fl = 1000000;
		for (int i = E; i != S; i = pre[i])
			fl = min(fl, c[pre[i]][i] - f[pre[i]][i]);

		for (int i = E; i != S; i = pre[i]) {
			f[pre[i]][i] += fl;
			f[i][pre[i]] -= fl;
		}
		tot += fl;
	}
}

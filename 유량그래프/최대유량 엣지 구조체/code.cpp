struct Edge {
	int to, c = 0, f = 0;
	Edge* rev;

	int spare() {
		return c - f;
	}
	void addflow(int flow) {
		f += flow;
		rev->f -= flow;
	}
};

vector<Edge*> graph[20000];
Edge* path[20000];
int pre[20000];
int visited[20000];

int main() {
	int total = 0;
	while (1) {
		fill_n(pre, 20000, -1);
		queue<int> q; q.push(S);

		while (!q.empty() && pre[E] == -1) {
			int now = q.front(); q.pop();

			for (auto e : graph[now]) {
				int v = e->to;
				if (pre[v] == -1 && e->spare()) {
					q.push(v);
					pre[v] = now;
					path[v] = e;
					if (v == E) break;
				}
			}
		}
		if (pre[E] == -1) break;
		int fl = 1000000;

		for (int i = E; i != S; i = pre[i])
			fl = min(fl, path[i]->spare());

		for (int i = E; i != S; i = pre[i])
			path[i]->addflow(fl);

		total += fl;
	}
}

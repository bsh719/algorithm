pair<int, int> rng[100001];
bool visit[100001];

int make_range(int a, int s) {
	visit[a] = 1;
	rng[a].first = s;
	int e = s;

	for (int b : link[a]) {
		if (visit[b]) continue;
		e = make_range(b, e + 1);
	}
	rng[a].second = e;
	return e;
}

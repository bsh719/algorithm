typedef pair<int, int> pi;
const int Z = 500001;
const int S = 524288;
vector<int> link[M];

bool visit[Z], visit2[Z];
int heavy_child[Z];

int find_heavy(int a) {
	visit[a] = 1;
	int C = 0, ans = 0, tot = 1;

	for (int b : link[a]) {
		if (visit[b]) continue;
		int t = find_heavy(b);
		tot += t;

		if (C < t) {
			C = t;
			ans = b;
		}
	}
	heavy_child[a] = ans;
	return tot;
}
int idx = S, cnt = 0;
pi pos[Z], parent_pos[S];

void make_tree(int a) {
	visit2[a] = 1;
	pos[a] = { idx, cnt };
	cnt++;

	if (heavy_child[a] != 0) {
		make_tree(heavy_child[a]);

		for (int b : link[a]) {
			if (!visit2[b]) {
				parent_pos[idx - S] = pos[a];
				make_tree(b);
			}
		}
	}
	else {
		idx += cnt;
		cnt = 0;
	}
}
